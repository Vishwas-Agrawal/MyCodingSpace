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

/*if you want to find the next occurences of the numbers in the array from index i then iterate the array in
reverse order then keep track of the pos[a[i]]*/
vll prefix_function(string s)
{
    ll n = (ll)s.length();
    vll pi(n);
    for (ll i = 1; i < n; i++)
    {
        ll j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int main()
{
    fio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif

    return 0;
}