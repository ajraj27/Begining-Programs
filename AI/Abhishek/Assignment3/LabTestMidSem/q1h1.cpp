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

int calcHeuristic(myNode &node, vector < position > &goals) {
    // cout << "YES heur" << endl; 
	int minH = 1e9;
	int sz = goals.size();
	for(int i = 0; i < sz; i++) {
		minH = min(minH, abs(node.p.first - goals[i].first) + abs(node.p.second - goals[i].second));
	}
	return minH;
}

// int calcHeuristic(myNode &node, position goal) {
//     return abs(node.p.first - goal.first) + abs(node.p.second - goal.second);
// }

struct compareNode {
	bool operator()( myNode &a, myNode &b) {
		if(a.f != b.f) return a.f > b.f;
		return a.path > b.path;
	}
};

vector< myNode > getNeighbours(myNode &curNode, graph &g, vector < position> &goals) {
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
		n.h = calcHeuristic(n, goals);
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
		n.h = calcHeuristic(n, goals);
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
		n.h = calcHeuristic(n, goals);
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
		n.h = calcHeuristic(n, goals);
		n.f = n.g + n.h;
		neighbours.push_back( n);
	}
	return neighbours;
}

string AStar(graph &g, position &source, vector < position > &goals) {
	if(g[source.first][source.second] == 0) return "NIL";
	// string sPos = to_string(source.first) + " " + to_string(source.second) + "\n";
	string sPos = to_string(source.first) + "-" + to_string(source.second) + " ";
	myNode sourceNode(source, "", 0, 1);
	sourceNode.h = calcHeuristic(sourceNode, goals);
	sourceNode.f = sourceNode.g + sourceNode.h;
	//Algo
	priority_queue < myNode, vector < myNode >, compareNode > statesQueue;
	set < position > visited;
	statesQueue.push(sourceNode);
	while(!statesQueue.empty()) {
		myNode curNode = statesQueue.top();
		statesQueue.pop();
		visited.insert(curNode.p);
		if(curNode.h == 0) return curNode.ansStr;
		vector < myNode > neighbours = getNeighbours(curNode, g, goals);
		int sz = neighbours.size();
		for(int i = 0; i < sz; i++) {
			if(visited.find(neighbours[i].p) == visited.end()) {
				statesQueue.push(neighbours[i]);
			}
		}
	}
	return "NIL";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int m, n;
		cin >> m >> n;
		graph g( m , vector < int > (n) );
		vector < position > goals;
		for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
			cin >> g[i][j];
			if(g[i][j] == 2) {
				goals.push_back({i, j});
			} 
		}
		int x, y;
		cin >> x >> y;
		position source = {x,y};
		string solution = AStar(g, source, goals );
		cout << solution;
	}
}

