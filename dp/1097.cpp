#include<bits/stdc++.h>
using ll=long long;
const int N=5e3+5;
#define pii pair<int,int> //sua thanh ll khi can
#define fi first
#define se second
#define F(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fo(i,a,b,c) for(int i=a;i>=b;i-=c)
#define pb push_back
const int MOD=1e9+7;
#define el cout<<'\n'
using namespace std;
int n,a[N];
ll dp[N][N];
ll s[N];
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
    F(i,1,n,1) cin>>a[i],s[i]=s[i-1]+a[i];
    clock_t begin = clock();
    //code:
    F(d,1,n,1)
    {
        F(i,1,n-d+1,1)
        {
            dp[i][i]=a[i];
            int j=i+d-1;
            dp[i][j]=max(s[j-1]-s[i-1]-dp[i][j-1]+a[j],s[j]-s[i]-dp[i+1][j]+a[i]);
        }
    }
    cout<<dp[1][n];
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}