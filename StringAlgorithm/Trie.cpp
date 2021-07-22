//by the authority of GOD  author manhar singh sachdev//
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
    map<char, Node *> child;
    bool isend = 0;
};

struct Trie
{
    Node *root;
    Trie(Node *temp)
    {
        root = temp;
    }
    int add(string word, int k, string ch)
    {
        Node *curr = root;
        int ans = 0;
        for (char letter : word)
        {
            if (ch[letter - 'a'] == '0')
                k--;
            if (k < 0)
                return ans;
            if (!curr->child[letter])
                curr->child[letter] = new Node;
            curr = curr->child[letter];
            if (!curr->isend)
            {
                curr->isend = 1;
                ans++;
            }
        }
        return ans;
    }
    bool isin(string word)
    {
        Node *curr = root;
        for (char letter : word)
        {
            if (!curr->child[letter])
                return false;
            curr = curr->child[letter];
        }
        return curr->isend;
    }
    void del(string word)
    {
        Node *curr = root;
        for (char letter : word)
            curr = curr->child[letter];
        curr->isend = 0;
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
    string s;
    cin >> s;
    string ch;
    cin >> ch;
    int k;
    cin >> k;
    int ans = 0;
    Trie *z = new Trie(new Node);
    for (int i = 0; i < s.size(); i++)
        ans += z->add(s.substr(i, s.size() - i), k, ch);
    cout << ans << "\n";
    return 0;
}