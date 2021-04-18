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
#define pb push_back
#define mp make_pair
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
vll primes(10000001, 1);
void countPrimes(vll &primes, ll n)
{
    primes[0] = 0;
    primes[1] = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        for (ll j = i * i; j <= n; j += i)
        {
            primes[j] = 0;
        }
    }
}

int main()
{
    ll n;
    cin >> n;

    countPrimes(primes, 10000000LL);
    ll count = 0;
    for (int i = 1; i < 10000001; i++)
    {

        if (primes[i] == 1)
        {
            count++;
            if (count > n)
            {

                break;
            }
            cout << i << endl;
        }
    }

    return 0;
}