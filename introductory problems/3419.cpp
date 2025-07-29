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
int a[105][105];
bitset<1005> c;
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
    memset(a,-1,sizeof(a));
    clock_t begin = clock();
    //code:
    a[1][1]=0;
    F(i,1,n,1) F(j,1,n,1)
    {
        if(i==1 && j==1) continue;
        if(i==1)
        {
            a[i][j]=a[i][j-1]+1;
            continue;
        }
        if(j==1)
        {
            a[i][j]=a[i-1][j]+1;
            continue;
        }
        if(i==j)
        {
            a[i][j]=0;
            continue;
        }
        c.reset();
        int ma=0;
        F(k,1,i-1,1)
            c[a[k][j]]=1,ma=max(ma,a[k][j]);
        F(k,1,j-1,1) 
            c[a[i][k]]=1,ma=max(ma,a[i][k]);
        F(k,0,ma,1) if(!c[k])
        {
            a[i][j]=k;
            break;
        }
        if(a[i][j]==-1)
        {
            a[i][j]=ma+1;
        }
    }
    F(i,1,n,1)
    {
        F(j,1,n,1)
        {
            cout<<a[i][j]<<" ";
        }
        el;
    }  
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}