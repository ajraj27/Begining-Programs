#include<bits/stdc++.h>
#define graph vector < vector < int > > 
#define position pair < int, int >

using namespace std;

struct myNode {

	position p;
	string ansStr;
	string path;
	int g, h, f;
	myNode(position x ,string ans, int G, string pth) {
		p = x;
		ansStr = ans;
		g = G;
		path = pth;
	}
	position up() {
		return { p.first - 1, p.second};
	}
	position down() {
		return { p.first + 1, p.second};
	}
	position right() {
		return { p.first, p.second + 1};
	}
	position left() {
		return { p.first, p.second - 1};
	}
};

// int calcHeuristic(myNode &node, vector < position > &goals) {
//     // cout << "YES heur" << endl; 
// 	int minH = 1e9;
// 	int sz = goals.size();
// 	for(int i = 0; i < sz; i++) {
// 		minH = min(minH, abs(node.p.first - goals[i].first) + abs(node.p.second - goals[i].second));
// 	}
// 	return minH;
// }

int calcHeuristic(myNode &node, position goal) {
    return abs(node.p.first - goal.first) + abs(node.p.second - goal.second);
}

struct compareNode {
	bool operator()( myNode &a, myNode &b) {
		if(a.f != b.f) return a.f > b.f;
		return a.path > b.path;
	}
};

vector< myNode > getNeighbours(myNode &curNode, graph &g, position &goal) {
    // cout << "YES getNeighbours" << endl;
	int m = g.size();
	int n = g[0].size();
	vector < myNode > neighbours;
	if(curNode.up().first >= 0 && g[curNode.up().first][curNode.up().second] >= 1 ) {
	    stringstream stri, strj;
	    string i,j;
	    stri << curNode.up().first;
	    stri >> i;
	    strj << curNode.up().second;
	    strj >> j;
// 		string ansStr = curNode.ansStr + i + " " + j + "\n";
		string ansStr = curNode.ansStr + i + "-" + j + "U" + " ";

		string path = curNode.path + "A";
		myNode n(curNode.up(), ansStr, curNode.g+1, path);
		n.h = calcHeuristic(n, goal);
		n.f = n.g + n.h;
		neighbours.push_back( n);
	} 

	if(curNode.right().second < n && g[curNode.right().first][curNode.right().second] >= 1) {
		stringstream stri, strj;
	    string i,j;
	    stri << curNode.right().first;
	    stri >> i;
	    strj << curNode.right().second;
	    strj >> j;
// 		string ansStr = curNode.ansStr + i + " " + j  + "\n";
		string ansStr = curNode.ansStr + i + "-" + j + "R" + " ";

	    string path = curNode.path + "B";
		myNode n(curNode.right(), ansStr, curNode.g+1, path);
		n.h = calcHeuristic(n, goal);
		n.f = n.g + n.h;
		neighbours.push_back( n);
	}

	if(curNode.down().first < m && g[curNode.down().first][curNode.down().second] >= 1) {
		stringstream stri, strj;
	    string i,j;
	    stri << curNode.down().first;
	    stri >> i;
	    strj << curNode.down().second;
	    strj >> j;
// 		string ansStr = curNode.ansStr + i + " " + j + "\n";
		string ansStr = curNode.ansStr + i + "-" + j + "D" + " ";
        string path = curNode.path + "C";
		myNode n(curNode.down(), ansStr, curNode.g+1,  path);
		n.h = calcHeuristic(n, goal);
		n.f = n.g + n.h;
		neighbours.push_back( n);
	}

	if(curNode.left().second >= 0 && g[curNode.left().first][curNode.left().second] >= 1) {
		stringstream stri, strj;
	    string i,j;
	    stri << curNode.left().first;
	    stri >> i;
	    strj << curNode.left().second;
	    strj >> j;
// 		string ansStr = curNode.ansStr + i + " " + j + "\n";
		string ansStr = curNode.ansStr + i + "-" + j + "L" + " ";

		string path = curNode.path + "D";
		myNode n(curNode.left(), ansStr, curNode.g+1, path);
		n.h = calcHeuristic(n, goal);
		n.f = n.g + n.h;
		neighbours.push_back( n);
	}
	return neighbours;
}

