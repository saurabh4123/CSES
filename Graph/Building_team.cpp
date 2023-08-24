#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(v,-1);
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(vis[i]==-1)
        {
            q.push(i);
            int val=1;
            vis[i]=val;
            while(q.size()!=0)
            {
                int s=q.size();
                val=val^3;
                while(s--)
                {
                    int x=q.front();
                    q.pop();
                    for(auto dd:adj[x])
                    {
                        if(vis[dd]==(val^3))
                        {
                            cout<<"IMPOSSIBLE"<<endl;
                            return 0;
                        }
                        else if(vis[dd]==-1)
                        {
                            vis[dd]=val;
                            q.push(dd);
                        }
                    }
                }
            }
        }
    }
    for(auto i:vis)
    cout<<i<<" ";
    cout<<endl;
    return 0;
}