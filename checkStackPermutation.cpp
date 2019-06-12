#include<bits/stdc++.h>
using namespace std;

bool permutationPossible(int input[],int output[],int n){
	stack<char> s;
	queue<char> inp;
	queue<char> out;
	
	for(int i=0;i<n;i++){
		inp.push(input[i]);
		out.push(output[i]);
	}

	while(!inp.empty()){
		int el=inp.front();
		inp.pop();

		if(el==out.front()){
			out.pop();
			while(!s.empty()){
				if(s.top()==out.front()){
					s.pop();
					out.pop();
				}
				else
					break;
			}
		}
		else
			s.push(el);
	}

	return inp.empty() && s.empty();


}



int main(){
	int n;
	cin >> n;

	int input[n],output[n];

	for(int i=0;i<n;i++)
		cin >> input[i];

	for(int i=0;i<n;i++)
		cin >> output[i];

	cout << permutationPossible(input,output,n);
}