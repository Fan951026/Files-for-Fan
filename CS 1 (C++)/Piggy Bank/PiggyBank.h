#ifndef PiggyBank_h
#define PiggyBank_h

class PiggyBank {
private:
	double start; int smash; double saving;
public:
	PiggyBank();
	PiggyBank(double);
	~PiggyBank();
	double getsaving();
	
	double getmoney();
	void setmoney(double);
	
	void getsmash();
	void getstart();
	void getcheck();
	double getmoney1();
	void setmoney1(double);
	double getmoney2();
	void setmoney2(double);
	double getmoney3();
	void setmoney3(double);
	double getmoney4();
	void setmoney4(double); 
	
};

#endif