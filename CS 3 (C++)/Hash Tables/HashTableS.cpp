#define _USE_MATH_DEFINES
#include "HashTableS.h"
#include <string>
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

HashTableS::HashTableS(int size){
	m = size;
	T = new Element *[m];
	for (int i = 0; i <= m - 1; ++i){
		T[i] = NULL;
	}


}
int HashTableS::Hash(string x){

	

	unsigned int value = 0;
	for (int i = 0; i < x.length(); ++i){
		value += x[i];
	}
	return value % m;
}
void HashTableS::Insert(string x, double y, double z){
	Element*q = new Element(x, y, z);
	int k = Hash(x);
	Element*p = T[k];
	q->next = p;
	T[k] = q;

}
void HashTableS::Remove(string x){
	int k = Hash(x);

	Element *nodeptr, *prenodeptr = nullptr;
	if (!T[k]){
		return;
	}
	if (T[k]->zipcode == x){
		nodeptr = T[k];
		T[k] = T[k]->next;
		delete nodeptr;

	}
	else{
		nodeptr = T[k];
		while (nodeptr != NULL && nodeptr->zipcode != x){
			prenodeptr = nodeptr;
			nodeptr = nodeptr->next;
		}
		if (nodeptr){
			prenodeptr->next = nodeptr->next;
			delete nodeptr;
		}
	}
}

bool HashTableS::Search(string x){

	int k = Hash(x);
	Element *nodeptr;
	if (T[k] == NULL){
		return false;
	}
	if (T[k]->zipcode == x){
		return true;

	}
	else{
		nodeptr = T[k];
		while (nodeptr != NULL && nodeptr->zipcode != x){
			nodeptr = nodeptr;
			nodeptr = nodeptr->next;
		}
		if (nodeptr){
			return true;
		}
		else{
			return false;
		}
	}
}
Element* HashTableS::findele(string a){

	int k = Hash(a);
	Element *nodeptr;
	if (T[k] == NULL){
		return NULL;
	}
	if (T[k]->zipcode == a){
		return T[k];

	}
	else{
		nodeptr = T[k];
		while (nodeptr != NULL && nodeptr->zipcode != a){
			nodeptr = nodeptr;
			nodeptr = nodeptr->next;
		}
		if (nodeptr){
			return nodeptr;
		}
		else{
			return NULL;
		}
	}
}
double HashTableS :: rdegree(double degree){
	return degree* M_PI / 180;
}

double HashTableS::ComputeDistance(string x1, string x2){
	
	Element first = *findele(x1);
	Element second =*findele(x2);
	double la_1 = rdegree(first.latitude);
	double la_2 = rdegree(second.latitude);
	double lo_1 = rdegree(first.longitude);
	double lo_2 = rdegree(second.longitude);
	

	return 3961 * 2 * asin(sqrt(pow(sin((la_2 - la_1) / 2), 2)
		+ cos(la_1)*cos(la_2)
		*pow(sin((lo_2 - lo_1) / 2), 2)));

}
int HashTableS::CountTableEntry(int i){
	Element *nodeptr;
	nodeptr = T[i];
	int count = 0;
	while (nodeptr != NULL){
		nodeptr = nodeptr->next;
		count+=1;
	}
	return count;
}
void HashTableS::PrintTableEntry(){
	int count = 0;
	cout << "\n";
	for (int i = 0; i < m; ++i){
		
		Element *nodeptr = T[i];
		while (nodeptr != NULL){
			cout << "\n" << i << ": " << nodeptr->zipcode << ", "
				<< nodeptr->latitude << ", " << nodeptr->longitude << "\n";

			count++;
			nodeptr = nodeptr->next;
		}
		

	}
	if (count == 0){
		cout << "Empty" << endl;
	}
}
int HashTableS::findlength(){
	Element *nodeptr;
	int count = 0;
	for (int i = 0; i < m; ++i){
		nodeptr = T[i];
		while(nodeptr != NULL){
			count += 1;
			nodeptr = nodeptr->next;
		}
	}
	return count/m;
}
