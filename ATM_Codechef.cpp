#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int withdraw;
	float amt;
	cin >> withdraw >> amt;

	if(withdraw%5==0 && amt>=withdraw+0.5)
		cout<<fixed<<setprecision(2)<<amt-(withdraw+0.5);

	else
		cout<<fixed<<setprecision(2)<<amt;

	return 0;
}