//xuecong fan
//visual studio

#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	char f;
	ifstream fin;
	ofstream fout;
	fin.open("secretMessage.txt");
	fout.open("decodedMessage.txt");
	while (!fin.eof()){
		fin.get(f);
		if ((f >= 'A') && (f <= 'M'))
		{
			f += 13;

		}
		else if ((f >= 'N') && (f <= 'Z'))
		{

			f -= 13;
		}
		else if ((f >= 'a') && (f <= 'm'))
		{
			f += 13;
		}
		else if ((f >= 'n') && (f <= 'z'))
		{
			f -= 13;
		}
		fout << f;
	}
	fin.close();
	fout.close();


	return 0;
}