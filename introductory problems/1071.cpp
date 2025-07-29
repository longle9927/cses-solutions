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
void process()
{
    ll x,y;cin>>x>>y;
    if(x>=y)
    {
        if(x&1) cout<<(x*x)-2*x+y+1;
        else cout<<(x*x)-y+1;
    }
    else
    {
        if(y&1) cout<<(y*y)-x+1;
        else cout<<(y*y)-2*y+x+1;
    }
    el;
}
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
    int t;cin>>t;

    clock_t begin = clock();
    //code:
    while(t--) process();
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    el;
    return 0;
}