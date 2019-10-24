    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define M 1000000007
    #define ull unsigned long long s
    #define pb push_back
    #define mp make_pair
    struct node
    {
        string srt;
        vector< vector< string > >vc;
        int count;
        float hur_cost;
    };
    bool sortby ( node &a, node &b )
    {
        return a.srt < b.srt;
    }
    struct CompareDist { 
    	bool operator()(node const& p1, node const& p2) 
    	{
    	    if(p1.hur_cost == p2.hur_cost)
    		    return p1.srt > p2.srt; 
    		else
    		   return  p1.hur_cost > p2.hur_cost;
    		 
    	} 
    }; 
    string makeString(vector < vector < string > > &a) {
        int m, n;
        m = a.size();
        n = a[0].size();
        string str = "";
        for(int i = 0; i < m; i++) 
        {
           for(int j = 0; j < n; j++)
            {
                str = str + a[i][j];
            }  
        }
       
        return str;
    }
    bool equal(vector <vector <string> > &a, vector < vector < string > > &b) {
        int m = a.size();
        int n = a[0].size();
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
            if(a[i][j] != b[i][j]) return false;
        }
        return true;
    }
    int huer(vector <vector <string> > &a, vector < vector < string > > &b)
    {
        int m = a.size();
        int n = a[0].size();
        map<string, pair<int, int> > m1;
        map<string, pair<int, int> >m2;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                m1[a[i][j]] = mp(i,j);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                m2[b[i][j]] = mp(i,j);
            }
        }
        float ans=0;
        map<string, pair<int , int> >::iterator itr;
        for (itr = m1.begin(); itr != m1.end(); ++itr)
        { 
           int x2 = m2[itr->first].first;
           int y2 = m2[itr->first].second;
           int x = itr->second.first;
           int y = itr->second.second;
           ans = ans + abs(x-x2)+abs(y-y2);
        } 
        ans =ans/2;
        return ans;
    }
    int main()
    {
        int t;
        cin >>t;
        for(int i=0;i<t;i++)
        {
            int ans;
            int m,n;
            cin >>m>>n;
            string sr;
            string sh="";
            string dh="";
            vector< vector < string > >src;
            vector< vector < string > >dest;
            for(int j=0;j<m;j++)
            {
               vector<string>v;
               for(int k=0;k<n;k++)
               {
                   cin >>sr;
                   v.push_back(sr);
                   sh = sh+sr+" ";
               }
               src.push_back(v);
           
            }
           for(int j=0;j<m;j++)
           {
               vector<string>v;
               for(int k=0;k<n;k++)
               {
                   cin >>sr;
                   v.push_back(sr);
                   dh = dh+sr+" ";
               }
               dest.push_back(v);
           }
            set<string>st;
            set < string > :: iterator it;
            node s;
            s.srt = "";
            s.vc = src;
            s.count = 0;
            s.hur_cost = huer(src,dest);
            priority_queue<node, vector<node>, CompareDist> q;
            q.push(s);
            int flag = 1;
            while(!q.empty())
                {
                    vector<vector<string> >dad;
                    vector<node>swp;
                    node ns = q.top();
                    st.insert(makeString(ns.vc));
                    q.pop();
                    dad= ns.vc;
                    for(int j=0;j<m;j++)
            	    {
            	        for(int k=0;k<n;k++)
            	        {
            	           if(k==0)
            	           {
            	               if(j==m-1)
            	               {
            	                   swap(dad[j][k],dad[j][k+1]);
            	                   it = st.find(makeString(dad));
            	                   if(it == st.end())
            	                   {
            	                       node s1;
            	                       string roll1 = min(dad[j][k],dad[j][k+1]);
            	                       string roll2 = max(dad[j][k],dad[j][k+1]);
            	                       s1.srt = ns.srt +"swap"+" "+roll1+" "+roll2+"\n";
                                       s1.vc = dad;
                                       s1.count = ns.count +1;
                                       s1.hur_cost = huer(dad,dest) + s1.count;
            	                       swp.push_back(s1);
            	                   } 
            	                   swap(dad[j][k],dad[j][k+1]);
            	               }
            	               else
            	               {
            	                   swap(dad[j][k],dad[j][k+1]);
            	                   it = st.find(makeString(dad));
            	                   if(it == st.end())
            	                   {
            	                       node s1;
                                       string roll1 = min(dad[j][k],dad[j][k+1]);
            	                       string roll2 = max(dad[j][k],dad[j][k+1]);
            	                       s1.srt = ns.srt +"swap"+" "+roll1+" "+roll2+"\n";    
            	                       s1.count = ns.count +1;
                                       s1.hur_cost = huer(dad,dest) + s1.count;
                                       s1.vc = dad;
            	                        
            	                       swp.push_back(s1);
            	                   } 
            	                   swap(dad[j][k],dad[j][k+1]);
            	                   swap(dad[j][k],dad[j+1][k]);
            	                   it = st.find(makeString(dad));
            	                   if(it == st.end())
            	                   {
            	                       node s1;
                                       string roll1 = min(dad[j][k],dad[j+1][k]);
            	                       string roll2 = max(dad[j][k],dad[j+1][k]);
            	                       s1.srt = ns.srt +"swap"+" "+roll1+" "+roll2+"\n"; 
            	                       s1.count = ns.count +1;
                                       s1.hur_cost = huer(dad,dest) + s1.count;
            	                       s1.vc = dad;
            	                        
            	                       swp.push_back(s1);
            	                   } 
            	                   swap(dad[j][k],dad[j+1][k]);
            	                   
            	               }
            	           }
            	           else if(k==n-1)
            	           {
            	               if(j==m-1)
            	               {
            	                   continue;
            	               }
            	               else
            	               {
            	                   swap(dad[j][k],dad[j+1][k]);
            	                   it = st.find(makeString(dad));
            	                   if(it == st.end())
            	                   {
            	                       node s1;
                                       string roll1 = min(dad[j][k],dad[j+1][k]);
            	                       string roll2 = max(dad[j][k],dad[j+1][k]);
            	                       s1.srt = ns.srt +"swap"+" "+roll1+" "+roll2+"\n"; 
            	                       s1.count = ns.count +1;
                                       s1.hur_cost = huer(dad,dest) + s1.count;
            	                       s1.vc = dad;
            	                       swp.push_back(s1);
            	                   } 
            	                   swap(dad[j][k],dad[j+1][k]);
                	                
            	               }
            	           }
            	           else
            	           {
            	                 swap(dad[j][k],dad[j][k+1]);
            	                 it = st.find(makeString(dad));
            	                 if(it == st.end())
            	                   {
            	                       node s1;
                                       string roll1 = min(dad[j][k],dad[j][k+1]);
            	                       string roll2 = max(dad[j][k],dad[j][k+1]);
            	                       s1.srt = ns.srt +"swap"+" "+roll1+" "+roll2+"\n";
            	                       s1.count = ns.count +1;
                                       s1.hur_cost = huer(dad,dest) + s1.count;
            	                       s1.vc = dad;
            	                       swp.push_back(s1);
            	                   } 
            	                   swap(dad[j][k],dad[j][k+1]);   
            	           }
            	        }
            	    }
            	      sort(swp.begin(), swp.end(), sortby);
            	      for(int j=0;j<swp.size();j++)
            	      {
            	          if(equal(swp[j].vc,dest))
            	          {
            	              flag = 0;
            	              cout<<swp[j].srt; 
            	              break;
            	          }
            	          else
            	          {
            	               q.push(swp[j]);   
            	          }
            	      }
            	    if(flag==0)
            	    {
            	        break;
            	    }
                }
           
     }
    } 