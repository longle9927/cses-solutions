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
int up[22][N];
int dep[N];
void dfs(int u=1)
{
    F(i,1,18,1) up[i][u]=up[i-1][up[i-1][u]];
    for(int v:g[u])
    {
        up[0][v]=u;
        dep[v]=dep[u]+1;
        dfs(v);
    }
}
int bit(int mask,int i)
{
    return (mask>>i)&1;
}
int get(int u,int k)
{
    F(i,0,18,1) if(bit(k,i)) u=up[i][u];
    return u;
}
void process()
{
    int u,k;cin>>u>>k;
    cout<<(get(u,k)?get(u,k):-1)<<'\n';
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