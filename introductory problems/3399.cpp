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
int n,a,b;
vector<int> res[3];
void process()
{
    res[1].clear(); res[2].clear();
    cin>>n>>a>>b;
    if(a+b>n)
    {
        cout<<"NO";el;
        return;
    }
    F(i,1,n-a-b,1) res[1].pb(i), res[2].pb(i);
    if(b>a)
    {
        F(i,n-a-b+1,n,1) res[2].pb(i);
        F(i,n-a+1,n,1) res[1].pb(i);
        F(i,n-a-b+1,n-a,1) res[1].pb(i);
        F(i,n-a-b+1,n-b,1) if(res[1][i-1] <= res[2][i-1])
        {
            cout<<"NO";el;
            return;
        }
        F(i,n-b+1,n,1) if(res[2][i-1] <= res[1][i-1])
        {
            cout<<"NO";el;
            return;
        }
    }
    else
    {
        F(i,n-a-b+1,n,1) res[1].pb(i);
        F(i,n-b+1,n,1) res[2].pb(i);
        F(i,n-a-b+1,n-b,1) res[2].pb(i);
        F(i,n-a-b+1,n-a,1) if(res[2][i-1] <= res[1][i-1])
        {
            cout<<"NO";el;
            return;
        }
        F(i,n-a+1,n,1) if(res[1][i-1] <= res[2][i-1])
        {
            cout<<"NO";el;
            return;
        }
    }
    cout<<"YES";el;
    F(i,1,2,1)
    {
        for(int x:res[i]) cout<<x<<' ';
        el;
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
    int t;cin>>t;
    clock_t begin = clock();
    //code:
    while(t--) process();
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}