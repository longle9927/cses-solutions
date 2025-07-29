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
int sol(ll x,int i)
{
    string res="";
    while(x)
    {
        res+=char(x%10+48);
        x/=10;
    }
    reverse(res.begin(),res.end());
    return res[i]-48;
}
void process()
{
    ll n;cin>>n;
    ll t=9;
    ll s=1;
    F(i,1,18,1)
    {
        if(n>t*i) n-=t*i;
        else
        {
            // cout<<n;el;
            ll x=(n+i-1)/i;
            // cout<<x;el;
            ll y=s+x-1;
            // cout<<y;el;
            cout<<sol(y,(n-1)%i);el;
            return;
        }
        s*=10;
        t*=10;
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
    int t;cin>>t;
    clock_t begin = clock();
    //code:
    while(t--) process();
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}