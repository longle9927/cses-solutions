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
int cnt[N+5];
void sang()
{
    cnt[1]=1;
    F(i,2,N,1) cnt[i]=2;
    F(i,2,sqrt(N),1)
    {
        cnt[i*i]++;
        F(j,i*i+i,N,i) cnt[j]+=2;
    }
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
    sang();
    int t;cin>>t;
    clock_t begin = clock();
    //code:
    while(t--)
    {
        int n;cin>>n;
        cout<<cnt[n];el;
    
    }
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}