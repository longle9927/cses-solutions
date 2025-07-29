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
ll n;
int a[N];
int dp[N];
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
    if(n*(n+1)%4!=0)
    {
        cout<<"NO";el;
        return 0;
    }
    clock_t begin = clock();
    //code:
    ll target=n*(n+1)/4;
    fo(i,n,1,1)
    {
        if(target>=i)
        {
            target-=i;
            a[i]=1;
        }
    }
    if(target>0)
    {
        cout<<"NO";el;
        return 0;
    }
    cout<<"YES";el;
    int ans=0;
    F(i,1,n,1)
    {
        if(a[i]) ans++;
    }
    cout<<ans;el;
    F(i,1,n,1)  if(a[i]) cout<<i<<" ";
    el;
    cout<<n-ans;el;
    F(i,1,n,1) if(!a[i]) cout<<i<<" ";
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    el;
    return 0;
}