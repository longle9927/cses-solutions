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
    set<int> se;
    F(i,1,n,1) se.insert(i);
    clock_t begin = clock();
    //code:
    int x=1;
    while(se.size())
    {
        auto it=se.upper_bound(x);
        if(it==se.end()) it=se.begin();
        auto vt=se.upper_bound(*it);
        if(vt==se.end()) vt=se.begin();
        cout<<*it<<' ';
        se.erase(it);
        x=*vt;
    }
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}