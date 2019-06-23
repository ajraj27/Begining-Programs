
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestDistanceDijkstra(int src,int n,vector<pair<int,int> > list[]){
    vector<int> distance(n+1,INT_MAX);
    vector<bool> flag(n+1,false);
    distance[src]=0;

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push(make_pair(0,src));

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        if(!flag[u]){
            flag[u]=true;

            for(auto x: list[u]){
                int v=x.first;
                int weight=x.second;

                if(distance[v] > distance[u]+weight){
                    distance[v]=distance[u]+weight;
                    pq.push(make_pair(distance[v],v));
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
           list[v].push_back(make_pair(u,w));
           
        }

        cin >> src;

        vector<int> dist=shortestDistanceDijkstra(src,n,list);

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
