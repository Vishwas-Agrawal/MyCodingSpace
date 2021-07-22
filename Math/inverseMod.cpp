#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vll vector<ll>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define M 1000000007LL
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
ll inv[1000001], fact[1000001];
int main()
{
    for (ll i = 1; i <= 1000001; i++)
        if (i == 1)
            fact[i] = 1;
        else
            fact[i] = fact[i - 1] * i % M;
    inv[1000000] = binpow(fact[1000000], M - 2, M);
    for (ll i = 999999; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % M;
    ll n;
    cin >> n;
    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        cout << fact[x] * inv[y] % M * inv[x - y] % M << endl;
    }
}
