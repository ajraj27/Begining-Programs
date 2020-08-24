#include<bits/stdc++.h>
using namespace std;

class HashTable{
private:
	static const int tableSize=10;
	list<pair<int,int> > table[tableSize];

public:
	bool isempty(){
		int numOfElements=0;

		for(int i=0;i<tableSize;i++)
			numOfElements+=table[i].size();

		return numOfElements==0;
	}

	int hashFunction(int key){
		return key%tableSize;
	}

	void insertItem(int key,int val){
		int hashValue=hashFunction(key);

		bool keyExists=false;
		for(auto itr=table[hashValue].begin();itr!=table[hashValue].end();itr++){
			if(itr->first==key){
				keyExists=true;
				itr->second=val;
				break;
			}
		}

		if(!keyExists) table[hashValue].push_back({key,val});
	}

	void removeItem(int key){
		int hashValue=hashFunction(key);
		
		for(auto itr=table[hashValue].begin();itr!=table[hashValue].end();itr++){
			if(itr->first==key){
				itr=table[hashValue].erase(itr);
				break;
			}
		}
	}

	int search(int key){
		int hashValue=hashFunction(key);
		
		for(auto itr=table[hashValue].begin();itr!=table[hashValue].end();itr++){
			if(itr->first==key){
				return itr->second;
			}
		}

		return -1;
	}

	void printHashTable(){
		for(int i=0;i<tableSize;i++){
			if(table[i].size()==0) continue;

			for(auto itr=table[i].begin();itr!=table[i].end();itr++)
				cout << itr->first << " " << itr->second << endl;
		}
	}
};

int main(){
	HashTable h;
	cout << h.isempty() << endl;

	h.insertItem(1,10);
	h.insertItem(2,11);
	h.insertItem(3,12);
	h.insertItem(4,13);
	h.insertItem(5,14);

	h.printHashTable();

	h.removeItem(4);

	h.printHashTable();

}