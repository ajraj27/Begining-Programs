#include<bits/stdc++.h>
using namespace std;

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
            return a.ansStr > b.ansStr;
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

float calcHeuristic(vector < vector < string > > &state, 
                  unordered_map < string, pair < int, int > > &goalPosition) {
    int m = state.size();
    int n = state[0].size();
    float h = 0.0;
    string roll;
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
        roll = state[i][j];
        int di = goalPosition[roll].first;
        int dj = goalPosition[roll].second;
        if(di == i) h += abs(dj - j);
        else h += min(abs(0-j)+abs(di-i)+abs(dj-0), abs(n-1-j)+abs(di-i)+abs(n-dj-1) );
    }
    return h/2.0;
}

vector < myNode > actions(myNode &curNode, unordered_map < string, pair < int, int > > &goalPosition) {
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
            n.h = calcHeuristic(n.state, goalPosition);
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
            n.h = calcHeuristic(n.state, goalPosition);
            n.f = n.g + n.h;
            children.push_back(n);
            swap(curNode.state[i][j], curNode.state[i][j+1]);
        }
    }
    return children;
}

string AStar(vector < vector < string > > &sourceState,
            vector < vector < string > > &goalState) {
    if(makeString(sourceState) == makeString(goalState)) return "";
    
    string goalStr = makeString(goalState);
    unordered_map < string, pair < int, int > > goalPosition;
    int m = goalState.size();
    int n = goalState[0].size();
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
        goalPosition[goalState[i][j]] = make_pair(i,j);
    }
    myNode sourceNode(sourceState, "",0);
    sourceNode.h = calcHeuristic(sourceState, goalPosition);
    sourceNode.f = sourceNode.g + sourceNode.h;
    
    unordered_set < string > visited;
    priority_queue < myNode, vector < myNode > , compareNode > statesQueue;
    statesQueue.push(sourceNode);
    while(!statesQueue.empty() ){
        myNode curNode = statesQueue.top();
        statesQueue.pop();
        visited.insert(makeString(curNode.state));
        if(makeString(curNode.state) == goalStr) {
            return curNode.ansStr;
        }
        vector < myNode > neighbours = actions(curNode, goalPosition);
        vector < myNode > :: iterator it;
        for(it = neighbours.begin(); it != neighbours.end(); it++) {
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
        int m, n;
        cin >> m >> n ;
        vector < vector < string > > 
        sourceState( m, vector < string >(n)), 
        goalState(m, vector < string >(n));
        
        string roll;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> roll;
                sourceState[i][j] = roll;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> roll;
                goalState[i][j] = roll;
            }
        }
        string solution = AStar(sourceState, goalState); 
        cout << solution ;
    }
}
