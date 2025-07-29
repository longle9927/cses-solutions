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
vector<int> g[N];
ll dp[N];
int dep[N];
int con[N];
void dfs0(int u=1,int p=-1)
{
    con[u]=1;
    for(int v:g[u])
    {
        if(v==p)continue;
        dep[v]=dep[u]+1;
        dfs0(v,u);
        con[u]+=con[v];
    }
}
void dfs(int u=1,int p=-1)
{
    for(int v:g[u])
    {
        if(v==p) continue;
        dp[v]=dp[u]+n-2*con[v];
        dfs(v,u);
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
    int u,v;
    F(i,2,n,1)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    clock_t begin = clock();
    //code:
    dfs0();
    F(i,2,n,1) dp[1]+=dep[i];
    dfs();
    F(i,1,n,1) cout<<dp[i]<<' ';
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}