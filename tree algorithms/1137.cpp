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
int n,a[N],t;
vector<int> g[N];
int tin[N];
int sz[N];
int d=0;
void dfs(int u=1,int p=-1)
{
    tin[u]=++d;
    sz[u]=1;
    for(int v:g[u])
    {
        if(v==p) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
ll s[N];
void update(int id,int l,int r,int u,int v)
{
    if(l==r)
    {
        s[id]=v;
        return;
    }
    if((l+r)/2<u) update(id*2+1,(l+r)/2+1,r,u,v);
    else update(id*2,l,(l+r)/2,u,v);
    s[id]=s[id*2]+s[id*2+1];
}
ll get(int id,int l,int r,int u,int v)
{
    if(l>v||u>r) return 0;
    if(l>=u&&r<=v) return s[id];
    return get(id*2,l,(l+r)/2,u,v)+get(id*2+1,(l+r)/2+1,r,u,v);
}
void process()
{
    int type;cin>>type;
    if(type==1)
    {
        int x,y;cin>>x>>y;
        update(1,1,n,tin[x],y);
    }
    else
    {
        int x;cin>>x;
        cout<<get(1,1,n,tin[x],tin[x]+sz[x]-1)<<'\n';
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
    cin>>n>>t;
    F(i,1,n,1) cin>>a[i];
    int u,v;
    F(i,2,n,1)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    clock_t begin = clock();
    //code:
    dfs();
    F(i,1,n,1) update(1,1,n,tin[i],a[i]);
    while(t--) process();
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}