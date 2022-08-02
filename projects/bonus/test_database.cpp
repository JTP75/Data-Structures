#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "Database.hpp"
#include <math.h>


struct Entry {
    std::string title;
    std::string author;
    int pubYear;

    inline bool operator==(Entry rhs) const {
        return
            this->title == rhs.title &&
            this->author == rhs.author &&
            this->pubYear == rhs.pubYear;
    };
};


TEST_CASE("Tests for double-stack list","[list]") {
    List<int> lst;

    REQUIRE(lst.getLength() == 0);
    REQUIRE(lst.isEmpty());

    REQUIRE(lst.insert(0,36));
    REQUIRE(lst.insert(1,49));
    REQUIRE(lst.insert(0,25));
    
    REQUIRE(lst.getLength() == 3);
    REQUIRE_FALSE(lst.isEmpty());
    for(int i=0; i < 3; i++)
        REQUIRE(lst.getEntry(i) == (i+5)*(i+5));

    REQUIRE_FALSE(lst.insert(-1,0));
    REQUIRE_FALSE(lst.insert(4,0));
    REQUIRE(lst.insert(3,0));

    REQUIRE(lst.insert(2,-555));
    lst.setEntry(4,64);
    REQUIRE(lst.remove(2));

    for(int i=0; i < 4; i++)
        REQUIRE(lst.getEntry(i) == (i+5)*(i+5));

    REQUIRE_FALSE(lst.remove(4));
    REQUIRE(lst.remove(3));
    REQUIRE(lst.remove(0));

    for(int i=0; i < 2; i++)
        REQUIRE(lst.getEntry(i) == (i+6)*(i+6));
    
    lst.clear();
    REQUIRE(lst.isEmpty());
}

TEST_CASE("Test Construction", "[construction]") {
    Database<std::string> testdb;

    REQUIRE(testdb.isEmpty());
}


TEST_CASE("Test Add", "[add]") {
    Database<std::string> testdb;
    std::string e1 = "entry";

    testdb.add("key1", "key2", e1);
    REQUIRE(!testdb.isEmpty());
    REQUIRE(testdb.contains("key1"));
    REQUIRE(testdb.contains("key2"));
}


TEST_CASE("Test Duplicate Add", "[duplicate add]") {
    Database<std::string> testdb;
    std::string e1 = "entry";
    
    testdb.add("key1", "key2", e1);
    REQUIRE(!testdb.add("key1", "key2", e1));
}


TEST_CASE("Test Retrieve", "[retrieve]") {
    Database<std::string> testdb;
    std::string e1 = "entry";

    testdb.add("key1", "key2", e1);
    
    REQUIRE(testdb.getValue("key1") == e1);
    REQUIRE(testdb.getValue("key2") == e1);
}


TEST_CASE("Test Add 2", "[add 2]") {
    Database<std::string> testdb;
    std::string e1 = "entry1";
    std::string e2 = "entry2";
    
    testdb.add("key1a", "key1b", e1);
    testdb.add("key2a", "key2b", e2);

    REQUIRE(testdb.getNumberOfEntries() == 2);

    REQUIRE(testdb.getValue("key1a") == e1);
    REQUIRE(testdb.getValue("key1b") == e1);
    REQUIRE(testdb.getValue("key2a") == e2);
    REQUIRE(testdb.getValue("key2b") == e2);
}


TEST_CASE("Test Remove", "[remove]") {
    Database<std::string> testdb;
    std::string e1 = "entry";

    testdb.add("key1", "key2", e1);
    
    testdb.remove("key1");
    REQUIRE(!testdb.contains("key1"));
    REQUIRE(!testdb.contains("key2"));

    testdb.add("key1", "key2", e1);
    
    testdb.remove("key2");
    REQUIRE(!testdb.contains("key1"));
    REQUIRE(!testdb.contains("key2"));

    REQUIRE(testdb.isEmpty());
}


TEST_CASE("Test Copy Construct", "[copy]") {
    Database<std::string> testdb;
    std::string e1 = "entry";

    testdb.add("key1", "key2", e1);

    Database<std::string> testdb_copy(testdb);

    REQUIRE(testdb_copy.getValue("key1") == e1);
    REQUIRE(testdb_copy.getValue("key2") == e1); 
}


TEST_CASE("Test Copy Assign", "[copy assign]") {
    Database<std::string> testdb;
    std::string e1 = "entry";

    testdb.add("key1", "key2", e1);

    Database<std::string> testdb_copy;

    testdb_copy = testdb;

    REQUIRE(testdb_copy.getValue("key1") == e1);
    REQUIRE(testdb_copy.getValue("key2") == e1); 
}


TEST_CASE("Test Entry Types", "[entry type]") {
    Database<Entry> testdb;

    Entry e1;
    std::string isbn1 = "000-0-00-000000-1";
    std::string catalog_id1 = "0000001";
    e1.title = "The Winds of Winter";
    e1.author = "George R. R. Martin";
    e1.pubYear = 2031;

    testdb.add(isbn1, catalog_id1, e1);

    Entry e2;

    std::string isbn2 = "000-0-00-000000-2";
    std::string catalog_id2 = "0000002";
    e2.title = "A Dream of Spring";
    e2.author = "George R. R. Martin";
    e2.pubYear = 2032;

    testdb.add(isbn2, catalog_id2, e2);
    Entry CID1, ISBN1, CID2, ISBN2;

    REQUIRE(testdb.getNumberOfEntries() == 2);
    REQUIRE(testdb.getValue(catalog_id1) == e1);
    REQUIRE(testdb.getValue(isbn1) == e1);
    REQUIRE(testdb.getValue(catalog_id2) == e2);
    REQUIRE(testdb.getValue(isbn2) == e2);

}

TEST_CASE("Test large database", "[size test]") {
    Database<uint> absval;
    uint nvals = 10;

    for(uint i = 1; i <= nvals; i++){
        std::string pos = std::to_string(i);
        std::string neg = "-" + std::to_string(i);
        absval.add(pos,neg,i);
    }

    REQUIRE(absval.getNumberOfEntries() == nvals);

    REQUIRE(absval.getValue("5") == 5);
    REQUIRE(absval.getValue("-2") == 2);
    REQUIRE(absval.getValue("-10") == 10);
    REQUIRE(absval.getValue("4") == 4);

    REQUIRE(absval.remove("-9"));
    REQUIRE(absval.remove("2"));
}

