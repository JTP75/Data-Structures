#include <iostream>
#include "FindPalindrome.cpp"

using namespace std;

int main()
{
	FindPalindrome f;
	string newString("a");
	cout << "\n******* Project 1 Main *********\n\n";
	for (int i=0; i<3; i++) {
		if(f.add(newString)) {
			cout << "Added the string :" << newString << endl;
		} else {
			cout << "ERROR: for some reason unable to add the string: << newString " << endl;
		}
		newString += "a";
	}
	cout << "\nNumber of sentence palindromes are:  " << f.number() << endl;
	cout << "\nThe sentence palindromes are:" << endl;
	vector<vector<string>> vectorList = f.toVector();
	for (int i=0; i<vectorList.size(); i++) {
		for (int j=0; j<vectorList[i].size(); j++) {
			cout << vectorList[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "\n******* Project 1 Main *********\n\n";
	return 0;
}

