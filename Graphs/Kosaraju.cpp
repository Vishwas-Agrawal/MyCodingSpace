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
vll graph1[200005], graph2[200005];
vll visited(200005, false);
stack<ll> ss;
void addEdge(vll graph[], ll u, ll v)
{
    graph[u].pb(v);
}
void dfs1(ll current)
{
    visited[current] = true;
    for (auto i : graph1[current])
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }
    ss.push(current);
}
void dfs2(ll current, vll &component)
{
    visited[current] = true;
    component.pb(current);
    for (auto i : graph2[current])
    {
        if (!visited[i])
        {
            dfs2(i, component);
        }
    }
}
int main()
{
    fio;
    ll n;
    cin >> n;
    ll m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll l, r;
        cin >> l >> r;
        addEdge(graph1, l, r);
        addEdge(graph2, r, l);
    }
    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }
    visited.assign(200005, false);
    while (!ss.empty())
    {
        vll v;
        ll x = ss.top();
        ss.pop();
        if (!visited[x])
        {
            dfs2(x, v);
        }
        //vector v contains the strongly connected components
    }

    return 0;
}