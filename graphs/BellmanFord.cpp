
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestDistanceBellmanFord(int src,int n,vector<pair<int,int> > list[]){
    vector<int> distance(n+1,INT_MAX);
    vector<bool> onqueue(n+1,false);
    distance[src]=0;

    queue<int> q;
    q.push(src);
    onqueue[src]=true;

    while(!q.empty()){
    	int u=q.front();
    	q.pop();
    	onqueue[u]=false;

    	for(auto x:list[u]){
    		int v=x.first;
    		int weight=x.second;

    		if(distance[v]>distance[u]+weight){
    			distance[v]=distance[u]+weight;
    			if(!onqueue[v]){
    				q.push(v);
    				onqueue[v]=true;
    			}
    		}

    	}

    }

    return distance;
}

int main(){
    int n,e,u,v,w,src,t;
    cin >> t;

    while(t--){
        cin >> n >> e;

        vector<pair<int,int> > list[n+1];

        for(int i=0;i<e;i++){
            cin >> u >> v >> w;

           list[u].push_back(make_pair(v,w));
        }

        cin >> src;

        vector<int> dist=shortestDistanceBellmanFord(src,n,list);

        for(int i=1;i<=n;i++){
            if(i==src)
                continue;

            else if(dist[i]==INT_MAX)
                cout << -1 << " ";

            else
                cout << dist[i] << " ";    

        }

        cout << endl;

    }
    
}
