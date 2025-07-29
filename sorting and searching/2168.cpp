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
    F(i,1,n,1) cin>>a[i].fi>>a[i].se,c[i]=i;
    clock_t begin = clock();
    //code:
    sort(c+1,c+n+1,cmp);
    int ma=0;
    F(i,1,n,1)
    {
        if(a[c[i]].se<=ma) contained[c[i]]=1;
        ma=max(ma,a[c[i]].se);
    }
    int mi=1e9+1;
    fo(i,n,1,1)
    {
        if(a[c[i]].se>=mi) contain[c[i]]=1;
        mi=min(mi,a[c[i]].se);
    }
    F(i,1,n,1) cout<<contain[i]<<' ';
    el;
    F(i,1,n,1) cout<<contained[i]<<' ';
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}