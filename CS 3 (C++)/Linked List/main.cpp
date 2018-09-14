//xuecong fan
//Did in the tutor center
#include "Set.h"
#include <iostream>
using namespace std;

int main(){
	Set a;
	Set b;
	a.Insert(1);
	a.Insert(4);
	a.Insert(9);


	b.Insert(4);
	b.Insert(8);
	b.Insert(9);

	

	cout << "A: " << endl;
	a.Print();
	cout << "B: " << endl;
	b.Print();

	if (a < b){
		cout << "a< b" << endl;
	}
	cout << "intersection: " << endl;

	Set iset = a^b;
	iset.Print();
	cout << "union: " << endl;
	Set set = a + b;
	set.Print();
	cout << "set difference: " << endl;
	Set st = a - b;
	st.Print();
	cout << "a = b" << endl;
	b=a;

	cout << "A: " << endl;
	a.Print();
	cout << "B: " << endl;
	b.Print();


	cout << "delet 1" << endl;
	a.Delete(1);
	cout << "A: " << endl;
	a.Print();

	cout << "find 3" << endl;
	
	bool Find = a.Find(3);
	cout << "find: " << Find << endl;
	return 0;
}