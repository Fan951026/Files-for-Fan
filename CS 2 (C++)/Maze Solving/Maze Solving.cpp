#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void find(int  row, int col, char**maze);

int main()
{
	
	
	ifstream txt;
	txt.open("maze.txt");
	int row;
	int col;
	

      if(txt.is_open()){
	    txt >> row;
		txt >> col;
		char**arr = new char *[row];
		for (int i = 0; i < row; ++i){
			arr[i] = new char [col];
		}
		cout << "Row:" << row << endl;
		int startrow = 0;
		int startcol = 0;
		cout << "col:" << col << endl;
		for (int i = 0; i < row; ++i){
			for (int j = 0; j < col; ++j){
				txt >> arr[i][j];
				cout << arr[i][j];
				if (arr[i][j] == 's'){
					startrow = i;
					startcol = j;
				}

			}
			cout << endl;
		}
		find(startrow, startcol, arr);
     }
	 

	  





	
	
	return 0;
}

void find(int  row, int col, char**maze){
	
	if (maze[row][col] == 'e'){
		
		return;
	}

	else if (maze[row + 1][col] == '.' || maze[row + 1][col] == 'e'){
		maze[row][col] = 'v';
		cout << "v" << endl;

		find(row + 1, col, maze);
	}

	else if (maze[row - 1][col] == '.' || maze[row - 1][col] == 'e'){
		maze[row][col] = 'v';
		cout << "^" << endl;
		find(row - 1, col, maze);

	}

	else if (maze[row][col - 1] == '.' || maze[row][col - 1] == 'e'){
		maze[row][col] = '<';
		cout << "<" << endl;
		find(row, col - 1, maze);

	}
	else if (maze[row][col + 1] == '.' || maze[row][col + 1] == 'e'){
		maze[row][col + 1] = '>';
		cout << ">" << endl;
		find(row, col + 1, maze);

	}

	else if (maze[row - 1][col] == 'v'){
		maze[row][col] = '#';
		find(row - 1, col, maze);
	}

	else if (maze[row + 1][col] == '^'){
		maze[row][col] = '#';
		find(row + 1, col, maze);
	}

	else if (maze[row][col + 1] == '<'){
		maze[row][col] = '#';
		find(row, col + 1, maze);
	}

	else if (maze[row][col - 1] == '>'){
		maze[row][col] = '#';
		find(row, col - 1, maze);


	}
}