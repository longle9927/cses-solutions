#include<bits/stdc++.h>
using ll=long long;
const int N=8e6+5;
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
pii a[N];
int c[N];
bool cmp(int i,int j)
{
    pii x=a[i],y=a[j];
    if(x.fi==y.fi) return x.se>y.se;
    return x.fi<y.fi;
}
int contained[N];
int contain[N];
vector<int> res;
void nen(int &x)
{
    x=lower_bound(res.begin(),res.end(),x)-res.begin()+1;
}
int cnt[N];
void update(int id,int l,int r,int u)
{
    if(l==r)
    {
        cnt[id]++;
        return;
    }
    if((l+r)/2<u) update(id*2+1,(l+r)/2+1,r,u);
    else update(id*2,l,(l+r)/2,u);
    cnt[id]=cnt[id*2]+cnt[id*2+1];
}
int get(int id,int l,int r,int u,int v)
{
    if(r<u||l>v) return 0;
    if(l>=u&&r<=v) return cnt[id];
    return get(id*2,l,(l+r)/2,u,v)+get(id*2+1,(l+r)/2+1,r,u,v);
}
int M;
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
    F(i,1,n,1)
    {
        cin>>a[i].fi>>a[i].se,c[i]=i;
        res.pb(a[i].fi);
        res.pb(a[i].se);
    }
    M=res.size();
    sort(res.begin(),res.end());
    F(i,1,n,1) nen(a[i].fi),nen(a[i].se);
    clock_t begin = clock();
    //code:
    sort(c+1,c+n+1,cmp);
    F(i,1,n,1)
    {
        contained[c[i]]=i-1-get(1,1,M,1,a[c[i]].se-1);
        update(1,1,M,a[c[i]].se);
    }
    memset(cnt,0,sizeof(cnt));
    fo(i,n,1,1)
    {
        contain[c[i]]=get(1,1,M,1,a[c[i]].se);
        update(1,1,M,a[c[i]].se);
    }
    F(i,1,n,1) cout<<contain[i]<<' ';
    el;
    F(i,1,n,1) cout<<contained[i]<<' ';
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}