#include<bits/stdc++.h>
using namespace std;
int si,ei;
bool dfs(int i,vector<int> adj[],vector<int> &vis,int cp,vector<int> &par)
{
   
    vis[i]=1;
    par[i]=cp;
    for(auto x:adj[i])
    {
        if(vis[x]!=1)
        {
            if(dfs(x,adj,vis,i,par))
            return true;
        }
        else if(x!=cp)
        {
            si=x;
            ei=i;
            return true;
        }
    }
    return false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<int> vis(n,-1),par(n,-1);
    si=-1,ei=-1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==-1)
        {
            dfs(i,adj,vis,-1,par);
            if(si!=-1)
            {
                vector<int> ans;
                ans.push_back(si);
                while(ei!=si)
                {
                    ans.push_back(ei);
                    ei=par[ei];
                }
                ans.push_back(si);
                cout<<ans.size()<<endl;
                for(auto i:ans)
                cout<<i+1<<" ";
                return 0;
            }
        }        
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}