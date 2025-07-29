#include<bits/stdc++.h>
using ll=long long;
const int N=1e3+5;
#define pii pair<int,int> //sua thanh ll khi can
#define fi first
#define se second
#define F(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fo(i,a,b,c) for(int i=a;i>=b;i-=c)
#define pb push_back
const int MOD=1e9+7;
#define el cout<<'\n'
using namespace std;
int n,a[N][N];
ll dp[N][N];
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
    char c;
    F(i,1,n,1) F(j,1,n,1) cin>>c,a[i][j]=c=='*';
    clock_t begin = clock();
    //code:
    dp[1][1]=1-a[1][1];
    F(i,1,n,1) F(j,1,n,1)
    {
        if(a[i][j]) continue;
        if(i>1) dp[i][j]=dp[i-1][j];
        if(j>1) dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
    }
    cout<<dp[n][n];
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}