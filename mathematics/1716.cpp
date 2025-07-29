#include<bits/stdc++.h>
using ll=long long;
const int N=2e6+5;
#define pii pair<int,int> //sua thanh ll khi can
#define fi first
#define se second
#define F(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fo(i,a,b,c) for(int i=a;i>=b;i-=c)
#define pb push_back
const int MOD=1e9+7;
#define el cout<<'\n'
using namespace std;
int n,k;
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
ll nghichdaomodulo(ll a,ll m)
{
    return binarypow(a,m-2,m);
}
ll gt[N],nd[N];
void init()
{
    gt[0]=nd[0]=1;
    F(i,1,N-5,1)
    {
        gt[i]=gt[i-1]*i%MOD;
        nd[i]=nghichdaomodulo(gt[i],MOD);
    }
}
// C(n,k) = gt[n]*nd[k]%MOD*nd[n-k]%MOD
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
    cin>>k>>n;
    clock_t begin = clock();
    //code:
    init();
    cout<<gt[n+k-1]*nd[k-1]%MOD*nd[n]%MOD;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}