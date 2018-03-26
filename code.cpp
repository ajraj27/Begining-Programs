#include<iostream>
using namespace std;

int main()
{
	int t,red,green;
	float ans;

	cin >> t;

	while(t--)
	{
		cin >> red >> green;

		if(red==0 && green==0)
			ans=1;
		else{
		ans=red/(red+green);
	}

	cout << fixed << setprecision(6)<<ans<<endl;
	}

}