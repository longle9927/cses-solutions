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
int n,x,a[N];
int c[N];
bool cmp(int i,int j)
{
    return a[i]<a[j];
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
    cin>>n>>x;
    F(i,1,n,1) cin>>a[i],c[i]=i;
    clock_t begin = clock();
    //code:
    sort(c+1,c+n+1,cmp);
    sort(a+1,a+n+1);
    F(i,1,n-2,1)
    {
        F(j,i+1,n-1,1)
        {
            int vt=lower_bound(a+j+1,a+n+1,x-a[i]-a[j])-a;
            if(a[i]+a[j]+a[vt]==x)
            {
                cout<<c[i]<<' '<<c[j]<<' '<<c[vt];el;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}