//xuecong fan
//use Visual Studio

#include <iostream>
#include <string>
using namespace std;
//strat program
int main()
{
	string began, end;
	string listOfMoves = "";
	int numMoves = 0;
	int x; // horizontal distance from start to finish
	int y; // vertical distance from start to finish

	cin >> began >> end;

	x = end[0] - began[0];
	y = end[1] - began[1];

	while (y != 0 || x != 0) {
		if (x>0)
		{
			x--;
			listOfMoves += "R";
		}
		else if (x<0)
		{
			x++;
			listOfMoves += "L";
		}

		if (y>0)
		{
			y--;
			listOfMoves += "U";
		}
		else if (y<0)
		{
			y++;
			listOfMoves += "D";
		}

		listOfMoves += "\n";
		numMoves++;
	}

	cout << numMoves << endl;
	cout << listOfMoves << endl;

	return 0;
}
//end program