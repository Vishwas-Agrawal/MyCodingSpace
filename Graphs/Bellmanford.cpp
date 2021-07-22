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
const int MAXN = 1e6;
ll d[MAXN];
ll n, m, inf = 1e9, src, u, v, wt;
vector<pair<pll, ll>> edges;
int main()
{
    fio;
    cin >> n >> m >> src;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        edges.pb({{u, v}, wt});
    }
    for (int i = 0; i <= n; i++)
        d[i] = inf;
    d[src] = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            if (d[edges[j].fi.fi] < inf)
                d[edges[j].fi.se] = min(d[edges[j].fi.se], d[edges[j].fi.fi] + edges[j].se);
    bool neg = false;
    for (int j = 0; j < m; j++)
        if (d[edges[j].fi.fi] + edges[j].se < d[edges[j].fi.se])
            neg = true;
    if (neg)
        cout << "Negative Cycle Detected" << endl;
    else
    {
        for (int i = 1; i <= n; i++)
            cout << d[i] << " ";
        cout << endl;
    }
    return 0;
}