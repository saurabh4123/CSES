#include<bits/stdc++.h>
using namespace std;
int main()
{
    int comp,conn;
    cin>>comp>>conn;
    vector<int> adj[comp];
    for(int i=0;i<conn;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(comp,-1);
    int s=0,d=comp-1;
    queue<int> q;
    q.push(0);
    vis[0]=0;
    vector<int> ans;
    while(q.size()!=0)
    {
        int qf=q.front();
        q.pop();
        if(qf==d)
        {
            ans.push_back(d);
            while(vis[qf]!=qf)
            {
                ans.push_back(vis[qf]);
                qf=vis[qf];
            }
            break;
        }
        for(auto x:adj[qf])
        {
            if(vis[x]==-1)
            {
                vis[x]=qf;
                q.push(x);
            }
        }
    }
    if(ans.size()==0)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=0;i--)
    cout<<ans[i]+1<<" ";
    cout<<endl;
    return 0;
}