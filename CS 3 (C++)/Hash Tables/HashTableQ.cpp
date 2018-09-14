#define _USE_MATH_DEFINES
#include "HashTableQ.h"
#include <string>
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

HashTableQ::HashTableQ(int size){
	m = size;
	T = new Element1[m];
	for (int i = 0; i < m - 1; ++i){
		T[i].flag = 0;
	}
}
int HashTableQ::Hash(string x){
	unsigned int value = 0;
	for (int i = 0; i < x.length(); ++i){
		value += x[i];
	}
	return value % m;
}
int HashTableQ::QuadraticProbe(string x, int i){
	return (Hash(x) + i*i) % m;
}
void HashTableQ::Insert(string x, double y, double z){
	int i = 0;
	while (i < m){
		int k = QuadraticProbe(x, i);
		if (T[k].flag != ACTIVE){
			T[k].zipcode = x; T[k].latitude = y; 
			T[k].longitude = z; T[k].flag = ACTIVE;
			return;
		}
		else{
			i++;
		}
	}
	cout << "The table is full for the linear probing.";
}
void HashTableQ::Remove(string x){
	int i = 0;
	Element1 node;
	while (i < m){
		int k = QuadraticProbe(x, i);
		if (T[k].flag == EMPTY){
			return;
		}
		if (T[k].zipcode == x){
			T[k] = node;
			T[k].flag =	DELETED;
		}
		i++;
	}
}
bool HashTableQ::Search(string x){
	int i = 0;
	Element1 node;
	while (i < m){
		int k = QuadraticProbe(x, i);
		if (T[k].flag == EMPTY){
			return false;
		}

		if (T[k].zipcode == x){
			return true;
		}
		else{
			return false;
		}
	}
}


double HashTableQ::rdegree(double degree){
	return degree* M_PI / 180;
}
Element1 HashTableQ::findele(string a){
	int i = 0;
	Element1 node;
	node.flag = EMPTY;
	while (i < m){
		int k = QuadraticProbe(a, i);
		if (T[k].flag == EMPTY){
		
			return node;
			
		}
		if (T[k].zipcode == a){
			node = T[k];
			return node;
		}
		else {
			i++;
		}
	
	}
	return node;
	
}

double HashTableQ::ComputeDistance(string x1,string x2){
	Element1 first = findele(x1);
	Element1 second = findele(x2);
	double la_1 = rdegree(first.latitude);
	double la_2 = rdegree(second.latitude);
	double lo_1 = rdegree(first.longitude);
	double lo_2 = rdegree(second.longitude);
	cout << first.zipcode << endl;
	cout << second.zipcode << endl;

	return 3961 * 2 * asin(sqrt(pow(sin((la_2 - la_1) / 2), 2)
		+ cos(la_1)*cos(la_2)
		*pow(sin((lo_2 - lo_1) / 2), 2)));

}
void HashTableQ::PrintTableEntry(){
	int count = 0;
	cout << "\n";
	for (int i = 0; i < m; ++i){

		Element1 node = T[i];
		if (node.flag == ACTIVE){
			cout << "\n" << i << ": " << node.zipcode << ", "
				<< node.latitude << ", " << node.longitude << "\n";

			count++;
		}

	}
	if (count == 0){
		cout << "Empty" << endl;
	}







}