#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "how4_a01972388.h"
using namespace std;

AvlNode::AvlNode(string s){
	word = s;
	ptrLeft = NULL;
	ptrRight = NULL;
}
AvlNode::AvlNode(){
	word = "";
	ptrLeft = NULL;
	ptrRight = NULL;
}

AvlTree::AvlTree(){
	root = NULL;
}
AvlTree::AvlTree(const AvlTree & B){
	AvlTree temp = B;
	root = new AvlNode(temp.root->word);

	while (root->ptrLeft != NULL || root->ptrRight != NULL){
		root->ptrLeft = new AvlNode(temp.root->ptrLeft->word);
		root->ptrRight = new AvlNode(temp.root->ptrRight->word);
	}
}
AvlTree::~AvlTree(){
	Avltree(this->root);
	root = NULL;
}
void AvlTree::Avltree(AvlNodeptr & ptr){
	if (ptr == NULL){
		return;
	}
	delete ptr->ptrLeft;
	delete ptr->ptrRight;

	ptr = NULL;
}
string AvlTree::Traverse(){
	cout << "The pre-order traversal list is:" << endl;
	return RTraverse(root);
}
string AvlTree::RTraverse(AvlNodeptr ptr){
	string ls, rs;
	if (ptr == NULL){
		return "";
	}
	else {

		ls = RTraverse(ptr->ptrLeft);
		rs = RTraverse(ptr->ptrRight);


		return (ptr->word + "  " + ls + rs);

	}

}
string AvlTree::Traverse1(){
	cout << "The descending order traversal list is:" << endl;
	return RRTraverse(root);
}
string AvlTree::RRTraverse(AvlNodeptr ptr){
	string ls, rs;
	if (ptr == NULL){
		return "";
	}
	else {

		ls = RRTraverse(ptr->ptrLeft);
		rs = RRTraverse(ptr->ptrRight);


		return (rs +" "+ ptr->word + " " + ls );

	}
	/*	cout << "ls: "<<ls << endl;
		cout << "rs: " << rs << endl;
		cout << "ptr->word: " << ptr->word << endl;*/


	

	
}
	int AvlTree::Height(){

		return RHeight(root);
	}
	int AvlTree::RHeight(AvlNode* ptr){

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
	int AvlTree::Size(){
		return RSize(root);
	}
	int AvlTree::RSize(AvlNodeptr& ptr){
		if (ptr == NULL){
			return 0;
		}
		else {
			return RSize(ptr->ptrLeft) + RSize(ptr->ptrRight) + 1;
		}
	}
	int AvlTree::GetHeight(AvlNodeptr v){
		if (v == NULL){
			return -1;
		}
		else {
			return  1 + max(GetHeight(v->ptrLeft), GetHeight(v->ptrRight));
		}


	}

	int AvlTree::max(int first, int second){
		if (first > second){
			return first;
		}
		else {
			return second;
		}
	}

	void AvlTree::balance(AvlNode* & ptr){
		if (ptr == NULL){
			return;
		}
		if (GetHeight(ptr->ptrLeft) - GetHeight(ptr->ptrRight) > 1){
			if (GetHeight(ptr->ptrLeft->ptrLeft) >= GetHeight(ptr->ptrLeft->ptrRight)){
				rightRotate(ptr);
			}
			else {
				doubleLeftRightRotate(ptr);
			}
		}
		if (GetHeight(ptr->ptrRight) - GetHeight(ptr->ptrLeft) > 1){
			if (GetHeight(ptr->ptrRight->ptrRight) >= GetHeight(ptr->ptrRight->ptrLeft)){
				leftRotate(ptr);
			}
			else{
				doubleRightLeftRotate(ptr);
			}
		}
		ptr->height = 1 + max(GetHeight(ptr->ptrLeft), GetHeight(ptr->ptrRight));

	}

	void AvlTree::Insert(string s){
		RInsert(root, s);

	}
	void AvlTree::RInsert(AvlNode *& ptr, string s){
		if (ptr == NULL){
			ptr = new AvlNode(s);
			return;
		}
		else {
			if (s == ptr->word){
				return;
			}
			else if (s < ptr->word){
				RInsert(ptr->ptrLeft, s);
				balance(ptr);
			}
			else{
				RInsert(ptr->ptrRight, s);
				balance(ptr);
			}

		}

	}

	void AvlTree::Delete(string s){
		RDelete(root, s);
	}
	void AvlTree::RDelete(AvlNode *& ptr, string s){
		if (ptr != NULL){
			if (s == ptr->word){
				DelNode(ptr);
			}
			else if (s<ptr->word){
				RDelete(ptr->ptrLeft, s);
			}
			else {
				RDelete(ptr->ptrRight, s);
			}
			balance(ptr);
		}
	}
	void AvlTree::DelNode(AvlNode*& ptr){
		if (ptr->ptrLeft == NULL&&ptr->ptrRight == NULL){
			delete ptr;
			ptr = NULL;
		}
		else if (ptr->ptrLeft == NULL){
			AvlNode* here = ptr;
			ptr = ptr->ptrRight;
			delete here;
		}
		else if (ptr->ptrRight == NULL){
			AvlNode* here = ptr;
			ptr = ptr->ptrLeft;
			delete here;
		}
		else {
			AvlNode*here = ptr->ptrRight;
			while (here->ptrLeft != NULL){
				here = here->ptrLeft;
			}
			ptr->word = here->word;
			RDelete(ptr->ptrRight, here->word);

		}
	}

	void AvlTree::rightRotate(AvlNodeptr& ptr){
		AvlNode*ptr1 = ptr->ptrLeft;

		ptr->ptrLeft = ptr1->ptrRight;
		ptr1->ptrRight = ptr;

		ptr->height = 1 + max(GetHeight(ptr->ptrLeft), GetHeight(ptr->ptrRight));
		ptr1->height = 1 + max(GetHeight(ptr1->ptrLeft), GetHeight(ptr1->ptrRight));
		ptr = ptr1;
	}
	void AvlTree::leftRotate(AvlNodeptr & ptr){
		AvlNode*ptr1 = ptr->ptrRight;
		ptr->ptrRight = ptr1->ptrLeft;
		ptr1->ptrLeft = ptr;
		ptr->height = 1 + max(GetHeight(ptr->ptrLeft), GetHeight(ptr->ptrRight));
		ptr1->height = 1 + max(GetHeight(ptr1->ptrLeft), GetHeight(ptr1->ptrRight));
		ptr = ptr1;
	}

	void AvlTree::doubleLeftRightRotate(AvlNodeptr & ptr){
		leftRotate(ptr->ptrLeft);
		rightRotate(ptr);

	}
	void AvlTree::doubleRightLeftRotate(AvlNodeptr & ptr){
		rightRotate(ptr->ptrRight);
		leftRotate(ptr);
	}
	string AvlTree::GetRoot(){
		return root->word;
	}
	bool AvlTree::Find(string s){
		return RFind(s, root);
	}

	bool AvlTree::RFind(string s, AvlNodeptr ptr){
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
	int AvlTree::FindComparisons(string s){
		return RFindComparisons(s,root);

	}
	int AvlTree::RFindComparisons(string s,AvlNodeptr ptr){
		ptr = root;
		int count = 0;
		while (ptr != NULL){
			if (s == ptr->word) {
				return count +1;
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


	int AvlTree::CountTwoChildren(){
		return RcountTwoChildren(root);
	}
	int AvlTree::RcountTwoChildren(AvlNodeptr ptr){
	    if(ptr->ptrLeft != NULL&&ptr->ptrRight != NULL){
			return 1 + RcountTwoChildren(ptr->ptrRight) + RcountTwoChildren(ptr->ptrLeft);
			}
		else {
			return 0;
		}
	

	}
	int AvlTree::CountOneChild(){
		return RcountOneChildren(root);
	}
	int AvlTree::RcountOneChildren(AvlNodeptr ptr){
		
		if (ptr->ptrLeft == NULL&&ptr->ptrRight != NULL){
			return 1 + RcountOneChildren(ptr->ptrRight) ;
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

	void AvlTree::Print()
	{
		Print(root, "");
	}

	void AvlTree::Print(AvlNodeptr ptr, string indent)
	{
		if (ptr == NULL) return;
		Print(ptr->ptrRight, indent+"  ");
		cout << indent << ptr->word << endl;
		Print(ptr->ptrLeft, indent+ "  ");
	}
	int AvlTree::CountLeaves(){
		return RcountLeaves(root);
	}
	int AvlTree::RcountLeaves(AvlNodeptr ptr){
		if (ptr->ptrLeft == NULL&&ptr->ptrRight == NULL){
			return 1;
		}
		else if (ptr->ptrLeft == NULL&&ptr->ptrRight != NULL){
			return RcountLeaves(ptr->ptrRight);
		}
		else if (ptr->ptrLeft != NULL&&ptr->ptrRight == NULL){
			return RcountLeaves(ptr->ptrLeft);
		}
		else {
			return  RcountLeaves(ptr->ptrRight) + RcountLeaves(ptr->ptrLeft);
		}
			
		
	}
		


