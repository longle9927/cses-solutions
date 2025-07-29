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
int n,a[N],t;
int mp[N];
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
    cin>>n>>t;
    F(i,1,n,1) cin>>a[i];
    clock_t begin = clock();
    //code:
    int ans=1;
    F(i,1,n,1)
    {
        if(mp[a[i]+1]) ans++;
        mp[a[i]]=i;
    }
    while(t--)
    {
        int i,j;cin>>i>>j;
        int u=a[i],v=a[j];
        set<int> se;
        for(int x:{u,u-1,v,v-1}) if(x&&x<n) se.insert(x);
        for(int x:se) if(mp[x]>mp[x+1]) ans--;
        swap(a[i],a[j]);
        swap(mp[u],mp[v]);
        for(int x:se) if(mp[x]>mp[x+1]) ans++;
        cout<<ans;el;
    }
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}