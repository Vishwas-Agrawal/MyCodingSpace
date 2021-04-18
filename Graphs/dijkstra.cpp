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
bool mark[MAXN];
ll d[MAXN];
ll n;
ll inf = 1e18;
vpll adj[MAXN];
void dijkstra(ll v)
{
    fill(d, d + n + 1, inf);
    fill(mark, mark + n + 1, false);
    d[v] = 0;
    ll u;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({d[v], v});
    while (!pq.empty())
    {
        u = pq.top().second;
        pq.pop();
        if (mark[u])
        {
            continue;
        }
        mark[u] = true;
        for (auto p : adj[u])
        {
            if (d[p.first] > d[u] + p.second)
            {
                // cout << p.first << " " << u << " " << d[u] + p.second << endl;
                d[p.first] = d[u] + p.second;
                pq.push({d[p.first], p.first});
            }
        }
    }
}

int main()
{
    fio;
    cin >> n;
    ll m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll u, r, c;
        cin >> u >> r >> c;
        adj[u].pb({r, c});
        adj[r].pb({u, c});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }

    return 0;
}