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
int a[N];
ll gt[N];

void sub1()
{
    int n;
    ll k;
    cin>>n>>k;
    k--;
    vector<int> v;
    F(i,1,n,1) v.pb(i);
    F(i,0,n-1,1)
    {
        ll x=gt[n-i-1];
        int j=k/x;
        cout<<v[j]<<' ';
        v.erase(v.begin()+j);
        k%=x;
    }
}
int c[N];
void sub2()
{
    int n;cin>>n;
    F(i,1,n,1) cin>>a[i];
    memset(c,0,sizeof(c));
    ll ans=1;
    F(i,1,n,1)
    {
        ll d=0;
        F(j,1,a[i]-1,1) if(!c[j]) d++;
        ans+=d*gt[n-i];
        c[a[i]]=1;
    }
    cout<<ans;
}
void process()
{
    int type;cin>>type;
    if(type==1) sub1();
    else sub2();
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
    gt[0]=1;
    F(i,1,20,1) gt[i]=gt[i-1]*i;
    while(t--) process();
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}