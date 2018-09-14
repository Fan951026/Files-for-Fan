//xuecong fan
//assignment did in totur center with friends 


#include"BSTree.h"
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



	while (root->ptrLeft != NULL || root->ptrRight != NULL){
		root->ptrLeft = new TreeNode(temp.root->ptrLeft->word);
		root->ptrRight = new TreeNode(temp.root->ptrRight->word);
	}

}

string BSTree::Traverse()
{
	cout << "The pre-order traversal list is: " << endl;
	return RTraverse(root);
}

string BSTree::RTraverse(TreeNodeptr ptr) {
	string ls, rs;
	if (ptr == NULL)
		return "";
	else {
		
		ls = RTraverse(ptr->ptrLeft);
		rs = RTraverse(ptr->ptrRight);

		//Post-order traverse 
		return (ptr->word + "  " + ls + rs);

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
	TreeNode *parent = NULL;

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
	else if (temp1->ptrRight == NULL){
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
		else if (s < ptr->word) {

			ptr = ptr->ptrLeft;


		}
		else if (s > ptr->word){
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
		return -1;
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
int BSTree::RSize(TreeNodeptr& ptr){
	if (ptr == NULL){
		return 0;
	}
	else {
		return RSize(ptr->ptrLeft) + RSize(ptr->ptrRight) + 1;
	}
}
string BSTree::GetRoot(){
	return root->word;
}

int BSTree::CountOneChild(){
	return RcountOneChildren(root);
}
int BSTree::RcountOneChildren(TreeNodeptr ptr){

	if (ptr->ptrLeft == NULL&&ptr->ptrRight != NULL){
		return 1 + RcountOneChildren(ptr->ptrRight);
	}
	else if (ptr->ptrLeft != NULL&&ptr->ptrRight == NULL){
		return 1 + RcountOneChildren(ptr->ptrLeft);
	}
	else if (ptr->ptrLeft != NULL && ptr->ptrRight != NULL) {
		return  RcountOneChildren(ptr->ptrRight) + RcountOneChildren(ptr->ptrLeft);
	}
	else {
		return 0;
	}
}

int BSTree::CountTwoChildren(){
	return RcountTwoChildren(root);
}
int BSTree::RcountTwoChildren(TreeNodeptr ptr){
	if (ptr->ptrLeft != NULL&&ptr->ptrRight != NULL){
		return 1 + RcountTwoChildren(ptr->ptrRight) + RcountTwoChildren(ptr->ptrLeft);
	}
	else if (ptr->ptrLeft == NULL&&ptr->ptrRight != NULL){
		return  RcountTwoChildren(ptr->ptrRight);
	}
	else if (ptr->ptrLeft != NULL&&ptr->ptrRight == NULL){
		return RcountTwoChildren(ptr->ptrLeft);
	}
	else {
		return 0;
	}


}
int BSTree::CountLeaves(){
	return RcountLeaves(root);
}
int BSTree::RcountLeaves(TreeNodeptr ptr){
	if (ptr->ptrLeft == NULL&&ptr->ptrRight == NULL){
		return 1;
	}
	else if (ptr->ptrLeft == NULL&&ptr->ptrRight != NULL){
		return RcountLeaves(ptr->ptrRight);
	}
	else if (ptr->ptrLeft != NULL&&ptr->ptrRight == NULL){
		return RcountLeaves(ptr->ptrLeft);
	}
	else if (ptr->ptrLeft != NULL && ptr->ptrRight != NULL) {
		return  RcountLeaves(ptr->ptrRight) + RcountLeaves(ptr->ptrLeft);
	}
	else {
		return 0;
	}


}

int BSTree::FindComparisons(string s){
	return RFindComparisons(s, root);

}
int BSTree::RFindComparisons(string s, TreeNodeptr ptr){
	ptr = root;
	int count = 0;
	while (ptr != NULL){
		if (s == ptr->word) {
			return count + 1;
		}
		else if (s < ptr->word) {

			ptr = ptr->ptrLeft;
			count++;

		}
		else if (s > ptr->word){
			ptr = ptr->ptrRight;
			count++;
		}

	}
	return count;
}

string BSTree::Traverse1(){
	cout << "The descending order traversal list is:" << endl;
	return RRTraverse(root);
}
string BSTree::RRTraverse(TreeNodeptr ptr){
	string ls, rs;
	if (ptr == NULL){
		return "";
	}
	else {

		ls = RRTraverse(ptr->ptrLeft);
		rs = RRTraverse(ptr->ptrRight);


		return (rs + " " + ptr->word + " " + ls);

	}
}

void BSTree::Print()
{
	Print(root, "");
}

void BSTree::Print(TreeNodeptr ptr, string indent)
{
	if (ptr == NULL) return;
	Print(ptr->ptrRight, indent + "  ");
	cout << indent << ptr->word << endl;
	Print(ptr->ptrLeft, indent + "  ");
}