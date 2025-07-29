#include<bits/stdc++.h>
using ll=long long;
const int N=1e6+5;
#define pii pair<int,int>
#define fi first
#define se second
#define F(i,a,b,c) for(int i=a;i<=b;i+=c)
#define fo(i,a,b,c) for(int i=a;i>=b;i-=c)
const ll MOD=1e9+3;
#define el cout<<'\n'
using namespace std;
const int base=31;
ll has[N],Pow[N];
string s,t;
int n,m;
ll hashs=0;
void hass()
{
    F(i,1,m,1)
    {
        hashs=(hashs*base+s[i]-'a')%MOD;
    }
}
void hast()
{
    F(i,1,n,1)
    {
        Pow[i]=(Pow[i-1]*base)%MOD;
        has[i]=(has[i-1]*base+t[i]-'a')%MOD;
    }
}
ll get(int i,int j)
{
    return (has[j]-has[i-1]*Pow[j-i+1]+MOD*MOD)%MOD;
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
    cin>>t>>s;
    clock_t begin = clock();
    //code:
    n=t.size(),m=s.size();
    t='#'+t;
    s='#'+s;
    Pow[0]=1;
    hass();
    hast();
    int ans=0;
    F(i,1,n-m+1,1)
    {
        if(hashs==get(i,i+m-1))
        {
            ans++;
        }
    }
    cout<<ans;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}
