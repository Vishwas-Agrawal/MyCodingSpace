
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vll vector<ll>
#define pb push_back
#define test \
   ll t;     \
   cin >> t; \
   while (t--)
#define fio                          \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);                    \
   cout.tie(NULL);
#define M 1000000007LL
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
struct s
{
   ll val;
   ll left;
   ll right;
};
s tree[1000000];

s createSegTree(s *tree, vll &given, ll ss, ll se, ll current)
{

   if (ss == se)
   {
      s temp;
      temp.val = 1;
      temp.left = given[ss];
      temp.right = given[ss];
      tree[current] = temp;

      return tree[current];
   }
   else
   {
      s temp;
      s first = createSegTree(tree, given, ss, (ss + se) / 2, current * 2 + 1);

      s second = createSegTree(tree, given, (ss + se) / 2 + 1, se, current * 2 + 2);
      tree[current] =
          return tree[current];
   }
}
ll rangeAns(ll *tree, ll l, ll r, ll ss, ll se, ll current)
{
   if (ss >= l && se <= r)
   {
      return tree[current];
   }
   else
   {
      if (ss > r || se < l)
      {
         return 0;
      }
      else
      {
         return rangeAns(tree, l, r, ss, (ss + se) / 2, current * 2 + 1) + rangeAns(tree, l, r, (ss + se) / 2 + 1, se, current * 2 + 2);
      }
   }
}
ll update(ll *tree, ll val, ll index, ll ss, ll se, ll current)
{
   if (index < ss || index > se)
   {
      return tree[current];
   }
   else
   {
      if (ss == se)
      {
         tree[current] = val;
         return tree[current];
      }
      else
      {
         tree[current] = update(tree, val, index, ss, (ss + se) / 2, current * 2 + 1) + update(tree, val, index, (ss + se) / 2 + 1, se, current * 2 + 2);
         return tree[current];
      }
   }
}

int main()
{
   ll n;
   cin >> n;
   vll v;
   ll x;
   inc(i, 0, n)
   {
      cin >> x;
      v.pb(x);
   }

   createSegTree(tree, v, 0, n - 1, 0);
   ll q;
   cin >> q;
   inc(i, 0, q)
   {
      string s;
      cin >> s;
      if (s == "present")
      {
         ll l, r;
         cin >> l >> r;
         cout << rangeAns(tree, l - 1, r - 1, 0, n - 1, 0) << endl;
      }
      else
      {
         ll l, r;
         cin >> l >> r;
         update(tree, l + v[r - 1], r - 1, 0, n - 1, 0);
         v[r - 1] = v[r - 1] + l;
      }
   }

   return 0;
}