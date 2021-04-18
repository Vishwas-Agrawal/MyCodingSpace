/*God or what*/
/*Author--Vishwas Agrawal*/
/*Author--Vishwas Agrawal*/
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define test \
   ll t;     \
   cin >> t; \
   while (t--)
#define fio                          \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);                    \
   cout.tie(NULL);
#define M 1000000007LL
#define input(v, n) \
   inc(i, 0, n)     \
   {                \
      ll x;         \
      cin >> x;     \
      v.pb(x);      \
   }
#define print(v, n) \
   inc(i, 0, n) { cout << v[i] << " "; }
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define endl "\n"
#define inc(i, a, n) for (ll i = a; i < n; i++)
#define dec(i, a, n) for (ll i = n - 1; i >= a; i--)
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
long long binpow(long long base, long long exp, int mod)
{
   long long res = 1;
   while (exp > 0)
   {
      if (exp % 2 == 1)
         res = (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
   return res;
}
long long mod(long long x)
{
   return ((x % M + M) % M);
}

long long add(long long a, long long b)
{
   return mod(mod(a) + mod(b));
}

long long mul(long long a, long long b)
{
   return mod(mod(a) * mod(b));
}
//mask turn on condition is (i&(1<<j))!=0 not (i&(1<<j))==1

int main()
{
   fio;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w",stdout);
    freopen("Error.txt","w",stderr);
#endif
    int n;
    vector<vll> g(n,vll(n));
    //reading the graph write code;
    vll deg(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            deg[i]+=g[i][j];
        }
    }
    int first =0;
    while(first <n && !deg[first]);{
        ++first;
        if(first==n){
            cout<<-1;
            return 0;
        }
    }
    int v1=-1,v2=-1;
    bool bad = false;
    for(int i=0; i<n; i++)
    {
        if(deg[i]&1){
            if(v1==-1)
            {
                v1=i;
            }
            else if (v2==-1)
            {
                v2=i;
            }
            else bad=true;
        }
    }
    if(v1!=-1){
        ++g[v1][v2],++g[v2][v1];
    }
    stack<int> st;
    st.push(first);
    vector<int> res;
    while(!st.empty()){
        int v=st.top();
        int i;
        for(i=0; i<n; i++)
        {
            if(g[v][i]){
                break;
            }
        }
        if(i==n){
            res.push_back(v);
            st.pop();
        }else{
            --g[v][i];
            --g[i][v];
            st.push(i);
        }
    }
    if(v1!=-1)
    {
        for(size_t i=0; i+1<res.size(); i++)
        {
            if((res[i]==v1&&res[i+1]==v2)||
            (res[i] == v2 && res[i+1] == v1)){
                vector<int> res2;
                for (size_t j = i + 1; j < res.size(); ++j)
                    res2.push_back(res[j]);
                for (size_t j = 1; j <= i; ++j)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(g[i][j])
            {
                bad = true;
            }
        }
    }
    if(bad){
        cout<<-1<<endl;
    }else{
        for(int x:res){
            cout<<x<<" ";
        }
    }


   return 0;
}

