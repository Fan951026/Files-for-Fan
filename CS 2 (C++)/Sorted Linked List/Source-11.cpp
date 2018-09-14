//xuecong fan
#include "link.h"
#include <iostream>
#include<string>

using namespace std;

void test(int & i){
	i *= 4;
}
void Insert(){
	cout << "Insert the list: " << endl;
}
void size(){
	cout << "Show the size of the element: " << endl;
}
void show(){
	cout << "Show the list: " << endl;
}
int main(){

	link<int> linked;
	Insert();
	linked.add (2);
	linked.displaylist();
	cout << "\n" << endl;
	size();
	cout << linked.number() << endl;
	show();
	linked.displaylist();

	cout << "\n" << endl;
	
	Insert();
	linked.add(3) ;
	linked.displaylist();
	cout << "\n" << endl;
	size();
	cout << linked.number() << endl;
	linked.number();
	show();
	linked.displaylist();

	cout << "\n" << endl;

	Insert();
	linked.add (1); 
	linked.displaylist();
	cout << "\n" << endl;
	size();
	cout << linked.number() << endl;
	linked.number();
	show();
	linked.displaylist();

	cout << "\n" << endl;

	Insert();
	linked.add (4);
	linked.displaylist();
	cout << "\n" << endl;
	size();
	cout << linked.number() << endl;
	linked.number();
	show();
	linked.displaylist();
	
	cout << "\n" << endl;
	cout << "copy construction(deep): " << endl;
	link<int> list1(linked);
	show();
	linked.displaylist();

	cout << "\n" << endl;
	cout << "copy assignment(deep):" << endl;
	link<int> list = linked;
	linked.displaylist();

	cout << "\n" << endl;
	cout << "For each function times 4" << endl;
	linked.foreach(test);
	show();
	linked.displaylist();
	cout << "\n" << endl;
	size();
	cout << linked.number() << endl;
	cout << "\n" << endl;

	cout << "Remove an element :"<< endl;
	linked.remove(8);
	linked.displaylist();
	cout << "\n" << endl;
	size();
	cout << linked.number() << endl;
	show();
	linked.displaylist();
	cout << "\n" << endl;
	cout << "Remove an element :" << endl;
	linked.remove(12);
	linked.displaylist();
	cout << "\n" << endl;
	size();
	cout << linked.number() << endl;
	show();
	linked.displaylist();
	cout << "\n" << endl;
	cout << "Remove an element :" << endl;
	linked.remove(16);
	linked.displaylist();
	cout << "\n" << endl;
	size();
	cout << linked.number() << endl;
	show();
	linked.displaylist();
	cout << "\n" << endl;
	cout << "Remove an element :" << endl;
	linked.remove(4);
	linked.displaylist();
	cout << "\n" << endl;
	size();
	cout << linked.number() << endl;
	show();
	linked.displaylist();
	

	

		

	
	
	
	




	return 0;
}



