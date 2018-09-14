//xuecong fan
//Did in the tutor centor
#include "Set.h"
#include <iostream>
using namespace std;
ListNode::ListNode(){
	value =0;
	next = nullptr;
}
ListNode::ListNode(int s){
	value = s;

}

Set::Set()
{
	head = NULL;
	count = 0;
}
Set::Set(Set &obj)
{
	head = NULL;
	count = 0;
	for (int i = 0; i < obj.count; ++i){
		Insert(obj[i]);

	}
}
Set::~Set(){

}
void Set::Insert(int v){
	if (Find(v)){
		return;
	}
	count++;
	ListNode *newnode = new ListNode(v);
	if (head != NULL){
		ListNode*here = head->next;
		ListNode*prev = head;

		while (here != NULL && v > here->value)
		{
			prev = here;
			here = here->next;
		}
		prev->next = newnode;
		newnode->next = here;
	}
	else{
		head = newnode;
	}
}
void Set::Delete(int v){
	ListNode*here = head->next;
	ListNode*prev = head;
	if (prev->value == v){
		head = here;
		delete prev;
		return;
	}
	while (v != here->value&&here->next != NULL){
		cout << here->value << endl;
		prev = here;
		here = here->next;
	
	}
	if (here->next != NULL)
	{
		prev->next = here->next;
		delete here;
	}
}
void Set::Print(){
	ListNode*here = head;
	while (here != NULL){
		cout << here->value << endl;
		here = here->next;
	}
}
bool Set::Find(int v){
	ListNode* temp = head;
	while (temp != NULL){
		if (temp->value == v){
			return true;
		}
		else {
			temp = temp->next;

		}
	}
	return false;
	
}

Set Set::operator^(const Set &obj){
	Set iset;
	ListNode *temp = this->head;
	while (temp != NULL){
		ListNode*app = obj.head;

		while (app != NULL){
			if (temp->value == app->value){
				iset.Insert(temp->value);
			}
			app = app->next;
		}
		temp = temp->next;
	}
	return iset;
}



bool Set::operator<(const Set& obj){
	int cpp = 0;
	int bpp = 0;
	
	ListNode *temp = this->head;
	while (temp != NULL){
		// compare temp->value to every value in obj
		ListNode*app = obj.head;

		while (app != NULL){
			if (temp->value == app->value){
				break;
			}
			
			app = app->next;
		}

		if (app == NULL){
			return false;
		}
		

		temp = temp->next;
		cpp++;
		
	}
	ListNode*app = obj.head;
	while (app != NULL){
		bpp++;
		app = app->next;
	}
	if (cpp == bpp){
		return false;
	}
	return true;
	
}
Set Set::operator+(const Set &obj){
	Set set;
	
	ListNode *temp = this->head;
	while (temp != NULL){
		ListNode*app = obj.head;
		set.Insert(temp->value);
		while (app != NULL){
			if (app->value != temp->value){
				set.Insert(app->value);
			}
			
			app = app->next;
		}
		temp = temp->next;
		
	}
	return set;
}
Set Set::operator-(const Set &obj){
	Set st;
	ListNode *temp = this->head;
	while (temp != NULL){
		ListNode*app = obj.head;

		while (app != NULL){
			if (temp->value != app->value){
				app = app->next;
			}
			else{
				break;
			}
		
			
		}
		if (app == NULL){
			st.Insert(temp->value);
		}
	
		temp = temp->next;

	}
	return st;
}
Set &Set::operator=( const Set &obj){




	ListNode *temp = this->head;
	while (temp != NULL){
		head = head->next;
		delete temp;
		temp = head;
	}	
	temp = obj.head;
	while (temp != NULL){
		
		
		this->Insert(temp->value);
		temp = temp->next;
		}
	

	return *this;
	}

int Set::operator[](const int index){
	int i = 0;
	ListNode*current = head;
	if (head == NULL){
		return 0;
	}
	while (i < index&&current->next != NULL){
		current = current->next;
		i++;

	}
	if (i < index){
		return 0;
	}
	else{
		return current->value;
	}

}
