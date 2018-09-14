#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void correctedbronze(int &, int &, int &);
void correctedsilver(int &, int &, int &);
void correctedgold(int &, int &, int &);


int main(){

	string distroted, corrected, header;
	char choose;
	int height;
	int width;
	int colorl;
	int r;
	int g;
	int b;

	cout << "what's the input file called" << endl;
	cin >> distroted;

	cout << "what's the output file called" << endl;
	cin >> corrected;

	ifstream fin;
	ofstream fout;

	fin.open(distroted);
	fout.open(corrected);

	fin >> header >> height >> width >> colorl;
	fout << header << endl << height << " " << width <<endl << colorl << endl;

	cout << "what would you like to do ?" << endl;
	cout << "b= bronze,s=silver,g=gold" << endl;
	cin >> choose;

	while (choose != 'b' && choose != 'r' && choose != 'g'){
		cout << "chose again" << endl;
		cin >> choose;
	}
	while (!fin.eof()){
		fin >> r >> g >> b;

		if (choose == 'g'){
			correctedgold(r, b, g);
		}
		else if (choose == 'b'){
			correctedbronze(r, b, g);
		}
		else{
			correctedsilver(r, b, g);
		}

		fout << r << " " << g << " " << b << " ";
	}


	return 0;
}
void correctedbronze(int &r, int &b, int &g) {
	r = r * 10;
	g = 0;
	b = 0;

}
void correctedsilver(int &r, int &b, int &g){
	r = 0;
	g = g * 20;
	b = b * 20;
}
void correctedgold(int &r, int &b, int &g){
	b = r % 1000;
	g = r / 1000 % 1000;
	r = r / 1000000;
}
