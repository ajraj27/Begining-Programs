#include<bits/stdc++.h>
using namespace std;


/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete below methods*/
/*inserts an element x at 
the back of the vector A */
void add_to_vector(vector<int> &A,int x)
{
	A.push_back(x);
}
/*sort the vector A in ascending order*/
void sort_vector_asc(vector<int> &A)
{
	sort(A.begin(),A.end());
}
/*reverses the vector A*/
void reverse_vector(vector<int> &A)
{
	reverse(A.begin(),A.end());
}
/*returns the size of the vector  A */
int size_of_vector(vector<int> &A)
{
	return A.size();
}
/*sorts the vector A in descending order*/
void sort_vector_desc(vector<int> &A)
{
	sort(A.rbegin(),A.rend());
}
/*prints space separated 
elements of vector A*/
void print_vector(vector<int> &A)
{
    int i;
	for(i=0;i<A.size();i++)
	    cout << A[i] << " " ;
}


int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		vector<int> A;
		int q;
		cin >> q;

		while(q--)
		{
			char ch;
			cin >> ch;

			if(ch=='a')
			{
				int num;
				cin >> num;
				add_to_vector(A,num);

			}

			else if(ch=='b')
				sort_vector_asc(A);

			else if(ch=='c')
				reverse_vector(A);

			else if(ch=='d')
				cout << size_of_vector(A) << " ";

			else if(ch=='e')
				print_vector(A);

			else
				sort_vector_desc(A); 
					 
		}

		cout << endl;
	}
}