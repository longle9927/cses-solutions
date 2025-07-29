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
int n, m, k;
int a[N], b[N];
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
    cin>>n>>m>>k;
    F(i,1,n,1) cin>>a[i];
    F(i,1,m,1) cin>>b[i];
    clock_t begin = clock();
    //code:
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    int ans=0;
    int i=1, j=1;
    while(i<=n && j<=m)
    {
        if(abs(a[i]-b[j]) <= k)
        {
            ans++;
            i++;
            j++;
        }
        else if(a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout<<ans;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}