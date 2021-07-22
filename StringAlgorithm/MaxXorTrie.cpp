#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define test  \
    ll t;     \
    cin >> t; \
    while (t--)
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const ll INF = 1000000000000000000;
#define debug(v, n)             \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << v[i] << " ";    \
    }                           \
    cout << "\n";
#define fill(a, n, v)           \
    for (int i = 0; i < n; i++) \
        a[i] = v;
#define fill1(a, n, m, v)           \
    for (int i = 0; i < n; i++)     \
    {                               \
        for (int j = 0; j < m; j++) \
            a[i][j] = v;            \
    }

struct Node
{
    Node *child[2];
    int onpath;
    Node()
    {
        child[0] = child[1] = NULL;
        onpath = 0;
    }
};

struct Trie
{
    Node *root;
    Trie(Node *temp)
    {
        root = temp;
    }

    void add(string num)
    {
        Node *curr = root;
        for (char bit : num)
        {
            int z = (bit == '1') ? 1 : 0;
            if (!curr->child[z])
                curr->child[z] = new Node;
            curr = curr->child[z];
            curr->onpath++;
        }
    }

    ll findmaxxor(string num)
    {
        Node *curr = root;
        ll val = 0;
        for (char i : num)
        {
            if (!curr)
            {
                val *= 2;
                continue;
            }
            int z = (i == '1') ? 0 : 1;
            if (curr->child[z])
            {
                curr = curr->child[z];
                val = val * 2 + 1;
            }
            else
            {
                curr = curr->child[z ^ 1];
                val *= 2;
            }
        }
        return val;
    }

    void del(string num)
    {
        Node *curr = root;
        for (char bit : num)
        {
            int z = (bit == '1') ? 1 : 0;
            if (curr->child[z]->onpath == 1)
            {
                curr->child[z] = NULL;
                break;
            }
            curr = curr->child[z];
            curr->onpath--;
        }
    }
};

int main()
{
    fio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Node *temp = new Node;
    Trie *z = new Trie(temp);
    ll xr = 0;
    z->add(string(40, '0'));
    for (int i = n - 1; i >= 0; i--)
    {
        xr ^= a[i];
        z->add(bitset<40>(xr).to_string());
    }
    ll ans = z->findmaxxor(string(40, '0'));
    xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr ^= a[i];
        ans = max(ans, z->findmaxxor(bitset<40>(xr).to_string()));
    }
    cout << ans << "\n";
    return 0;
}