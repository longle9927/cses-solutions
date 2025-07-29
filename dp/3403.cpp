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
int n,m;
int a[N];
int b[N];
int dp[N][N];
int tr[N][N];
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
    F(i,1,m,1) cin>>b[i];
    clock_t begin = clock();
    //code:
    F(i,1,n,1) F(j,1,m,1)
    {
        if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];
                tr[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i][j-1];
                tr[i][j]=2;
            }
        }
    }
    cout<<dp[n][m];el;
    int i=n,j=m;
    vector<int> res;
    while(i&&j)
    {
        if(tr[i][j]==1) i--;
        else if(tr[i][j]==2) j--;
        else
        {
            res.pb(a[i]);
            i--;j--;
        }
    }
    fo(i,res.size()-1,0,1) cout<<res[i]<<' ';
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}