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
int n,a[N],x;
unordered_map<int,pii> mp;
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
    cin>>n>>x;
    F(i,1,n,1) cin>>a[i];
    clock_t begin = clock();
    //code:
    F(i,1,n-3,1) F(j,i+1,n-2,1) mp[a[i]+a[j]]={i,j};
    F(k,3,n-1,1) F(h,k+1,n,1)
    {
        if(mp.find(x-a[k]-a[h])!=mp.end())
        {
            auto [i,j]=mp[x-a[k]-a[h]];
            if(i!=k&&i!=h&&j!=k&&j!=h)
            {
                cout<<i<<' '<<j<<' '<<k<<' '<<h;el;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}