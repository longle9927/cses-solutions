#include<bits/stdc++.h>
using ll=long long;
const int N=5e2+5;
#define pii pair<int,int> //sua thanh ll khi can
#define fi first
#define se second
#define F(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fo(i,a,b,c) for(int i=a;i>=b;i-=c)
#define pb push_back
const int MOD=1e9+7;
#define el cout<<'\n'
using namespace std;
int n,m;
char a[N][N];
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
    cin>>n>>m;
    F(i,1,n,1) F(j,1,m,1) cin>>a[i][j];
    clock_t begin = clock();
    //code:
    F(i,1,n,1) F(j,1,m,1) a[i][0]=a[0][j]='Z';
    F(i,1,n,1) F(j,1,m,1)
    {
        bool ok=0;
        F(c,'A','D',1)
        {
            if(a[i][j]!=char(c)&&a[i-1][j]!=char(c)&&a[i][j-1]!=char(c))
            {
                a[i][j]=char(c);
                ok=1;
                break;
            }
        }
        if(!ok)
        {
            cout<<"IMPOSSIBLE";el;
            return 0;
        }
    }
    F(i,1,n,1)
    {
        F(j,1,m,1) cout<<a[i][j];
        el;
    }
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}