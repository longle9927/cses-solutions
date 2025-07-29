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
ll a[N];
bool check(ll k)
{
    ll res=0;
    F(i,1,n,1)
    {
        res+=k/a[i];
        if(res>=t) return 1;
    }
    return 0;
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
    clock_t begin = clock();
    //code:
    ll l=1,r=1e18,mid,ans;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}