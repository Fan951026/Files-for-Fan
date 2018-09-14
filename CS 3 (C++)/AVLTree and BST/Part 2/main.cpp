#include <string>
#include <iostream>
#include "how4_a01972388.h"
#include "BSTree.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <locale>   
using namespace std;

int main(){
	ifstream b;
	AvlTree T;
	b.open("hw4_input.txt");
	string input;
	if (!b.is_open()){
		cout << "file not open!" << endl;
	}

	while (b >> input)
	{
		if (input[0] == 'i'){

			b >> input;

			T.Insert(input);

		}
		else if (input[0] == 'r'){

			b >> input;

			T.Delete(input);
		}
		else {
			cout << "error" << endl;
		}
	}




	cout << "Avltree hw4_input.txt: " << endl;
	cout << T.Traverse() << endl;
	cout << T.Traverse1() << endl;;
	cout << "The word in the root is: " << T.GetRoot() << endl;
	cout << "The height of the tree is: " << T.Height() << endl;
	cout << "The number of nodes in the tree is: " << T.Size() << endl;
	cout << "The number of the nodes with two children is: " << T.CountTwoChildren() << endl;
	cout << "The number of the nodes with one child is:" << T.CountOneChild() << endl;
	cout << "The number of leaf nodes is:" << T.CountLeaves() << endl;
	b.close();
	T.Print();




	ifstream dictionary("dictionary.txt");
	AvlTree dictTree;
	vector<string> dic;
	if (!dictionary.is_open()){
		cout << "file not open!" << endl;
	}

	while (dictionary >> input)
	{
		dic.push_back(input);
	}
	random_shuffle(dic.begin(), dic.end());
	for (int i = 0; i < dic.size(); ++i){
		dictTree.Insert(dic.at(i));
	}

	cout << "AVLtree Height of dictionary: " << dictTree.Height() << endl;
	cout << "AVLtree Size of dictionary: " << dictTree.Size() << endl;
	dictionary.close();





	ifstream app;
	app.open("letter.txt");
	cout << "letter.txt: " << endl;
	string bpp;
	while (app >> bpp){
		for (int i = 0; i < bpp.size(); ++i){


			bpp[i] = tolower(bpp[i]);

		}

		if (dictTree.Find(bpp) == false){
			cout << "AVLtree: " << bpp << endl;
		}

	}

	app.close();












	BSTree tree;
	string secinput;
    ifstream s;
    s.open("hw4_input.txt");
	if (!s.is_open()){
		cout << "file not open!" << endl;
	}

	while (s >> secinput)
	{
		if (secinput[0] == 'i'){

			s>> secinput;

			tree.Insert(secinput);

		}
		else if (secinput[0] == 'r'){

			s >> secinput;

			tree.Delete(secinput);
		}
		else {
			cout << "error" << endl;
		}
	}
	tree.Print();



	cout << "BSTree hw4_input.txt: " << endl;
	cout << tree.Traverse() << endl;
	cout << tree.Traverse1() << endl;;
	cout << "The word in the root is: " << tree.GetRoot() << endl;
	cout << "The height of the tree is: " << tree.Height() << endl;
	cout << "The number of nodes in the tree is: " << tree.Size() << endl;
	cout << "The number of the nodes with two children is: " << tree.CountTwoChildren() << endl;
	cout << "The number of the nodes with one child is:" << tree.CountOneChild() << endl;
	cout << "The number of leaf nodes is:" << tree.CountLeaves() << endl;
	s.close();


	ifstream dictionary1("dictionary.txt");
	BSTree dictTree1;
	vector<string> dic1;
	if (!dictionary1.is_open()){
		cout << "file not open!" << endl;
	}

	while (dictionary1 >> secinput)
	{
		dic1.push_back(secinput);
	}
	random_shuffle(dic1.begin(), dic1.end());
	for (int i = 0; i < dic1.size(); ++i){
		dictTree1.Insert(dic1.at(i));
	}

	cout << "BSTree Height of dictionary: " << dictTree1.Height() << endl;
	cout << "BSTree Size of dictionary: " << dictTree1.Size() << endl;
	dictionary1.close();
















	int numBST = 0, numAVL = 0;

	ifstream a;
	a.open("letter.txt");
	
	string qwe;
	while (a >> qwe){
		for (int i = 0; i < qwe.size(); ++i){


			qwe[i] = tolower(qwe[i]);

		}


		if (dictTree1.Find(qwe) == false){

			cout <<"BSTree: "<< qwe << endl;
		}
		else{
			numBST += dictTree1.FindComparisons(qwe);
		}


	}




	a.close();

	

	cout << "BST root is: " << dictTree1.GetRoot() << " |VS|  AVL root is: " << dictTree.GetRoot() << endl;
	cout << "BST height is: " << dictTree1.Height() << " |VS|  AVL height is: " << dictTree.Height() << endl;
	cout << "BST size is: " << dictTree1.Size() << " |VS|  AVL size is: " << dictTree.Size() << endl;
	cout << "BST two children is: " << dictTree1.CountTwoChildren() << " |VS|  AVL two children is:  " << dictTree.CountTwoChildren() << endl;
	cout << "BST one child is:" << dictTree1.CountOneChild() << " |VS|  AVL one children is:  " << dictTree.CountOneChild() << endl;
	cout << "BST leaf nodes is:" << dictTree1.CountLeaves() << " |VS|  AVL leaf nodes is:  " << dictTree.CountLeaves() << endl;
	
	

	ifstream e;
	e.open("letter.txt");
	while (e >> qwe){
		for (int i = 0; i < qwe.size(); ++i){


			qwe[i] = tolower(qwe[i]);

		}


		if (dictTree1.Find(qwe) == false){

			cout << "BSTree: " << qwe << endl;
		}
		else{
			numAVL += dictTree.FindComparisons(qwe);
		}


	}




	a.close();
	
	cout << "letter campaison." << endl;
	cout << "BST number of comparisons is: " << numBST << " |VS|  AVL number of comparisons is:  " << numAVL << endl;
	
	
	
	
	return 0;
}