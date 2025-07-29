#include<bits/stdc++.h>
using ll=long long;
const int N=3e3+5;
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
char a[N][N];
string ans="";
void bfs()
{
    queue<pii> q;
    q.push({1,1});
    ans+=a[1][1];
    while(q.size())
    {
        int x=q.size();
        int mi=1e9;
        vector<pii> res;
        while(x--)
        {
            auto [i,j]=q.front();q.pop();
            // cout<<i<<' '<<j;el;
            if(i==n&&j==n) return;
            if(i<n) mi=min(mi,(int)a[i+1][j]),res.pb({i+1,j});
            if(j<n) mi=min(mi,(int)a[i][j+1]),res.pb({i,j+1});
            
            
        }
        // cout<<char(mi);el;
        ans+=char(mi);
        for(auto [u,v]:res)
        {
            if((int)a[u][v]==mi) q.push({u,v});
        }
        // cout<<ans;el;
    }
    // cout<<ans;
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
    F(i,1,n,1) F(j,1,n,1) cin>>a[i][j];
    clock_t begin = clock();
    //code:
    bfs();
    cout<<ans;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}