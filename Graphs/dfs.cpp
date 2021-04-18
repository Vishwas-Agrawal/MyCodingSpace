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
#define pb push_back
#define mp make_pair
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
#define inc(i, a, n) for (ll i = a; i < n; i++)
#define dec(i, a, n) for (ll i = n - 1; i >= a; i--)
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
vll graph[200005];
vll visited(200005, false);
vll answer(200005);
void addEdge(vll graph[], ll u, ll v)
{
   graph[u].pb(v);
   graph[v].pb(u);
}
ll dfs(ll current)
{
   // cout << current << endl;
   visited[current] = true;
   ll temp = 1;
   for (auto i : graph[current])
   {
      if (!visited[i])
      {

         temp += dfs(i);
         //do whatever you like here
         //according to question
         //happy coding
      }
   }
   answer[current] = temp;
   return temp;
   // your add return statement
   //donot forget to change type of function
}

int main()
{
   ll n;
   cin >> n;
   ll u, v;
   inc(i, 0, n - 1)
   {
      cin >> u;
      addEdge(graph, i + 2, u);
   }
   dfs(1);
   for (int i = 1; i <= n; i++)
   {
      cout << answer[i] - 1 << " ";
   }
   cout << endl;

   return 0;
}