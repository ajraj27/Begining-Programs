    #include<bits/stdc++.h>
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
     
    vector < myNode > actions(myNode &curNode) {
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
     
    void BFS(queue < myNode > &statesQueue,
                unordered_map < string, int > &visited) {
        myNode &curNode = statesQueue.front(); // check syntax
        vector < myNode > neighbours = actions(curNode);
        vector < myNode > :: iterator it;
        for(it = neighbours.begin(); it != neighbours.end(); it++) {
            string stateStr = makeString(it->state);
            if(visited.find(stateStr) == visited.end()) {
                visited[stateStr] = it->level;
                statesQueue.push(*it);
            }
        }
        statesQueue.pop();
    }
     
    string ifIntersecting(unordered_map < string, int > &sVisited,
                    unordered_map < string, int > &gVisited) {
        unordered_map < string, int > :: iterator it, sEnd, gEnd;
        sEnd = sVisited.end();
        gEnd = gVisited.end();
        for(it = sVisited.begin(); it != sEnd; it++) {
            if(gVisited.find(it->first) != gEnd) {
                return it->first;
            }
        }
        return "no";
    }
     
    int biDirectionalSearch(vector < vector < string > > &sourceState, 
                            vector < vector < string > > &goalState) {
                                
        if(makeString(sourceState) == makeString(goalState)) return 0;// base condition
        myNode sourceNode(sourceState, "", 0);
        myNode goalNode(goalState, "", 0);
        unordered_map < string, int > sVisited, gVisited;
        queue < myNode > sQueue, gQueue;
        sVisited[makeString(sourceState)] =  0;
        gVisited[makeString(goalState)] =  0;
        sQueue.push(sourceNode);
        gQueue.push(goalNode);
        
        while(!sQueue.empty() && !gQueue.empty() ) {
            BFS(sQueue, sVisited);
            BFS(gQueue, gVisited);
            string key = ifIntersecting(sVisited, gVisited);
            int answer;
            if(key != "no") {
                answer = sVisited[key] + gVisited[key];
                return answer;
            }
        }
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
            int solution = biDirectionalSearch(sourceState, goalState); 
            cout << solution << endl;
        }
    }