#include<bits/stdc++.h>
#define DOST pair < string , string >
using namespace std;
 
struct myNode {
    vector < vector < string > > state;
    string ansStr;
    int level;
    myNode(vector < vector < string > > &newState, string ans, int lvl) {
        state = newState;
        ansStr = ans;
        level = lvl;
    }
};
 
 
bool compareNode(const myNode &a, const myNode &b) {
    return a.ansStr < b.ansStr;
}
 
bool checkConstraints(vector < vector < string > > &state, vector < DOST > &friends) {
    int m = state.size();
    int n = state[0].size();
    int sz = friends.size();
    for(int k = 0; k < sz; k++) { 
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
            if(state[i][j] == friends[k].first) {
                if(j-1 >= 0 && state[i][j-1] == friends[k].second) return false;
                if(j+1 < n  && state[i][j+1] == friends[k].second) return false;
            }
        }
    }
    return true;
}
 
vector < myNode > nextPossibleStates(myNode &curNode) {
    int m, n;
    m = curNode.state.size();
    n = curNode.state[0].size();
    vector < myNode > children;
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
        string roll1, roll2, swapStr;
        if((j == 0 || j == n-1) && i+1 < m) {
            roll1 = curNode.state[i][j];
            roll2 = curNode.state[i+1][j];
            if(roll1 > roll2) swap(roll1, roll2);
            swapStr = curNode.ansStr + "swap " + roll1 + " " + roll2 + "\n";  
            swap(curNode.state[i][j], curNode.state[i+1][j]);
            myNode n(curNode.state, swapStr, curNode.level+1);
            children.push_back(n);
            swap(curNode.state[i][j], curNode.state[i+1][j]);
        }
        if(j >= 0 && j < n-1 ) {
            roll1 = curNode.state[i][j];
            roll2 = curNode.state[i][j+1];
            if(roll1 > roll2) swap(roll1, roll2);
            swapStr = curNode.ansStr + "swap " + roll1 + " " + roll2 + "\n";  
            swap(curNode.state[i][j], curNode.state[i][j+1]);
            myNode n(curNode.state, swapStr, curNode.level+1);
            children.push_back(n);
            swap(curNode.state[i][j], curNode.state[i][j+1]);
        }
    }
    sort(children.begin(), children.end(), compareNode);
    return children;
}
 
string DLS(myNode &curNode, vector < DOST > &friends, int limit) {
    if(limit ==0 && checkConstraints(curNode.state, friends) ) return curNode.ansStr;
 
    if(limit <= 0) return "no";
 
    vector < myNode > children = nextPossibleStates(curNode);
    int size = children.size();
    for(int i = 0; i < size; i++) {
        string solution = DLS(children[i], friends, limit-1);
        if( solution != "no") return solution;
    }
    return "no";
 
}
 
string IDDFS(vector < vector < string > >  &sourceState, vector < DOST > &friends) {
    int dmax = friends.size();
    string solution ;
    myNode sourceNode(sourceState, "", 0);
    for(int i = 0; i <= dmax; i++) {
        solution = DLS(sourceNode, friends, i);
        if(solution != "no") return solution;
    }
    return "";
}
 
int main() {
    int testCase;
    cin >> testCase;
    while(testCase--) {
        int m, n, f;
        cin >> m >> n ;
        vector < vector < string > > sourceState( m, vector < string >(n));
        vector < DOST > friends;
        string roll, roll1, roll2;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> roll;
                sourceState[i][j] = roll;
            }
        }
        cin >> f;
        for(int i = 0; i < f; i++) {
            cin >> roll1 >> roll2;
            friends.push_back(make_pair(roll1, roll2));
        }
        string solution = IDDFS(sourceState, friends); 
        cout << solution;
    }
}