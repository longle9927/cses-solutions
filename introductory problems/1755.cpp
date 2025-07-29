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
int n;
int c[N];
void sol1()
{
    int ans=0;
    F(i,'A','Z',1)
    {
        if(c[i]%2==1)
        {
            ans++;
        }
    }
    if(ans>1)
    {
        cout<<"NO SOLUTION\n";return;
    }
    char ch;
    F(i,'A','Z',1)
    {
        if(c[i]%2==0)
        {
            int x=c[i]/2;
            while(c[i]>x)
            {
                cout<<char(i);
                c[i]--;
            }
        }
        else ch=char(i); 
    }
    while(c[ch]>0)
    {
        cout<<ch;
        c[ch]--;
    }
    fo(i,'Z','A',1)
    {
        while(c[i]>0)
        {
            cout<<char(i);
            c[i]--;
        }
    }
}
void sol2()
{
    F(i,'A','Z',1)
    {
        if(c[i]%2==1)
        {
            cout<<"NO SOLUTION\n";return;
        }
    }
    F(i,'A','Z',1)
    {
        int x=c[i]/2;
        while(c[i]>x)
        {
            cout<<char(i);
            c[i]--;
        }
    }
    fo(i,'Z','A',1)
    {
        while(c[i]>0)
        {
            cout<<char(i);
            c[i]--;
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
    n=s.size();s='#'+s;
    clock_t begin = clock();
    //code:
    F(i,1,n,1) c[s[i]]++;
    if(n&1) sol1();
    else sol2();
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}