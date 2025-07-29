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
int n,t;
vector<int> g[N];
int dep[N];
int up[22][N];
void dfs(int u=1)
{
    F(k,1,18,1) up[k][u]=up[k-1][up[k-1][u]];
    for(int v:g[u])
    {
        dep[v]=dep[u]+1;
        up[0][v]=u;
        dfs(v);
    }
}
int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    fo(k,18,0,1)
        if(dep[u]-(1<<k)>=dep[v]) u=up[k][u];
    if(u==v) return u;
    fo(k,18,0,1)
        if(up[k][u]!=up[k][v]) u=up[k][u],v=up[k][v];
    return up[0][u];
}
void process()
{
    int u,v;cin>>u>>v;
    cout<<lca(u,v);el;
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
    cin>>n>>t;
    int x;
    F(i,2,n,1) cin>>x,g[x].pb(i);
    clock_t begin = clock();
    //code:
    dfs();
    while(t--) process();
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}