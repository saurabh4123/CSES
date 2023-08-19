#include<bits/stdc++.h>
using namespace std;
int n,m;
bool valid(int i,int j,string g[])
{
    if(i>=0 && j>=0 && i<n && j<m && g[i][j]=='.' )
    return true;
    return false;
}
void dfs(int i,int j,string g[])
{
    g[i][j]='#';
    if(valid(i+1,j,g))
        dfs(i+1,j,g);
    if(valid(i-1,j,g))
        dfs(i-1,j,g);
    if(valid(i,j+1,g))
        dfs(i,j+1,g);
    if(valid(i,j-1,g))
        dfs(i,j-1,g);    
}

int main()
{
    cin>>n>>m;
    string g[n];
    for(int i=0;i<n;i++)
    cin>>g[i];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(g[i][j]=='.')
            {
                dfs(i,j,g);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}