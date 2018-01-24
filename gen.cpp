
#include <iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<cctype>
#include "BinarySearchTree.h"


using namespace std;

int main(int argc, char *argv[]) {

	ifstream inf;

	//command line prompt
	inf.open(argv[1]);

	if (inf.fail()) {
		cout << "file failed to open" << endl;
	}

	//read in words from file, modify cstring
	char word[30];
	int length = 0;
	char temp;
	int line_number = 1;

	BinarySearchTree<char*> bst(NULL);
	
	//read in words from file
	//for each word, parse and insert into BST
	while (!inf.eof()) {
		if (temp == '\n') {
			line_number++;
		}
		inf.get(temp); 

		if (isalpha(temp)) {
			while (isalpha(temp)) {
				if (isupper(temp)) {
					temp = temp + 32;
				}
				word[length++] = temp;
				inf.get(temp);

			}
			word[length] = '\0';
			length = 0;
			char* test = new char[30];
			strcpy(test, word);
			bst.insert(test, line_number);
		}
	}
	
	//print results of tree
	bst.printTree();



	return 0;
}

