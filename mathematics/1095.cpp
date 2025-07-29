#include<bits/stdc++.h>
using ll=long long;
const int N=1e6+5;
#define pii pair<int,int> //sua thanh ll khi can
#define fi first
#define se second
#define F(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fo(i,a,b,c) for(int i=a;i>=b;i-=c)
#define pb push_back
const ll MOD=1e9+7;
#define el cout<<'\n'
using namespace std;
ll binarypow(ll a,ll b,ll m)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
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
        ll a,b;cin>>a>>b;
        cout<<binarypow(a,b,MOD);el;
    }
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}