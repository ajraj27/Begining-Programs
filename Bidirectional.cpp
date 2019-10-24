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
    };
    bool sortby ( node &a, node &b )
    {
        return a.srt < b.srt;
    }
    string makeString(vector < vector < string > > &a) {
        int m, n;
        m = a.size();
        n = a[0].size();
        string str = "";
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) {
            str = str + a[i][j];
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
            queue <node> q;
            queue <node> qd;
            unordered_map<string, int> st;
            unordered_map<string, int> std;
            node s;
            s.srt = "";
            s.vc = src;
            s.count = 0;
            st.insert(mp((makeString(src)),s.count));
            node s1;
            s1.srt = "";
            s1.vc = dest;
            s1.count = 0;
            std.insert(mp((makeString(dest)),s1.count));
            unordered_map<string, int>:: iterator it;
            q.push(s);
            qd.push(s1);
            int flag=1,flg=1;
            if(equal(src,dest))
            {
                cout<<0<<endl;
            }
            else
            {
                while(!q.empty() && !qd.empty())
                {
                    vector<vector<string> >dad;
                    vector<vector<string> >daddy;
                    vector<node>swp;
                    vector<node>swpd;
                    node ns = q.front();
                    //cout<<ns.count<<endl;
                    node ns1 = qd.front();
                    //cout<<ns1.count<<endl;
                    q.pop();
                    qd.pop();
                    dad= ns.vc;
                    daddy = ns1.vc;
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
                                  s1.count = ns.count +1;
                                  s1.vc = dad;
                                  st.insert(mp((makeString(s1.vc)),s1.count));
                                  swp.push_back(s1);
                              }
                              swap(dad[j][k],dad[j][k+1]);
                             
                              swap(daddy[j][k],daddy[j][k+1]);
                              it = std.find(makeString(daddy));
                              if(it == std.end())
                              {
                                  node s1;
                                  string roll1 = min(daddy[j][k],daddy[j][k+1]);
                                  string roll2 = max(daddy[j][k],daddy[j][k+1]);
                                  s1.srt = ns1.srt +"swap"+" "+roll1+" "+roll2+"\n";
                                  s1.count = ns1.count +1;
                                  s1.vc = daddy;
                                  std.insert(mp((makeString(s1.vc)),s1.count));
                                  swpd.push_back(s1);
                              }
                              swap(daddy[j][k],daddy[j][k+1]);
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
                                  s1.vc = dad;
                                  st.insert(mp((makeString(s1.vc)),s1.count));
                                  swp.push_back(s1);
                              }
                              swap(dad[j][k],dad[j][k+1]);
                             
                              swap(daddy[j][k],daddy[j][k+1]);
                              it = std.find(makeString(daddy));
                              if(it == std.end())
                              {
                                  node s1;
                                  string roll1 = min(daddy[j][k],daddy[j][k+1]);
                                  string roll2 = max(daddy[j][k],daddy[j][k+1]);
                                  s1.srt = ns1.srt +"swap"+" "+roll1+" "+roll2+"\n";
                                  s1.count = ns1.count +1;
                                  s1.vc = daddy;
                                  std.insert(mp((makeString(s1.vc)),s1.count));
                                  swpd.push_back(s1);
                              }
                              swap(daddy[j][k],daddy[j][k+1]);
                             
                              swap(dad[j][k],dad[j+1][k]);
                              it = st.find(makeString(dad));
                              if(it == st.end())
                              {
                                  node s1;
                                  string roll1 = min(dad[j][k],dad[j+1][k]);
                                  string roll2 = max(dad[j][k],dad[j+1][k]);
                                  s1.srt = ns.srt +"swap"+" "+roll1+" "+roll2+"\n";  
                                  s1.vc = dad;
                                  s1.count = ns.count +1;
                                  st.insert(mp((makeString(s1.vc)),s1.count));
                                  swp.push_back(s1);
                              }
                              swap(dad[j][k],dad[j+1][k]);
                             
                              swap(daddy[j][k],daddy[j+1][k]);
                              it = std.find(makeString(daddy));
                              if(it == std.end())
                              {
                                  node s1;
                                  string roll1 = min(daddy[j][k],daddy[j+1][k]);
                                  string roll2 = max(daddy[j][k],daddy[j+1][k]);
                                  s1.srt = ns1.srt +"swap"+" "+roll1+" "+roll2+"\n";
                                  s1.count = ns1.count +1;
                                  s1.vc = daddy;
                                  std.insert(mp((makeString(s1.vc)),s1.count));
                                  swpd.push_back(s1);
                              }
                              swap(daddy[j][k],daddy[j+1][k]);
                             
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
                                  s1.vc = dad;
                                  st.insert(mp((makeString(s1.vc)),s1.count));
                                  swp.push_back(s1);
                              }
                              swap(dad[j][k],dad[j+1][k]);
                             
                              swap(daddy[j][k],daddy[j+1][k]);
                              it = std.find(makeString(daddy));
                              if(it == std.end())
                              {
                                  node s1;
                                  string roll1 = min(daddy[j][k],daddy[j+1][k]);
                                  string roll2 = max(daddy[j][k],daddy[j+1][k]);
                                  s1.srt = ns1.srt +"swap"+" "+roll1+" "+roll2+"\n";
                                  s1.count = ns1.count +1;
                                  s1.vc = daddy;
                                  std.insert(mp((makeString(s1.vc)),s1.count));
                                  swpd.push_back(s1);
                              }
                              swap(daddy[j][k],daddy[j+1][k]);
                               
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
                                  s1.vc = dad;
                                  st.insert(mp((makeString(s1.vc)),s1.count));
                                  swp.push_back(s1);
                              }
                              swap(dad[j][k],dad[j][k+1]);  
                             
                              swap(daddy[j][k],daddy[j][k+1]);
                            it = std.find(makeString(daddy));
                            if(it == std.end())
                              {
                                  node s1;
                                  string roll1 = min(daddy[j][k],daddy[j][k+1]);
                                  string roll2 = max(daddy[j][k],daddy[j][k+1]);
                                  s1.srt = ns1.srt +"swap"+" "+roll1+" "+roll2+"\n";
                                  s1.count = ns1.count +1;
                                  s1.vc = daddy;
                                  std.insert(mp((makeString(s1.vc)),s1.count));
                                  swpd.push_back(s1);
                              }
                              swap(daddy[j][k],daddy[j][k+1]);  
                      }
                   }
               }
              sort(swp.begin(), swp.end(), sortby);
              sort(swpd.begin(), swpd.end(), sortby);
             unordered_map<string, int>:: iterator itr;
             int flag=0;
              for(itr = st.begin(); itr != st.end(); itr++) 
              {
                    if(std.find(itr->first)!=std.end())
                    {
                        flag = 1;
                        ans = std[itr->first]+itr->second;
                        //cout<<st.size()<<endl;
                        cout<<ans<<endl;
                        break;
                    }
              }
              if(flag==1)
              {
                  break;
              }
              else
              {
                  for(int j=0;j<swp.size();j++)
                  {
                      q.push(swp[j]);
                  }
                  for(int j=0;j<swpd.size();j++)
                  {
                      qd.push(swpd[j]);
                  }
              }
            }
        }
    }
    } 