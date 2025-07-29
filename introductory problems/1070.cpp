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
int n;
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
    clock_t begin = clock();
    //code:
    if(n==1)
    {
        cout<<"1";
        return 0;
    }
    if(n<4)
    {
        cout<<"NO SOLUTION";
        return 0;
    }
    F(i,2,n,2)
    {
        if(i%2==0) cout<<i<<" ";
    }
    F(i,1,n,2)
    {
        if(i%2==1) cout<<i<<" ";
    }
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    el;
    return 0;
}