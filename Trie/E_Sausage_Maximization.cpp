#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const ll MX = 2e5 + 5;
inline void norm(ll &a)
{
    a %= mod;
    (a < 0) && (a += mod);
} // positive mod value
inline ll modAdd(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a + b) % mod;
} // modular addition
inline ll modSub(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a - b) % mod;
} // modular subtraction
inline ll modMul(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a * b) % mod;
} // modular multiplication
inline ll bigMod(ll b, ll p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1LL)
            r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1LL;
    }
    return r;
}
inline ll modInverse(ll a) { return bigMod(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

struct node
{
    bool endmark;
    node *next[3];
    node()
    {
        endmark = false;
        for (int i = 0; i < 3; i++)
            next[i] = NULL;
    }
} *root;

void insert(string &str, int len)
{
    node *curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}

vector<ll> search(string &str, int len)
{
    node *curr = root;
    vector<ll> ans;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - '0';
        if (id == 0)
        {
            if (curr->next[0])
            {
                ans.push_back(0);
                curr = curr->next[0];
            }
            else
            {
                ans.push_back(1);
                curr = curr->next[1];
            }
        }
        else
        {
            if (curr->next[1])
            {
                ans.push_back(1);
                curr = curr->next[1];
            }
            else
            {
                ans.push_back(0);
                curr = curr->next[0];
            }
        }
    }
    return ans;
}

string to_binary(int n)
{
    string s = "";
    for (int i = 0; i < 32; i++)
    {
        s += to_string(n % 2);
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 1; i < n; i++)
        v[i] = v[i] ^ v[i - 1];

    ll ansMin = v[0];
    root = new node(); 
    string ss = to_binary(ansMin); 
    insert(ss, ss.length()); 
    for (int i = 1; i < n; i++)
    {
        string s = to_binary(v[i]);
        vector<ll> ans = search(s, s.length());
        ll r = 0;
        ll t = 1;
        for (int j = 31; j >= 0; j--)
        {
            r += (ans[j] * t);
            t *= 2;
        }
        insert(s, s.length()); 
        ansMin = min(ansMin, r ^ v[i]);
    }
    ll xx = 1^3; 
    cout << xx << endl; 
    cout << max(v[n-1], v[n-1] ^ ansMin) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}