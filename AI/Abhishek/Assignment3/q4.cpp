#include<bits/stdc++.h>
using namespace std;
#define DOST pair < string, string>
struct myNode {
    vector < vector < string > > state;
    string ansStr;
    int g;
    float h;
    float f;
    myNode(vector < vector < string > > &newState, string ans, int lvl) {
        state = newState;
        ansStr = ans;
        g = lvl;
    }
};
 
struct compareNode {
    bool operator()(const myNode &a, const myNode &b) {
        if(abs(a.f - b.f) < 0.000001) {
            return a.ansStr >= b.ansStr;
        }
        return a.f > b.f;
    }
};
 
string makeString(vector < vector < string > > &state) {
    int m, n;
    m = state.size();
    n = state[0].size();
    string str = "";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            str = str + state[i][j] + " ";
        }
    }
    return str;
}
 
float checkConstraints(vector < vector < string > > &state, 
                     vector < DOST > &friends) {
    int m = state.size();
    int n = state[0].size();
    int sz = friends.size();
    int ctr = 0, flag;
    for(int k = 0; k < sz; k++) { 
        string roll1, roll2;
        roll1 = friends[k].first;
        roll2 = friends[k].second;
        flag = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(state[i][j] == roll1) {
                    if(j-1 < 0 || state[i][j-1] != roll2) {
                        if(j+1 >= n || state[i][j+1] != roll2) {
                            ctr++;
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if(flag) break;
        }
    }
    return (sz - ctr)/2.0;
}
 
vector < myNode > actions(myNode &curNode, vector < DOST > &friends) {
    int m = curNode.state.size();
    int n = curNode.state[0].size();
    vector < myNode > children;
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
        string roll1, roll2, swapStr;
        if((j == 0 || j == n-1) && i+1 < m) {
            roll1 = curNode.state[i][j];
            roll2 = curNode.state[i+1][j];
            if(roll1 > roll2) swap(roll1, roll2);
            swapStr = curNode.ansStr + "swap " + roll1 + " " + roll2 + "\n";
            swap(curNode.state[i][j], curNode.state[i+1][j]);
            myNode n(curNode.state, swapStr, curNode.g + 1);
            n.h = checkConstraints(n.state, friends);
            n.f = n.g + n.h;
            children.push_back(n);
            swap(curNode.state[i][j], curNode.state[i+1][j]);
        }
        if(j >= 0 && j < n-1 ) {
            roll1 = curNode.state[i][j];
            roll2 = curNode.state[i][j+1];
            if(roll1 > roll2) swap(roll1, roll2);
            swapStr = curNode.ansStr + "swap " + roll1 + " " + roll2 + "\n";  
            swap(curNode.state[i][j], curNode.state[i][j+1]);
            myNode n(curNode.state, swapStr, curNode.g + 1);
            n.h = checkConstraints(n.state, friends);
            n.f = n.g + n.h;
            children.push_back(n);
            swap(curNode.state[i][j], curNode.state[i][j+1]);
        }
    }
    return children;
}
 
string AStar(vector < vector < string > > &sourceState,
            vector < DOST > &friends) {
    map < string, int > moves;
    if(checkConstraints(sourceState, friends) == 0) return "";
    
    myNode sourceNode(sourceState, "", 0);
    sourceNode.h = checkConstraints(sourceState, friends);
    sourceNode.f = sourceNode.g + sourceNode.h;
    string ansStr = "";
    unordered_set < string > visited;
    priority_queue < myNode, vector < myNode >, compareNode > statesQueue;
    statesQueue.push(sourceNode);
    while(!statesQueue.empty() ){
        myNode curNode = statesQueue.top();
        statesQueue.pop();
        visited.insert(makeString(curNode.state));
        if(curNode.h == 0) return curNode.ansStr;
        vector < myNode > neighbours = actions(curNode, friends);
        vector < myNode > :: iterator it;
        for(it = neighbours.begin(); it != neighbours.end(); it++) {
            // if(it->h == 0) return it->ansStr;
            string stateStr = makeString(it->state);
            if(visited.find(stateStr) == visited.end()) {
                statesQueue.push(*it);
            }
        }
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
        string solution = AStar(sourceState, friends); 
        cout << solution;
    }
}