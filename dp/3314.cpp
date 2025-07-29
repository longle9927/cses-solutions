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
int n,a[N];
int dp[N];
int l[N],r[N];
int c[N];
bool cmp(int i,int j)
{
    return a[i]>a[j];
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
    cin>>n;
    F(i,1,n,1) cin>>a[i],c[i]=i;
    clock_t begin = clock();
    //code:
    stack<int> st;
    F(i,1,n,1)
    {
        while(st.size()&&a[st.top()]<=a[i]) st.pop();
        if(st.empty()) l[i]=-1;
        else l[i]=st.top();
        st.push(i);
    }
    while(st.size()) st.pop();
    fo(i,n,1,1)
    {
        while(st.size()&&a[st.top()]<=a[i]) st.pop();
        if(st.empty()) r[i]=-1;
        else r[i]=st.top();
        st.push(i);
    }
    sort(c+1,c+n+1,cmp);
    int ans=0;
    F(i,1,n,1)
    {
        dp[c[i]]=1;
        if(l[c[i]]!=-1) dp[c[i]]=max(dp[c[i]],dp[l[c[i]]]+1);
        if(r[c[i]]!=-1) dp[c[i]]=max(dp[c[i]],dp[r[c[i]]]+1);
        ans=max(ans,dp[c[i]]);
    }
    cout<<ans;
    clock_t end = clock();
    cerr<<endl<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}