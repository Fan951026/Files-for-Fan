//xuecong fan
//assignment did in totur center with friends 


#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>  
#include <vector>
#include <locale>   
#include "BSTREE.h"
using namespace std;



int main(){
	ifstream b;
	b.open("dictionary.txt");
	if (b.fail()){
		cout << "it fail" << endl;
	}
	vector < string > dic ;


	string app;
	BSTree tree;
	while (b >> app){
		dic.push_back(app);
		
	
	}
	
	random_shuffle(dic.begin(), dic.end());
	for (int i = 0; i < dic.size(); ++i){
		tree.Insert(dic.at(i));
		
		
	}
	cout << "finish" << endl;
	cout << tree.Height() << endl;
	cout << tree.Size() << endl;
	BSTree tree2;
	for (int i = 0; i < 10; ++i){
		tree2.Insert(dic.at(i));

	}
	cout << tree2.Traverse() << endl;
	cout << "delete " << dic.at(3) << endl;
	tree2.Delete(dic.at(3));
	cout << "after delete " <<  tree2.Traverse() << endl;
	
	cout << "tree height: "<<tree2.Height() << endl;
	cout << "tree size: " <<tree2.Size() << endl;
	cout << "find: " << dic.at(3) << " " << tree2.Find(dic.at(3)) << endl;
	b.close();
	
	
	ifstream a;
	a.open("letter.txt");
	
	string bpp;
	while (a>>bpp){
		for (int i = 0; i < bpp.size(); ++i){
			
			
			bpp[i] = tolower(bpp[i]);
			
		}


	if (tree.Find(bpp) == false){
			cout << bpp << endl;
		}

	}
	a.close();


/*
	tree.Insert("tree");
	tree.Insert("cocoa");
	tree.Insert("wow");
	tree.Insert("zzzz");
	tree.Insert("vortex");
	tree.Insert("uu");
	tree.Insert("apple");
	if (tree.Find("tree")){
		cout << "'tree' is in the BST" << endl;
	}

	cout << tree.Traverse() << endl;
	cout << tree.Height() << endl;
	tree.Delete("wow");
	cout << tree.Traverse() << endl;
	cout << tree.Size() << endl;*/

	









	return 0;

}
