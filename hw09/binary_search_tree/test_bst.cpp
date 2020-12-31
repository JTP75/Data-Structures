#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

#include "binary_search_tree.h"

typedef BinarySearchTree<int, int> TreeType;

void error(const char* msg, int lineno)
{
    cout << "FAILED: (Line " << lineno << ") " << msg << endl;
}

void test_creation()
{
    TreeType bst1;

    if (!bst1.isEmpty())
        error("TreeType should be empty here", __LINE__);
    bst1.insert(10, 10);
    if (bst1.isEmpty())
        error("TreeType should not be empty here", __LINE__);
}

void test_insert_retrieve_delete()
{
    TreeType bst1;

    bst1.insert(10, 10);
    bst1.insert(5, 5);
    bst1.insert(15, 15);
    bst1.insert(12, 12);
    bst1.insert(18, 18);

    if (bst1.insert(12, 12))
        error("TreeType duplicate key should fail", __LINE__);

    int item;
    if (!bst1.retrieve(18, item))
        error("TreeType retrieve failed", __LINE__);
    if (!bst1.retrieve(12, item))
        error("TreeType retrieve failed", __LINE__);
    if (!bst1.retrieve(15, item))
        error("TreeType retrieve failed", __LINE__);
    if (!bst1.retrieve(5, item))
        error("TreeType retrieve failed", __LINE__);
    if (!bst1.retrieve(10, item))
        error("TreeType retrieve failed", __LINE__);

    bst1.remove(12);
    if (bst1.retrieve(12, item))
        error("TreeType retrieve should have failed", __LINE__);
    bst1.remove(18);
    if (bst1.retrieve(18, item))
        error("TreeType retrieve should have failed", __LINE__);
    bst1.remove(5);
    if (bst1.retrieve(5, item))
        error("TreeType retrieve should have failed", __LINE__);
    bst1.remove(10);
    if (bst1.retrieve(10, item))
        error("TreeType retrieve should have failed", __LINE__);
    bst1.remove(15);
    if (bst1.retrieve(15, item))
        error("TreeType retrieve should have failed", __LINE__);

    if (!bst1.isEmpty())
        error("TreeType should be empty here", __LINE__);
}

TreeType dummy(TreeType test)
{
    TreeType temp = test;
    return temp;
}

void test_copy_assign()
{
    TreeType bst1;

    bst1.insert(50, 50);
    bst1.insert(0, 0);
    bst1.insert(100, 100);
    bst1.insert(25, 25);
    bst1.insert(75, 75);

    TreeType bst2;

    bst2 = dummy(bst1);

    if (bst2.isEmpty())
        error("TreeType should not be empty here", __LINE__);

    int item;
    if (!bst2.retrieve(100, item))
        error("TreeType retrieve failed", __LINE__);
    if (!bst2.retrieve(75, item))
        error("TreeType retrieve failed", __LINE__);
    if (!bst2.retrieve(50, item))
        error("TreeType retrieve failed", __LINE__);
    if (!bst2.retrieve(25, item))
        error("TreeType retrieve failed", __LINE__);
    if (bst2.retrieve(51, item))
        error("TreeType retrieve should have failed", __LINE__);
}

int main()
{

    test_creation();
    test_insert_retrieve_delete();
    test_copy_assign();

    return EXIT_SUCCESS;
}
