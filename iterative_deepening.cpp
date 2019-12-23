    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long int 
    #define M 1000000007
    #define ull unsigned long long s
    #define pb push_back
    #define mp make_pair
    struct node{
        string srt;
        vector< vector< string > >vc;
    };
    bool sortby ( node& a, node& b )
    {
        return a.srt < b.srt;
    }
    bool check(vector <vector <string> > &a, string s2,string s3) 
    {
        int m = a.size();
        int n = a[0].size();
             for(int j=0;j<m;j++)
    	        {
    	            for(int k=0;k<n;k++)
    	            {
    	                if(a[j][k] == s2)
    	                {
    	                    if(k==0)
    	                    {
    	                        if(j==0)
    	                        {
    	                            if(a[j][k+1] == s3)
        	                        {
        	                           return false;
         	                        }
    	                        }
    	                        else if(j==m-1)
    	                        {
    	                            if(a[j][k+1] == s3)
        	                        {
        	                            return false;
         	                        }
    	                        }
    	                        else{
    	                            if(a[j][k+1] == s3)
        	                        {
        	                            return false;
         	                        }
    	                        }
    	                    }
    	                    else if(k==n-1)
    	                    {
    	                        if(j==0)
    	                        {
    	                            if(a[j][k-1] == s3)
        	                        {
        	                            return false;
         	                        }
    	                        }
    	                        else if(j==m-1)
    	                        {
    	                            if(a[j][k-1] == s3)
        	                        {
        	                            return false;
         	                        }
    	                        }
    	                        else{
    	                            if(a[j][k-1] == s3)
        	                        {
        	                            return false;
         	                        }
    	                        }
    	                    }
    	                    else{
    	                        if(a[j][k-1] == s3)
    	                        {
    	                            return false;
     	                        }
     	                        else if(a[j][k+1] == s3)
     	                        {
     	                            return false;
     	                        }
    	                    }
    	                 
    	                }
    	                
    	            }
    	            
    	        }
    	        return true;
    }
    bool idfs(node& ns,vector < vector < string > > &src,int qu,vector < vector < string > > &query,int level)
    {
        int m, n,ind,j;
        m = src.size();
        n = src[0].size();
        int flag = 1,flg=1;
        if(level == 1)
        {
            for(int k=0;k<qu;k++)
           {
            	    string sr1 = query[k][0];
                    string sr2 = query[k][1];
                	if(check(src,sr1,sr2))
                	{
                         ind = j;
                         flag = 0;
                    }
                    else
                    {
                	    return false;
                    }
            }
            if(flag==0)
            {
                cout<<ns.srt;
                return true;
            }
        }
        else
        {
                vector<node>swp;
                vector<vector<string> >dad;
                dad = src;
                for(int j=0;j<m;j++)
            	    {
            	        for(int k=0;k<n;k++)
            	        {
            	           if(k==0)
            	           {
            	               if(j==m-1)
            	               {
            	                   swap(dad[j][k],dad[j][k+1]);
            	                  
            	                       node s1;
            	                       string roll1 = min(dad[j][k],dad[j][k+1]);
            	                       string roll2 = max(dad[j][k],dad[j][k+1]);
            	                       s1.srt = ns.srt +"swap"+" "+roll1+" "+roll2+"\n";
                                       s1.vc = dad;
            	                       swp.push_back(s1);
            	               
            	                   swap(dad[j][k],dad[j][k+1]);
            	               }
            	               else
            	               {
            	                   swap(dad[j][k],dad[j][k+1]);
            	                       node s1;
                                       string roll1 = min(dad[j][k],dad[j][k+1]);
            	                       string roll2 = max(dad[j][k],dad[j][k+1]);
            	                       s1.srt = ns.srt +"swap"+" "+roll1+" "+roll2+"\n";  
            	                       s1.vc = dad;
            	                       swp.push_back(s1);
            	                   swap(dad[j][k],dad[j][k+1]);
            	                   
            	                   swap(dad[j][k],dad[j+1][k]);
            	                       node s2;
                                       roll1 = min(dad[j][k],dad[j+1][k]);
            	                       roll2 = max(dad[j][k],dad[j+1][k]);
            	                       s2.srt = ns.srt +"swap"+" "+roll1+" "+roll2+"\n";
            	                       s2.vc = dad;
            	                       swp.push_back(s2);
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
            	                       node s1;
                                       string roll1 = min(dad[j][k],dad[j+1][k]);
            	                       string roll2 = max(dad[j][k],dad[j+1][k]);
            	                       s1.srt = ns.srt +"swap"+" "+roll1+" "+roll2+"\n";
            	                       s1.vc = dad;
            	                       swp.push_back(s1);
            	                   swap(dad[j][k],dad[j+1][k]);
                	                
            	               }
            	           }
            	           else
            	           {
            	                 swap(dad[j][k],dad[j][k+1]);
            	                       node s1;
                                       string roll1 = min(dad[j][k],dad[j][k+1]);
            	                       string roll2 = max(dad[j][k],dad[j][k+1]);
            	                       s1.srt = ns.srt +"swap"+" "+roll1+" "+roll2+"\n";
            	                       s1.vc = dad;
            	                       swp.push_back(s1);
            	                   
            	                   swap(dad[j][k],dad[j][k+1]);   
            	           }
            	        }
            	    }
            	     sort(swp.begin(), swp.end(), sortby);  
            	     for(int j=0;j<swp.size();j++)
            	     {
            	         if(idfs(swp[j],swp[j].vc,qu,query,level-1))
            	         {
            	             return true;
            	         }
            	         
            	     }
            	     return false;
        }
        
    }
    int main()
    {
        int t;
        cin >>t;	
        for(int i=0;i<t;i++)
        {
            node ans;
            int m,n,qu;
            cin >>m>>n;
            string sr;
            string str1,str2;
            vector< vector < string > >src;
            vector< vector < string > >query;
            for(int j=0;j<m;j++)
    	    {
    	        vector<string>v;
    	        for(int k=0;k<n;k++)
    	        {
    	            cin >>sr;
    	            v.push_back(sr);
    	        } 
    	        src.push_back(v);
    	    }
    	    cin >>qu;
    	    for(int j=0;j<qu;j++)
    	    {
    	        vector<string>v;
    	        cin>>str1;
    	        v.pb(str1);
    	        cin>>str2;
    	        v.pb(str2);
    	        query.pb(v);
    	    }
    	    node s;
            s.srt = "";
            s.vc = src;
    	    int max_depth = 10;
    	    for(int j=1;j<=max_depth;j++)
    	    {
    	       // cout<<j<<endl;
    	       if(idfs(s,src,qu,query,j))
    	       {
    	           break;
    	       }
    	    }
        }
    }