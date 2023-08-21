#include<bits/stdc++.h>
using namespace std;
int n,m;
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
char dch[4]={'U','R','D','L'};
int main()
{
    cin>>n>>m;
    int sx,sy,ex,ey;
    vector<char> g[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='A')
            {
                sx=i,sy=j;
                ch='.';
            }
            if(ch=='B')
            {
                ex=i,ey=j;
                ch='.';
            }
            g[i].push_back(ch);
        }
    }
    string ans="";
    queue<pair<int,int>> q;
    q.push({sx,sy});
    g[sx][sy]='#';
    while(q.size()!=0)
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==ex && y==ey)
        {
            while(x!=sx || y!=sy)
            {
                ans.push_back(g[x][y]);
                if(g[x][y]=='R') y--;
                else if(g[x][y]=='U') x++;
                else if(g[x][y]=='D') x--;
                else  y++;
            }
            break;
        }
        for(int i=0;i<4;i++)
        {
            int nx=x+dr[i];
            int ny=y+dc[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && g[nx][ny]=='.')
            {
                q.push({nx,ny});
                g[nx][ny]=dch[i];
            }
        }
    }
    if(ans.size()==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }  
    reverse(ans.begin(),ans.end());
    cout<<"YES"<<endl;
    cout<<ans.length()<<endl;
    cout<<ans<<endl; 
    return 0;
}