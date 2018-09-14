#include "MaxHeap.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int BinarySearch(Element a[], int arraySize, string target);
int FindFirstIndex(Element a[], int arraySize,  string target);
int FindLastIndex(Element a[], int arraySize,  string target);


int main(){

	Element a;
	a.weight = 3;
	a.word = "asd";
	Element b;
	b.weight = 8;
	b.word = "ban";
	Element c;
	c.weight = 10;
	c.word = "can";
	Element d;
	d.weight = 15;
	d.word = "dan";
	Element e;
	e.weight = 18;
	e.word = "eye";
	Element f;
	f.weight = 35;
	f.word = "gan";
	Element g;
	g.weight = 45;
	g.word = "qwe";

	MaxHeap w;
	w.Insert(a);
	w.Insert(b);
	w.Insert(c);
	w.Insert(d);
	w.Insert(e);
	w.Insert(f);
	w.Insert(g);
	w.PrintHeap();
	cout << "DeleteMax: " << endl;
	w.DeleteMax();
	w.PrintHeap();
	cout << "DeleteMax: " << endl;
	w.DeleteMax();
	w.PrintHeap();

	Element*wvv;
	wvv = w.FindTopMatches(3);
	for (int i = 0; i < 1; i++){
		cout << wvv[i].word << endl;

	}

	cout << "----------------------------------------------------------------" << endl;
	cout << "Second: " << endl;
	//Element a1;
	//a1.weight = 1;
	//a1.word = "fan";
	//Element b1;
	//b1.weight = 2;
	//b1.word = "hig";
	//Element c1;
	//c1.weight = 7;
	//c1.word = "egg";
	//Element d1;
	//d1.weight = 13;
	//d1.word = "pic";
	//Element e1;
	//e1.weight = 25;
	//e1.word = "did";
	//Element f1;
	//f1.weight = 30;
	//f1.word = "tai";
	//Element g1;
	//g1.weight = 41;
	//g1.word = "pan";


	//MaxHeap q;
	//q.Insert(a1);
	//q.Insert(b1);
	//q.Insert(c1);
	//q.Insert(d1);
	//q.Insert(e1);
	//q.Insert(f1);
	//q.Insert(g1);
	
	int heapSize = 7;
	int arraySize = 8;
	Element *es = new Element[arraySize];
	Element e1;
	Element e2;
	Element e3;
	Element e4;
	Element e5;
	Element e6;
	Element e7;
	e1.weight = 1;
	e1.word = "asf";
	e2.weight = 2;
	e2.word = "def";
	e3.weight = 3;
	e3.word = "fre";
	e4.weight = 4;
	e4.word = "ger";
	e5.weight = 5;
	e5.word = "van";
	e6.weight = 6;
	e6.word = "zig";
	e7.weight = 7;
	e7.word = "sdff";




	es[1] = e1;
	es[2] = e2;
	es[3] = e3;
	es[4] = e4;
	es[5] = e5;
	es[6] = e6;
	es[7] = e7;
	MaxHeap q(es, heapSize, arraySize);
	q.PrintHeap();
	cout << "DeleteMax: " << endl;
	q.DeleteMax();
	q.PrintHeap();
	cout << "DeleteMax: " << endl;
	q.DeleteMax();
	q.PrintHeap();
	Element*qvv;
	qvv = q.FindTopMatches(1);
	for (int i = 0; i < 1; i++){
		cout << qvv[i].word << endl;
	}
	cout << "-------------------------------------------------" << endl;

	cout << "merge two of them: " << endl;
	w.Merge(q);
	w.PrintHeap();
	Element*gvv;
	gvv = w.FindTopMatches(2);
	for (int i = 0; i < 2; i++){
		cout << gvv[i].word << endl;

	}
	cout << "----------------------------------------------------------" << endl;

	ifstream qww;
	qww.open("SortedWords.txt");
	int size;
	string temp;
	getline(qww, temp);
	size = stoi(temp);

	MaxHeap t(size + 10);

	string wo;
	int wei;

	Element * pop;
	
	pop = new Element[size];
	for (int i = 0; i < size; i++){

		qww >> wo >> wei;

		pop[i].weight = wei;
		pop[i].word = wo;
		t.Insert(pop[i]);
	}
	string choose;
	cout << "***********************************************************" << endl;
	cout << "Menu: " << endl;
	cout << "S: Search top words with one prefix or two prefixes" << endl;
	cout << "Q: Quit Search" << endl;
	cout << "************************************************************" << endl;
	
	while (choose != "S" || choose != "Q"){
	//	
		cin >> choose;
		if (choose == "S"){
			string dpp;
			cout << "Please input your prefix or prefixes: ";
			cin >> dpp;
			int found = dpp.find('&');
			if (found < 0){

				int first = FindFirstIndex(pop, size, dpp);
				int last = FindLastIndex(pop, size, dpp);
				MaxHeap h(size);
				for (int i = first; i <= last; i++){
					h.Insert(pop[i]);
				}
				int count;
				cout << "Please input the number of top matches you want to return: ";
				cin >> count;
				Element*mvv;
				mvv = h.FindTopMatches(count);
				for (int i = 0; i < count; i++){
					cout << mvv[i].word << endl;

				}
			}
			else
			{

				
				string new1 = dpp.substr(0, found);
				string new2 = dpp.substr(found + 1, dpp.length() - 1);
				BinarySearch(pop, size, new1);
				int first = FindFirstIndex(pop, size, new1);
				int last = FindLastIndex(pop, size, new1);
				MaxHeap p1(size);
				for (int i = first; i <= last; i++){
					p1.Insert(pop[i]);
				}
			
				MaxHeap y(size);
				BinarySearch(pop, size, new2);
				int first1 = FindFirstIndex(pop, size, new2);
				int last1 = FindLastIndex(pop, size, new2);
				for (int j = first1; j <= last1; j++){
					y.Insert(pop[j]);
				}
			
				p1.Merge(y);
				
				int count1;
				cout << "Please input the number of top matches you want to return: ";
				cin >> count1;
				Element*err;
				
				err = p1.FindTopMatches(count1);
				for (int i = 0; i < count1; i++){
					cout << err[i].word << endl;

				}



			}



		}
		else if (choose == "Q"){
			cout << "Thank you for using autocomplete software developed by xuecong" << endl;
			return 0;
		}
		else{

			cout << "your type wrong word! Do it again:" << endl;;
			cout << "***********************************************************" << endl;
			cout << "Menu: " << endl;
			cout << "S: Search top words with one prefix or two prefixes" << endl;
			cout << "Q: Quit Search" << endl;
			cout << "************************************************************" << endl;
			cin >> choose;
		}





	}






	
	return 0;


}


int BinarySearch(Element a[], int arraySize, string target){
	
	int start = 0;
	int end = arraySize;
	while (end > start) {

		int mid = (start+end) / 2;

		if (target == a[mid].word.substr(0, target.length())){
			return mid;
		}
		else{
			if (target < a[mid].word.substr(0, target.length())){
				end = mid - 1;
			}
			if (target > a[mid].word.substr(0, target.length())) {
				start = mid + 1;
			}
		}
	}
	return -1;


}
int FindFirstIndex(Element a[], int arraySize, string target){
	int firstindex = BinarySearch(a, arraySize, target);
	bool s = false;
	while (!s){
		if (a[firstindex - 1].word.substr(0, target.length()) == target){
			firstindex = firstindex - 1;
		}
		else{
			s = true;
		}
	}
	return firstindex;
}
int FindLastIndex(Element a[], int arraySize, string target){
	int lastindex = BinarySearch(a, arraySize, target);
	bool f = false;
	while (!f){
		if (a[lastindex + 1].word.substr(0, target.length()) == target){
			lastindex = lastindex + 1;
		}
		else {
			f = true;
		}
	}
	return lastindex;
}
