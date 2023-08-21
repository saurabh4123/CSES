#include<bits/stdc++.h>

using namespace std;
void dfs(int i,vector<int> &vis,vector<int> adj[])
{
    vis[i]=1;
    for(auto x:adj[i])
    if(vis[x]==0)
    dfs(x,vis,adj);
}
int main()
{
    int c,r;
    cin>>c>>r;
    vector<int> adj[c];
    for(int i=0;i<r;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(c,0);
    int comp=0;
    vector<int> temp;
    for(int i=0;i<c;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,vis,adj);
            comp++;
            temp.push_back(i);
        }
    }
    cout<<comp-1<<endl;
    for(int i=0;i<(int)temp.size()-1;i++)
    {
        cout<<temp[i]+1<<" "<<temp[i+1]+1<<endl;
    }
    return 0;
}