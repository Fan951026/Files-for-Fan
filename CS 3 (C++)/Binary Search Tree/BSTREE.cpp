//xuecong fan
//assignment did in totur center with friends 


#include"BSTREE.h"
#include<iostream>
#include<string>
using namespace std;

TreeNode::TreeNode(string s){
	 word = s;
	 ptrLeft = NULL;
	 ptrRight = NULL;
}
TreeNode::TreeNode(){
	word = "";
	ptrLeft = NULL;
	ptrRight = NULL;
}
BSTree::BSTree(){
	root = NULL;
}
BSTree::BSTree(const BSTree &B){
	BSTree temp = B;
	root = new TreeNode(temp.root->word);
	


	while (root->ptrLeft != NULL||root->ptrRight != NULL){
		root->ptrLeft = new TreeNode(temp.root->ptrLeft->word);
        root->ptrRight = new TreeNode(temp.root->ptrRight->word);
	}

}

string BSTree::Traverse() 
{ 
	cout << "Postoder traversal " << endl; 
	return RTraverse(root); 
}

string BSTree::RTraverse(TreeNodeptr ptr) {
	string ls, rs; 
	if (ptr == NULL)  
		return ""; 
	else {
		cout << "Intermediate Result: " << ptr->word << endl;
		ls = RTraverse(ptr->ptrLeft); 
		rs = RTraverse(ptr->ptrRight); 
	
		//Post-order traverse 
		return (ptr->word+ "  " + ls + rs); 
		
	} 
}



BSTree::~BSTree(){
	BSTtree(this->root);
	root = NULL;
}
void BSTree::BSTtree(TreeNodeptr & ptr){
	if (ptr == NULL){
		return;
	}
	delete ptr->ptrLeft;
	delete ptr->ptrRight;

		ptr = NULL;
}
void BSTree::Insert(string s){
	if (root == NULL){
		root = new TreeNode(s);
	}
	else{
		TreeNodeptr parent = NULL;
		TreeNodeptr ptr = root;
		while (ptr != NULL){

			if (s <= ptr->word) {
				parent = ptr;
				ptr = ptr->ptrLeft;

			}
			else if (s > ptr->word){
				parent = ptr;
				ptr = ptr->ptrRight;

			}
		}

		if (ptr == NULL && s < parent->word){
			parent->ptrLeft = new TreeNode(s);
		}
		else if (ptr == NULL && s > parent->word){
			parent->ptrRight = new TreeNode(s);
		}
	// Insert new string into either parent's left or right branch.
	//parent->ptrLeft = new TreeNode(s);
	//parent->ptrRight = new TreeNode(s);
	}
}
void BSTree::Delete(string s){
	RDelete(s, root);
}
void BSTree::RDelete(string s, TreeNodeptr& ptr){
	TreeNode *temp;
	temp = root;
	TreeNode *parent =NULL;
	
	bool full = false;

	while (full == false){
		if (temp == NULL){
			return;
		}
		else if (s == temp->word){
			full = true;
		}
		else if (s < temp->word){
			parent = temp;
			temp = temp->ptrLeft;
			
		}
		else{
			parent = temp;
			temp = temp->ptrRight;
		}
	}

	
	TreeNode *temp1;
	temp1 = temp->ptrLeft;
	if (temp1 == NULL){
		if (parent->ptrLeft == temp){
			parent->ptrLeft = temp->ptrRight;
		}
		else {
			parent->ptrRight = temp->ptrRight;
		}
		delete temp;
		temp = NULL;
	}
	if (temp1->ptrRight == NULL){
		if (parent->ptrLeft == temp){
			parent->ptrLeft = temp1;
		}
		else {
			parent->ptrRight = temp1;
		}
		
		temp1->ptrRight = temp->ptrRight;
		delete temp;
		temp = NULL;
	}
	else{
		while (temp1->ptrRight != NULL){
			
			temp1 = temp1->ptrRight;
		

		}
		temp->word = temp1->word;

		delete temp1;
		temp1 = NULL;
	}


	
}

bool BSTree::Find(string s){
	return RFind(s, root);
}

bool BSTree::RFind(string s, TreeNodeptr ptr){
	ptr = root;
	while (ptr != NULL){
		if (s == ptr->word) {
			return true;
		}
		else if (s < ptr->word ) {
			
			ptr = ptr->ptrLeft;
			

		}
		else if (s > ptr->word ){
			ptr = ptr->ptrRight;
		}

	}
	return false;
}

int BSTree::Height(){

	return RHeight(root);
}
int BSTree::RHeight(TreeNode* &ptr){

	if (ptr == NULL){
		return 0;
	}
	
		int count = RHeight(ptr->ptrLeft);
		int num = RHeight(ptr->ptrRight);
		if (count > num){
			return count + 1;
		}
		else {
			return num + 1;
		}
	
}
int BSTree::Size(){
	return RSize(root);
}
int BSTree::RSize( TreeNodeptr& ptr){
	if (ptr == NULL){
		return 0;
	}
	else {
		return RSize(ptr->ptrLeft) + RSize(ptr->ptrRight)+1;
	}
}




