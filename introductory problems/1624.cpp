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
bool a[9][9];
bool r[9],c[9],lft[17],rght[17];
ll ans=0;
void Try(int i=1,int j=1,int d=0)
{
    if(d==8)
    {
        ans++;
        return;
    }
    if(i>8)
    {
        ans+=(d==8);
        return;
    }
    if(j>8)
    {
        Try(i+1,1,d);
        return;
    }
    if(a[i][j] && !r[i] && !c[j] && !lft[i-j+8] && !rght[i+j])
    {
        r[i]=1;
        c[j]=1;
        lft[i-j+8]=1;
        rght[i+j]=1;
        Try(i,j+1,d+1);
        r[i]=0;
        c[j]=0;
        lft[i-j+8]=0;
        rght[i+j]=0;
    }
    Try(i,j+1,d);
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
    char ch;
    F(i,1,8,1) F(j,1,8,1) cin>>ch,a[i][j]=(ch=='.');
    clock_t begin = clock();
    //code:
    Try();
    cout<<ans;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}