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
    string res="";
    F(i,1,n,1) c[s[i]]++;
    int ma=0;
    F(i,'A','Z',1) ma=max(ma,c[i]);
    if(ma>(n+1)/2)
    {
        cout<<"-1";el;
        return 0;
    }
    F(i,1,n,1)
    {
        // bool ok=0;
        F(j,'A','Z',1)
        {
            if(c[j]&&(res.empty()||j!=res.back()))
            {
                c[j]--;
                ma=0;
                F(k,'A','Z',1) ma=max(ma,c[k]);
                if(ma>(n-i+1)/2)
                {
                    c[j]++;
                    continue;
                }
                res+=char(j);
                // ok=1;
                break;
            }
            
        }
        // if(!ok)
        // {
        //     cout<<"-1";el;
        //     return 0;
        // }
    }
    cout<<(res.size()==n?res:"-1");el;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}