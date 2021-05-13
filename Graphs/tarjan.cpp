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
#define test  \
    ll t;     \
    cin >> t; \
    while (t--)
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define M 1000000007LL
#define input(v, n) \
    inc(i, 0, n)    \
    {               \
        ll x;       \
        cin >> x;   \
        v.pb(x);    \
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
//bitwise operator precedence is less than != and ==
// a%M(a%=M) is not a syntax error
//count(all(v),3) counts the number of 3 in vector
//lower_bound if x not present points to next greater element
//upper_bound return first element in the range which has value greater than given value
vll disc(100005, -1);
ll low[100005], timeX, instack[100005];
vll adj[100005];
stack<ll> s;
vector<vll> components;
void dfs(ll cur)
{
    cout << cur << endl;
    disc[cur] = low[cur] = timeX++;
    s.push(cur);
    instack[cur] = 1;
    for (auto j : adj[cur])
    {
        if (disc[j] == -1)
        {
            dfs(j);
            low[cur] = min(low[cur], low[j]);
        }
        else if (instack[j] == 1)
        {
            low[cur] = min(low[cur], low[j]);
        }
    }
    if (disc[cur] == low[cur])
    {
        vll scc;
        while (1)
        {
            ll temp = s.top();
            s.pop();
            instack[temp] = 0;
            scc.pb(temp);
            if (cur == temp)
            {
                break;
            }
        }
        components.pb(scc);
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
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (disc[i] == -1)
        {
            dfs(i);
        }
    }
    cout << "SCCs are-" << endl;
    for (auto i : components)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}