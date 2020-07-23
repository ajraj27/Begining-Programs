//Course Schedule II - Leetcode

class Solution {
public:
    vector<int> g[100005];
    int vis[100005]={0};
    vector<int> ans;
    
    void dfs(int u){
        vis[u]=1;
        for(int v:g[u]){
            if(!vis[v]) dfs(v);
        }
        
        ans.push_back(u);
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n=numCourses;
        
        for(auto eq : prerequisites){
            g[eq[1]].push_back(eq[0]);
        }
        
        for(int i=0;i<n;i++) if(!vis[i]) dfs(i);
        
        reverse(ans.begin(),ans.end());

        // Chcking for cycle
        map<int,int> m;
        for(int i=0;i<n;i++) m[ans[i]]=i;
        
        bool bad=false;
        for(int i=0;i<n;i++) for(int j:g[i]) if(m[i]>m[j]) bad=true;
        if(bad) return {};
        ////


        // If not cycle, return ans;
        return ans;
        
        
        
    }
};