//used visual studio 2013
//xuecong fan


#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void input(string answer, string answer1,double& num1);
void input2(string answer, string answer1, double& num2);
void input1(double& num1, double& num2);
void input3(double& num1);
void input4(double & num3);
void input5(double &num4);

int main(){
	ifstream fin;
	fin.open("triviaQuestions.txt");
	ifstream fout;
	fout.open("triviaAnswers.txt");
	ifstream score;
	score.open("highScores.txt");
	cout << "Welcome to the BioShock trivia game!" << endl;
	string answer;
	string answer1;
	string question;
	string scores;
	double num1=0;
	double num2=0;
	double num3=0;
	
	getline(fin, question);
	cout << question << endl;;
	input4(num3);

	getline(fin, question);
	cout<< question<<"\n";
	
	getline(cin, answer);
	getline(fout, answer1);
	input(answer, answer1, num1);
	input2(answer, answer1, num2);

	input4(num3);
	getline(fin, question);
	cout << "\n" << question<<"\n";
	getline(cin, answer);
	getline(fout, answer1);

	input(answer, answer1, num1);
	input2(answer, answer1, num2);

	input4(num3);
    getline(fin, question);
	cout << question << "\n";
    getline(cin, answer);
	getline(fout, answer1);
	input(answer, answer1, num1);
	input2(answer, answer1, num2);


	input4(num3);
	getline(fin, question);
	cout << question << "\n";
	getline(cin, answer);
	getline(fout, answer1);
	input(answer, answer1, num1);
	input2(answer, answer1, num2);


	input4(num3);
	getline(fin, question);
	cout << question << "\n";
	getline(cin, answer);
	getline(fout, answer1);
	input(answer, answer1, num1);
	input2(answer, answer1, num2);


	input4(num3);
	getline(fin, question);
	cout << question << "\n";
	getline(cin, answer);
	getline(fout, answer1);
	input(answer, answer1, num1);
	input2(answer, answer1, num2);


	input4(num3);
	getline(fin, question);
	cout << question << "\n";
	getline(cin, answer);
	getline(fout, answer1);
	input(answer, answer1, num1);
	input2(answer, answer1, num2);


	input4(num3);
	getline(fin, question);
	cout << question << "\n";
	getline(cin, answer);
	getline(fout, answer1);
	input(answer, answer1, num1);
	input2(answer, answer1, num2);


	input4(num3);
	getline(fin, question);
	cout << question << "\n";
	getline(cin, answer);
	getline(fout, answer1);
	input(answer, answer1, num1);
	input2(answer, answer1, num2);


	input4(num3);
	getline(fin, question);
	cout << question << "\n";
	getline(cin, answer);
	getline(fout, answer1);
	input(answer, answer1, num1);
	input2(answer, answer1, num2);






	input1(num1,num2);
	input3(num1);

	cout << "Current High Scores:\n" << endl;
	getline(score, scores);
	cout << scores<< endl;
	getline(score, scores);
	cout << scores  << endl;
	getline(score, scores);
	cout << scores  << endl;



	return 0;
}
void input(string answer,string answer1,double& num1){
	
	if (answer == answer1){
		
		num1 ++;
		cout << "That is correct! You currently have "<< num1<<" point." << endl;
		
		
		
	}
	else{
		
		cout << "I'm sorry, that is incorrect.You currently have " << num1<< "point." << endl;
		
	}
}
void input2(string answer, string answer1,double& num2){

	if (answer == answer1){
		
		num2++;
	}
	else{
		
		num2++;
	}
}
void input1(double& num1,double& num2){
	
	cout << "Final score: " << num1 / num2 * 100<<" %"<<" ( "<<num1<<"/ "<<num2<<"correct questions )"<< endl;
}
void input3(double & num1){
	if (num1 >= 8){
		cout << "Congratulation! You are in the high scores list." << endl;
	}
	else{
		cout << "You did not make it into the high scores list." << endl;
	}
	
}
void input4(double & num3){
	
	num3++;
		cout << "Question " << num3 << " :" << endl;
	
}
