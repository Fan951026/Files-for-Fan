#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	cout << setprecision(2) << fixed;
	double Drop = 0.00;
	double balance;
	double Beemans = 10, Dentyne = 10, Chiclets = 10, Carefree = 10;
	double RBeemans = Beemans - 5, RDentyne = Dentyne - 3, RChiclets = Chiclets - 9, RCarefree = Carefree - 4;

	char decision;
	cout << "s - report the machine status " << endl;
	cout << "d - drop in a quarter" << endl;
	cout << "1 - pull the 1st tab" << endl;
	cout << "2 - pull the 2nd tab" << endl;
	cout << "3 - pull the 3rd tab" << endl;
	cout << "4 - pull the 4th tab" << endl;
	cout << "r - restock the machine" << endl;
	cout << "q - quit" << endl;
	cin >> decision;

	while (decision != 'Q' && decision != 'q')

	{
		switch (decision){
		case 's':
		case 'S':
			balance = 24.50;
			balance += Drop;
			cout << "1: " << RBeemans << " packs of Beemans " << endl;
			cout << "2: " << RDentyne << " packs of Dentyne " << endl;
			cout << "3: " << RChiclets << " packs of Chiclets " << endl;
			cout << "4: " << RCarefree << " packs of Carefree " << endl;
			cout << "There is $ " << balance << " in the machine " << endl;
			cin >> decision;
	

			break;

		case 'd':
		case 'D':
			cout << "ching" << endl;
			cin >> decision;
			Drop += 0.25;
			break;

		case '1':
			 {
				cout << "(nothing happens)" << endl;
				cin >> decision;
			}
			break;

		case '2':
			if (RDentyne >= 1 && Drop >= 0.50){
				cout << "A pack of Dentyne slides into view" << endl;
				cin >> decision;
				RDentyne -= 1;
			}
			else if (RDentyne >= 1 && Drop >= 0.50){
				cout << "You hear mechanical clanking, but no gum appears." << endl;
				cin >> decision;
			}
			else {
				cout << " (nothing happens)" << endl;
				cin >> decision;
			}

			break;

		case '3':if (RChiclets >= 1 && Drop >= 0.75){
			cout << "A pack of Chiclets slides into view" << endl;
			cin >> decision;
			RChiclets -= 1;
		}
				 else if (RChiclets < 1 && Drop >= 0.75){
					 cout << "You hear mechanical clanking, but no gum appears." << endl;
					 cin >> decision;

				 }
				 else{
					 cout << " (nothing happens)" << endl;
					 cin >> decision;
				 }



				 break;

		case '4':if (RCarefree >= 1 && Drop >= 1.00){
			cout << "A pack of Carefree slides into view" << endl;
			cin >> decision;
			RCarefree -= 1;
		}
				 else if (RCarefree < 1 && Drop >= 1.00){
					 cout << "You hear mechanical clanking, but no gum appears." << endl;
					 cin >> decision;
				 }
				 else {
					 cout << " (nothing happens)" << endl;
					 cin >> decision;
				 }

				 break;

		case 'r':
		case 'R':
			
			cout << "  A grouchy-looking attendant shows up, opens the back, fiddles around a bit, closes it, and leaves." << endl;
			cin >> decision;
			{

			while (decision == 's' || decision =='S'){
				balance = 0.00;


				cout << "1: " << Beemans << " packs of Beemans " << endl;
				cout << "2: " << Dentyne << " packs of Dentyne " << endl;
				cout << "3: " << Chiclets << " packs of Chiclets " << endl;
				cout << "4: " << Carefree << " packs of Carefree " << endl;
				cout << "There is $ " << balance << " in the machine " << endl;
				cin >> decision;
				balance += Drop;
			}
			while (decision != 'Q' && decision != 'q'){
				cout << "S0 long" << endl;
				
			}

			}
		



			break;

		case 'q':
		case 'Q':
			cout << "So long!" << endl;
			break;

		default:
			cout << "I do not understand" << endl;
			break;




		}



	}











	return 0;
}

