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
int dep[N];
vector<int> res;
int ma=0;
int id=0;
int dist[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    memset(dep,-1,sizeof(dep));
    dep[s]=0;
    while(q.size())
    {
        int u=q.front();q.pop();
        for(auto v:g[u])
        {
            if(dep[v]==-1)
            {
                dep[v]=dep[u]+1;
                if(ma<dep[v])
                {
                    ma=dep[v];
                    id=v;
                }
                q.push(v);
            }
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
    int u,v;
    F(i,2,n,1)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    clock_t begin = clock();
    //code:
    bfs(1);
    ma=0;
    // int x=id;
    bfs(id);
    ma=0;
    // cout<<id;el;
    F(i,1,n,1) dist[i]=max(dist[i],dep[i]);
    bfs(id);
    // cout<<x<<' '<<id;
    // F(i,1,n,1) cout<<dep[i]<<' ';el;
    F(i,1,n,1) cout<<max(dist[i],dep[i])<<' ';
    // cout<<dist[x]<<' '<<dep[id];
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}