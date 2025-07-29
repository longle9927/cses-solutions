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
int t,x;
int ans[N];
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
    cin>>x>>t;
    clock_t begin = clock();
    //code:
    set<int> se;
    multiset<int> res;
    se.insert(0);se.insert(x);
    res.insert(x);
    F(i,1,t,1)
    {
        cin>>x;
        auto it=se.lower_bound(x);
        int r=*it;
        int l=*(--it);
        se.insert(x);
        res.erase(res.find(r-l));
        res.insert(r-x);
        res.insert(x-l);
        cout<<*res.rbegin()<<' ';
    }
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}