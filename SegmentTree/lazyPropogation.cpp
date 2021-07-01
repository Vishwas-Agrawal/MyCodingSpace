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
ll decbin(string s)
{
   return stoll(s, 0, 2);
}
//mask turn on condition is (i&(1<<j))!=0 not (i&(1<<j))==1
//bitwise operator precedence is less than != and ==
// a%M(a%=M) is not a syntax error
//count(all(v),3) counts the number of 3 in vector
//lower_bound if x not present points to next greater element
//upper_bound return first element in the range which has value greater than given value
const int N = 1e6 + 5;
string given, result;
ll tree[N];
bool laz[N];
ll upd[N];
void pushdown(ll ss, ll se, ll cur)
{
   if (laz[cur] == 0)
      return;
   laz[cur] = 0;
   ll mid = (ss + se) / 2;
   tree[cur * 2 + 1] = (mid - ss + 1) * upd[cur], tree[cur * 2 + 2] = (se - mid) * upd[cur];
   upd[cur * 2 + 1] = upd[cur * 2 + 2] = upd[cur];
   laz[cur * 2 + 1] = laz[cur * 2 + 2] = 1;
   upd[cur] = 0;
}
ll createSegTree(ll ss, ll se, ll cur)
{
   laz[cur] = 0;
   upd[cur] = 0;
   if (ss == se)
   {
      tree[cur] = given[ss] - '0';
      return tree[cur];
   }
   tree[cur] = createSegTree(ss, (ss + se) / 2, cur * 2 + 1) + createSegTree((ss + se) / 2 + 1, se, cur * 2 + 2);
   return tree[cur];
}
ll rangeAns(ll l, ll r, ll ss, ll se, ll cur)
{
   if (ss >= l && se <= r)
      return tree[cur];
   if (ss > r || se < l)
      return 0;
   pushdown(ss, se, cur);
   return rangeAns(l, r, ss, (ss + se) / 2, cur * 2 + 1) + rangeAns(l, r, (ss + se) / 2 + 1, se, cur * 2 + 2);
}
ll update(ll l, ll r, ll ss, ll se, ll cur, ll type)
{

   if (ss >= l && se <= r)
   {
      tree[cur] = (se - ss + 1) * type, laz[cur] = 1, upd[cur] = type;
      return tree[cur];
   }
   if (ss > r || se < l)
      return tree[cur];
   pushdown(ss, se, cur);
   return tree[cur] = update(l, r, ss, (ss + se) / 2, cur * 2 + 1, type) + update(l, r, (ss + se) / 2 + 1, se, cur * 2 + 2, type);
}
int main()
{
   fio;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("Error.txt", "w", stderr);
#endif
   test
   {
      ll n, q;
      cin >> n >> q;
      ll l[q], r[q];
      cin >> result >> given;
      createSegTree(0, n - 1, 0);
      for (int i = 0; i < q; i++)
         cin >> l[i] >> r[i];
      bool ok = true;
      for (int i = q - 1; i >= 0; i--)
      {
         ll temp = rangeAns(l[i] - 1, r[i] - 1, 0, n - 1, 0);
         ll len = r[i] - l[i] + 1;
         if (temp * 2 == len)
            ok = false;
         else if (temp * 2 < len)
            update(l[i] - 1, r[i] - 1, 0, n - 1, 0, 0);
         else
            update(l[i] - 1, r[i] - 1, 0, n - 1, 0, 1);
      }

      if (ok)
      {
         for (int i = 0; i < n; i++)
         {
            if (rangeAns(i, i, 0, n - 1, 0) != result[i] - '0')
            {
               ok = false;
               break;
            }
         }
      }
      (ok) ? cout << "YES" << endl : cout << "NO" << endl;
   }

   return 0;
}