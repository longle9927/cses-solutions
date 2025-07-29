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
ll xando(ll a,ll b,ll m)
{
    ll res=0;
    while(b)
    {
        if(b&1) res=(res+a)%m;
        a=(a*2)%m;
        b>>=1;
    }
    return res;
}
ll binarypow(ll a,ll b,ll m)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=xando(res,a,m);
        a=xando(a,a,m);
        b>>=1;
    }
    return res;
}
bool ktcoso(ll a,ll d,ll k,ll n)
{
    ll x=binarypow(a,d,n);
    if(x==1||x==n-1) return 1;
    while(k--)
    {
        x=xando(x,x,n);
        if(x==n-1) return 1;
    }
    return 0;
}
bool kt(ll n)
{
    if(n==2||n==3||n==5) return 1;
    if(n<2||n%2==0) return 0;
    ll d=n-1;
    int k=0;
    while(d%2==0) k++,d>>=1;
    vector<ll> base={2,3,5,7,11,13,17,19,23};
    for(ll a:base)
    {
        if(a>=n) break;
        if(!ktcoso(a,d,k,n)) return 0;
    }
    return 1;
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
    int t;cin>>t;
    clock_t begin = clock();
    //code:
    while(t--)
    {
        ll n;cin>>n;
        n++;
        while(!kt(n)) n++;
        cout<<n;el;
    }
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}