pair < string , string > AStar(graph &g, position &source, position goal) {
    string nil = "NIL";
    string null = "";
	if(g[source.first][source.second] == 0) return make_pair(nil, nil);
	//sourceNode
	stringstream stri, strj;
	string i, j;
	stri << source.first;
	stri >> i;
	strj << source.second;
	strj >> j;
// 	string sPos = i + " " + j + "\n";
	string sPos = i + "-" + j + "" + " ";
	if(g[source.first][source.second] == 2) return make_pair(null, sPos) ;
	myNode sourceNode(source, sPos, 0, "");//position{i,j}, ansString, g, pathPriority
	sourceNode.h = calcHeuristic(sourceNode, goal);
	sourceNode.f = sourceNode.g + sourceNode.h;
	//Algo
	priority_queue < myNode, vector < myNode >, compareNode > statesQueue;
	set < position > visited;
	// vector < pair < string, string > > ansList;
    // cout << "YES" << endl;
	statesQueue.push(sourceNode);
	while(!statesQueue.empty()) {
		myNode curNode = statesQueue.top();
		statesQueue.pop();
		cout << curNode.ansStr  << " ----- " << curNode.h  << " " << curNode.f << endl;
		visited.insert(curNode.p);
		if(curNode.h == 0) return {curNode.path, curNode.ansStr} ;
		vector < myNode > neighbours = getNeighbours(curNode, g, goal);
		int sz = neighbours.size();
		for(int i = 0; i < sz; i++) {
			if(visited.find(neighbours[i].p) == visited.end()) {
				statesQueue.push(neighbours[i]);
			}
		}
	}
	
	return make_pair(nil, nil);
}

bool compareAns(pair < string, string > &a, pair < string, string> &b){
    int al = a.first.length();
    int bl = b.first.length();
    if(al == bl) {
        return a.first < b.first;
    }
    return al < bl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int m, n, tmp;
		cin >> m >> n;
		graph g( m , vector < int > (n) );
		vector < position > goals;
		vector < pair < string, string > >  ansList;
		for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
		    cin >> tmp;
		    if(tmp == 2) {
		        goals.push_back({i, j});
		        g[i][j] = 1;
		    }
			else g[i][j] = tmp;
		}
		int x, y;
		cin >> x >> y;
		if(g[x][y] == 0) g[x][y] = 1;
		position p = {x,y};
		int sz = goals.size();
		int flag = 0;
// 		for(int i = 0; i < m; i++){
// 		    for(int j = 0; j  < n; j++) {
// 		        cout << g[i][j] << " " ;
// 		    }
// 		    cout << endl;
// 		}
		for(int i = 0; i < sz; i++) {
		  //  cout << "start main "  << i << endl;
		    g[goals[i].first][goals[i].second] = 2;
		  //  cout << "i j val" << endl;
		  //  cout << goals[i].first << " " << goals[i].second << " " <<  g[goals[i].first][goals[i].second] << endl;
		    pair < string, string > solution = AStar(g, p, goals[i] );
		    if(solution.first != "NIL") ansList.push_back(solution);
		    g[goals[i].first][goals[i].second] = 1;
		  //  cout << "i j val" << endl;
		  //  cout << goals[i].first << " " << goals[i].second << " " << g[goals[i].first][goals[i].second] << endl;
		  //  cout << "end main "  << i << endl;
		}
// 		for(auto it : ansList) {
// 		    cout << it.first << "---" << it.second << endl;
// 		}
		sort(ansList.begin(), ansList.end(), compareAns);
	    if(ansList.size() > 0) cout << ansList[0].second << endl;
	    else cout << "NIL" << endl;
		ansList.clear();
	}
}
