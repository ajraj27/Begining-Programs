#include<iostream>
using namespace std;

int main()
{
	int t,a,b,max=0,winner,lead_player,lead,player1=0,player2=0;

	cin>>t;

	while(t--)
	{
		cin >> a >> b;

		player1=player1+a;
		player2=player2+b;

		lead=player1-player2;
		lead_player=1;

		if(lead<0)
		{
			lead=lead*(-1);
			lead_player=2;
		}

		if(lead>max)
		{
			max=lead;
			winner=lead_player;
		}

	}

	cout << winner <<" "<<max;


}