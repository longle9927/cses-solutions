#include<bits/stdc++.h>
using ll=long long;
const int N=25;
#define pii pair<int,int> //sua thanh ll khi can
#define fi first
#define se second
#define F(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fo(i,a,b,c) for(int i=a;i>=b;i-=c)
#define pb push_back
const int MOD=1e9+7;
#define el cout<<'\n'
using namespace std;
ll n;
ll k,a[N];
int bit(int mask,int i)
{
    return (mask>>i)&1;
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
    cin>>n>>k;
    ll ans=0;
    F(i,0,k-1,1) cin>>a[i];
    clock_t begin = clock();
    //code:
    F(mask,1,(1<<k)-1,1)
    {
        int d=0;
        ll lcm=1;
        F(i,0,k-1,1) if(bit(mask,i))
        {
            if(lcm<=n/a[i])
            {
                lcm*=a[i];
                d++;
            }
            else
            {
                lcm=n+1;
                break;
            }
        }
        if(d&1) ans+=n/lcm;
        else ans-=n/lcm;
    }
    cout<<ans;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}