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
string s;
ll ans=0;
bool vs[8][8];
void Try(int i=1,int x=1,int y=1)
{
    if(7-x+y-1>48-i+1) return;
    if(i>48)
    {
        if(x==7&&y==1) ans++;
        return;
    }
    bool up=x==1||vs[x-1][y];
    bool down=x==7||vs[x+1][y];
    bool left=y==1||vs[x][y-1];
    bool right=y==7||vs[x][y+1];
    if((up&&down&&!left&&!right) || (left&&right&&!up&&!down)) return;
    if(x==7&&y==1) return;
    if(s[i]=='?')
    {
        if(x<7&&!vs[x+1][y])
        {
            vs[x+1][y]=1;
            Try(i+1,x+1,y);
            vs[x+1][y]=0;
        }
        if(y<7&&!vs[x][y+1])
        {
            vs[x][y+1]=1;
            Try(i+1,x,y+1);
            vs[x][y+1]=0;
        }
        if(x>1&&!vs[x-1][y])
        {
            vs[x-1][y]=1;
            Try(i+1,x-1,y);
            vs[x-1][y]=0;
        }
        if(y>1&&!vs[x][y-1])
        {
            vs[x][y-1]=1;
            Try(i+1,x,y-1);
            vs[x][y-1]=0;
        }
    }
    else
    {
        if(s[i]=='D')
        {
            if(x<7&&!vs[x+1][y])
            {
                vs[x+1][y]=1;
                Try(i+1,x+1,y);
                vs[x+1][y]=0;
            }
        }
        else if(s[i]=='R')
        {
            if(y<7&&!vs[x][y+1])
            {
                vs[x][y+1]=1;
                Try(i+1,x,y+1);
                vs[x][y+1]=0;
            }
        }
        else if(s[i]=='U')
        {
            if(x>1&&!vs[x-1][y])
            {
                vs[x-1][y]=1;
                Try(i+1,x-1,y);
                vs[x-1][y]=0;
            }
        }
        else if(s[i]=='L')
        {
            if(y>1&&!vs[x][y-1])
            {
                vs[x][y-1]=1;
                Try(i+1,x,y-1);
                vs[x][y-1]=0;
            }
        }

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
    cin>>s;
    s='#'+s;
    clock_t begin = clock();
    //code:
    vs[1][1]=1;
    Try();
    cout<<ans;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}