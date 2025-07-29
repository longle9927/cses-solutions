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
int st[N];
void update(int id,int l,int r,int u,int v)
{
    if(l==r)
    {
        st[id]=v;
        return;
    }
    if((l+r)/2<u) update(id*2+1,(l+r)/2+1,r,u,v);
    else update(id*2,l,(l+r)/2,u,v);
    st[id]=st[id*2]+st[id*2+1];
}
int get(int id,int l,int r,int k)
{
    if(l==r) return l;
    if(st[id*2]>=k) return get(id*2,l,(l+r)/2,k);
    else return get(id*2+1,(l+r)/2+1,r,k-st[id*2]);
}
int k;
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
    cin>>n>>k;
    clock_t begin = clock();
    //code:
    F(i,1,n,1) update(1,1,n,i,1);
    int remain=n,x=1;
    F(i,1,n,1)
    {
        x=(x+k)%remain;
        if(!x) x=remain;
        int j=get(1,1,n,x);
        cout<<get(1,1,n,x)<<' ';
        update(1,1,n,j,0);
        remain--;
    }
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}