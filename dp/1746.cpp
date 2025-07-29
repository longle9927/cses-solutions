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
int n,m;
int a[N];
ll dp[105][N];
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
    cin>>n>>m;
    F(i,1,n,1) cin>>a[i];
    clock_t begin = clock();
    //code:
    F(i,1,n,1)
    {
        F(j,1,m,1)
        {
            if(a[i]&&j!=a[i]) continue;
            dp[j][i]=1;
            if(a[i-1])
            {
                if(abs(j-a[i-1])<=1) dp[j][i]=dp[a[i-1]][i-1];
            }
            else dp[j][i]=(dp[j-1][i-1]+dp[j+1][i-1]+dp[j][i-1])%MOD;
        }
    }
    ll ans=0;
    F(j,1,m,1) ans+=dp[j][n];
    // cout<<dp[1][2];
    cout<<ans;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}