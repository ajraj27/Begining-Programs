#include<bits/stdc++.h>
using namespace std;
#define DOST pair < string, string>
struct myNode {
    vector < vector < string > > state;
    string ansStr;
    unordered_map < string, int > moves;
    int cost;
    myNode(vector < vector < string > > &newState, string ans,
            unordered_map < string, int > &mv, int cs) {
        state = newState;
        ansStr = ans;
        moves = mv;
        cost = cs;
    }
};
 

bool compareNode(myNode &a, myNode &b) {
    return a.ansStr < b.ansStr;
}

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

vector < myNode > actions(myNode &curNode, int cost) {
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
            myNode n(curNode.state, swapStr, curNode.moves, curNode.cost);
            //add movesCost for roll1 and roll2
            n.moves[roll1]++;
            n.moves[roll2]++;
            n.cost += n.moves[roll1] + n.moves[roll2];
            //check constraint on moves
            if(n.cost <= cost)
                children.push_back(n);
            swap(curNode.state[i][j], curNode.state[i+1][j]);
        }
        if(j >= 0 && j < n-1 ) {
            roll1 = curNode.state[i][j];
            roll2 = curNode.state[i][j+1];
            if(roll1 > roll2) swap(roll1, roll2);
            swapStr = curNode.ansStr + "swap " + roll1 + " " + roll2 + "\n";  
            swap(curNode.state[i][j], curNode.state[i][j+1]);
            myNode n(curNode.state, swapStr, curNode.moves, curNode.cost);
            //add movesCost for roll1 and roll2
            n.moves[roll1]++;
            n.moves[roll2]++;
            n.cost += n.moves[roll1] + n.moves[roll2];
            //check constraint on moves
            if(n.cost <= cost)
                children.push_back(n);
            swap(curNode.state[i][j], curNode.state[i][j+1]);
        }
    }
    sort(children.begin(), children.end(), compareNode);
    return children;
}

bool checkConstraints(vector < vector < string > > &state, vector < DOST > &friends) {
    int m = state.size();
    int n = state[0].size();
    int sz = friends.size();
    for(int k = 0; k < sz; k++) { 
        string roll1, roll2;
        roll1 = friends[k].first;
        roll2 = friends[k].second;
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
            if(state[i][j] == roll1) {
                if(j-1 >= 0 && state[i][j-1] == roll2) return false;
                if(j+1 < n  && state[i][j+1] == roll2) return false;
            }
        }
    }
    return true;
}

string BFS(vector < vector < string > > &sourceState,
            vector < DOST > &friends, int cost) {
    if(checkConstraints(sourceState, friends)) return "";
    
    unordered_map < string, int > moves;
    myNode sourceNode(sourceState, "", moves,0);
    sourceNode.cost = 0;
    
    string ansStr = "";
    unordered_set < string > visited;
    queue < myNode > statesQueue;
    statesQueue.push(sourceNode);
    while(!statesQueue.empty() ){
        myNode &curNode = statesQueue.front();
        visited.insert(makeString(curNode.state));
        vector < myNode > neighbours = actions(curNode, cost);
        vector < myNode > :: iterator it;
        for(it = neighbours.begin(); it != neighbours.end(); it++) {
            string stateStr = makeString(it->state);
            if(visited.find(makeString(it->state)) == visited.end()) {
                if(checkConstraints(it->state, friends)) {
                    if(cost > it->cost) {
                        cost = it->cost;
                        ansStr = it->ansStr;
                    }
                    if(cost == it->cost ) {
                        if(ansStr > it->ansStr) ansStr = it->ansStr; 
                    }
                }
                else statesQueue.push(*it);
            }
        }
        statesQueue.pop();
    }
    return ansStr;
}

int main() {
    int testCase;
    cin >> testCase;
    while(testCase--) {
        int m, n, k, f;
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
        string solution = BFS(sourceState, friends, INT_MAX); 
        cout << solution;
    }
}