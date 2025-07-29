#include<bits/stdc++.h>
using ll=long long;
const int N=1e6+5;
#define pii pair<int,int> //sua thanh ll khi can
#define fi first
#define se second
#define F(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fo(i,a,b,c) for(int i=a;i>=b;i-=c)
#define pb push_back
const int MOD=1e9+7;
#define el cout<<'\n'
using namespace std;
int n;
int a[1005][1005];
void bfs()
{
    memset(a,-1,sizeof(a));
    a[1][1]=0;
    queue<pii> q;
    q.push({1,1});
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        if(x+2<=n&&y+1<=n&&a[x+2][y+1]==-1)
        {
            a[x+2][y+1]=a[x][y]+1;
            q.push({x+2,y+1});
        }
        if(x+1<=n&&y+2<=n&&a[x+1][y+2]==-1)
        {
            a[x+1][y+2]=a[x][y]+1;
            q.push({x+1,y+2});
        }
        if(x-1>0&&y+2<=n&&a[x-1][y+2]==-1)
        {
            a[x-1][y+2]=a[x][y]+1;
            q.push({x-1,y+2});
        }
        if(x-2>0&&y+1<=n&&a[x-2][y+1]==-1)
        {
            a[x-2][y+1]=a[x][y]+1;
            q.push({x-2,y+1});
        }
        if(x-1>0&&y-2>0&&a[x-1][y-2]==-1)
        {
            a[x-1][y-2]=a[x][y]+1;
            q.push({x-1,y-2});
        }
        if(x-2>0&&y-1>0&&a[x-2][y-1]==-1)
        {
            a[x-2][y-1]=a[x][y]+1;
            q.push({x-2,y-1});
        }
        if(x+1<=n&&y-2>0&&a[x+1][y-2]==-1)
        {
            a[x+1][y-2]=a[x][y]+1;
            q.push({x+1,y-2});
        }
        if(x+2<=n&&y-1>0&&a[x+2][y-1]==-1)
        {
            a[x+2][y-1]=a[x][y]+1;
            q.push({x+2,y-1});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(".inp","r"))
    {
        freopen(".inp","r",stdin);
        freopen(".out","w",stdout);
    }
    //input:
    cin>>n;
    clock_t begin = clock();
    //code:
    bfs();
    F(i,1,n,1)
    {
        F(j,1,n,1)
        {
            cout<<a[i][j]<<" ";
        }
        el;
    }
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}