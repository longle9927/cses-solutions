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
int a[N];
vector<int> g[N];
int sz[N];
int par[N];
int dep[N];
int head[N];
int heavy[N];
void dfs_init(int u=1,int p=-1)
{
    sz[u]=1;
    int ma=0;
    int id=0;
    for(int v:g[u])
    {
        if(v==p) continue;
        par[v]=u;
        dep[v]=dep[u]+1;
        dfs_init(v,u);
        if(ma<sz[v])
        {
            ma=sz[v];
            id=v;
        }
        sz[u]+=sz[v];
    }
    heavy[u]=id;
}
int timer=0;
int tin[N];
void dfs(int u=1)
{
    tin[u]=++timer;
    int v=heavy[u];
    if(v)
    {
        head[v]=head[u];
        dfs(v);
    }
    for(int w:g[u])
    {
        if(w==par[u]||w==v) continue;
        head[w]=w;
        dfs(w);
    }
}
int ma[N];
int s=1;
void init()
{
    
    while(s<n) s*=2;
    F(i,1,n,1) ma[s+tin[i]-1]=a[i];
    fo(i,s-1,1,1) ma[i]=max(ma[i<<1],ma[i<<1|1]);
}
void update(int u,int v)
{
    int p=s+u-1;
    ma[p]=v;
    for(p>>=1;p;p>>=1) ma[p]=max(ma[p<<1],ma[p<<1|1]);
}
int get(int u,int v)
{
    int ans=0;
    int l=s+u-1,r=s+v-1;
    while(l<=r)
    {
        if(l&1) ans=max(ans,ma[l++]);
        if(r%2==0) ans=max(ans,ma[r--]);
        l>>=1;
        r>>=1;
    }
    return ans;
}
void process()
{
    int type;cin>>type;
    int x,y;
    if(type==1)
    {
        cin>>x>>y;
        update(tin[x],y);
    }
    else
    {
        cin>>x>>y;
        int ans=0;
        if(dep[head[x]]<dep[head[y]]) swap(x,y);
        while(head[x]!=head[y])
        {
            ans=max(ans,get(tin[head[x]],tin[x]));
            x=par[head[x]];
            if(dep[head[x]]<dep[head[y]]) swap(x,y);
        }
        if(tin[x]>tin[y]) swap(x,y);
        ans=max(ans,get(tin[x],tin[y]));
        cout<<ans<<' ';
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
    dfs_init();
    head[1]=1;
    dfs();
    init();
    while(t--) process();
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}