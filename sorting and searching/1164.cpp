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
struct tri
{
    int x;
    int type;
    int id;
    bool operator <(const tri &other) const
    {
        if(x==other.x) return type>other.type;
        return x<other.x;
    }
} a[N];
int f[N];
int cnt[N];
void update(int id,int l,int r,int u,int v)
{
    if(l==r)
    {
        cnt[id]+=v;
        return;
    }
    if((l+r)/2<u) update(id*2+1,(l+r)/2+1,r,u,v);
    else update(id*2,l,(l+r)/2,u,v);
    cnt[id]=cnt[id*2]+cnt[id*2+1];
}
int get(int id,int l,int r)
{
    if(l==r) return l;
    if(cnt[id*2]<((l+r)/2-l+1)) return get(id*2,l,(l+r)/2);
    else return get(id*2+1,(l+r)/2+1,r);
}
// struct cmp
// {
//     bool operator ()(int i,int j)
//     {
//         return a[i].x<a[j].x;
//     }
// };
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
    int sz=0;
    F(i,1,n,1)
    {
        int x,y;cin>>x>>y;
        a[++sz]={x,1,i};
        a[++sz]={y,-1,i};
    }
    clock_t begin = clock();
    //code:
    n=sz;
    sort(a+1,a+n+1);
    // priority_queue<int,vector<int>,cmp> h;
    int ans=0;
    F(i,1,n,1)
    {
        // while(h.size()&&a[h.top()].x<a[i].x) update(1,1,n,f[a[h.top()].id],-1);
        int vt=get(1,1,n);
        // cout<<a[i].x<<' '<<a[i].type<<' '<<vt;el;
        if(a[i].type==1)
        {
            update(1,1,n,f[a[i].id]=vt,1);
            ans=max(ans,vt);
            
        }
        else update(1,1,n,f[a[i].id],-1)
            //  ,h.push(i)
             ;
        // cout<<a[i].x<<' ';
    }
    // el;
    // F(i,1,n,1) cout<<a[i].type<<' ';
    // el;
    cout<<ans;el;
    F(i,1,n/2,1) cout<<f[i]<<' ';
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}