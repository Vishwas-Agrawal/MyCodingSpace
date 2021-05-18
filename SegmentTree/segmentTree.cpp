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

struct s
{
   ll val;
   ll left;
   ll right;
   ll sum;
};
s tree[400000];
s createSegTree(s *tree, vll &given, ll ss, ll se, ll current)
{
   if (ss == se)
   {
      s temp;
      temp.val = given[ss];
      temp.left = given[ss];
      temp.right = given[ss];
      temp.sum = given[ss];
      tree[current] = temp;
      return tree[current];
   }
   else
   {
      s first = createSegTree(tree, given, ss, (ss + se) / 2, current * 2 + 1);
      s second = createSegTree(tree, given, (ss + se) / 2 + 1, se, current * 2 + 2);
      tree[current].val = max({first.val, second.val, first.right + second.left});
      tree[current].left = max({first.sum + second.left, first.left});
      tree[current].right = max({second.right, second.sum + first.right});
      tree[current].sum = first.sum + second.sum;
      return tree[current];
   }
}
ll rangeAns(s *tree, ll l, ll r, ll ss, ll se, ll current)
{
   if (ss >= l && se <= r)
   {
      return tree[current].val;
   }
   else
   {
      if (ss > r || se < l)
      {
         return 0;
      }
      else
      {
         return max(rangeAns(tree, l, r, ss, (ss + se) / 2, current * 2 + 1), rangeAns(tree, l, r, (ss + se) / 2 + 1, se, current * 2 + 2));
      }
   }
}
s update(s *tree, ll val, ll index, ll ss, ll se, ll current)
{
   if (index < ss || index > se)
   {
      return tree[current];
   }
   else
   {
      if (ss == se)
      {
         s temp;
         temp.val = val;
         temp.left = val;
         temp.right = val;
         temp.sum = val;
         tree[current] = temp;
         return tree[current];
      }
      else
      {
         s first = update(tree, val, index, ss, (ss + se) / 2, current * 2 + 1);
         s second = update(tree, val, index, (ss + se) / 2 + 1, se, current * 2 + 2);
         tree[current].val = max({first.val, second.val, first.right + second.left});
         tree[current].left = max({first.sum + second.left, first.left});
         tree[current].right = max({second.right, second.sum + first.right});
         tree[current].sum = first.sum + second.sum;
         return tree[current];
      }
   }
}

int main()
{
   fio;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("Error.txt", "w", stderr);
#endif
   ll n, m;
   cin >> n >> m;
   vll v;
   input(v, n);
   createSegTree(tree, v, 0, n - 1, 0);
   if (tree[0].val >= 0)
   {
      cout << tree[0].val << endl;
   }
   else
   {
      cout << 0 << endl;
   }
   for (int i = 0; i < m; i++)
   {
      ll index, val;
      cin >> index >> val;
      update(tree, val, index, 0, n - 1, 0);
      if (tree[0].val >= 0)
      {
         cout << tree[0].val << endl;
      }
      else
      {
         cout << 0 << endl;
      }
   }

   return 0;
}