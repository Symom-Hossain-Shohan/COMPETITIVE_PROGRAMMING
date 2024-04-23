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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    // set<ll> st;
    // for(int i=0;i<n; i++)
    // {
    //     st.insert(v[i]);
    //     v[i] %= 2;
    // }

    set<ll> divisors;

    // divisors.push_back(1);
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }

    ll ans = 0;
    for (auto i : divisors)
    {
        ll div = i;
        // cout << div << ' ';

        ll g = 0;
        for (int j = 0; j + div < n; j++)
        {
            g = __gcd(g, abs(v[j] - v[j + div]));
        }
        if (g != 1)
            ans++;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}