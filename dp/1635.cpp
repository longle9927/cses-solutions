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
int n,a[N],w;
ll dp[N];
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
    cin>>n>>w;
    F(i,1,n,1) cin>>a[i];
    clock_t begin = clock();
    //code:
    sort(a+1,a+n+1);
    dp[0]=1;
    F(j,a[1],w,1) F(i,1,n,1) if(j>=a[i]) dp[j]=(dp[j]+dp[j-a[i]])%MOD;
    cout<<dp[w]%MOD;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}