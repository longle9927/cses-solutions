#include<bits/stdc++.h>
using ll=long long;
const int N=5e2+5;
#define pii pair<int,int> //sua thanh ll khi can
#define fi first
#define se second
#define F(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fo(i,a,b,c) for(int i=a;i>=b;i-=c)
#define pb push_back
const int MOD=1e9+7;
#define el cout<<'\n'
using namespace std;
int a,b;
int dp[N][N];
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
    cin>>a>>b;
    clock_t begin = clock();
    //code:
    F(i,1,a,1) F(j,1,b,1)
    {
        if(i==j) dp[i][j]=0;
        else
        {
            int x=1e9;
            F(k,1,i-1,1) x=min(x,dp[k][j]+dp[i-k][j]);
            F(k,1,j-1,1) x=min(x,dp[i][k]+dp[i][j-k]);
            dp[i][j]=x+1;
        }
    }
    cout<<dp[a][b];
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}