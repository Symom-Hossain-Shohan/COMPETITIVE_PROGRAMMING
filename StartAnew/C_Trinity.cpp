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
    sort(v.begin(), v.end());

    ll ans = 1e18;
    for (int i = 0; i < n - 2; i++)
    {
        ll l = i + 2, r = n - 1;

        ll rgt = -1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;

            if (v[i] + v[i + 1] > v[mid])
            {
                rgt = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        // cout << i << ' ' << rgt << endl;
        if (rgt != -1)
        {
            ans = min(ans, n - (rgt - i + 1));
        }
    }
    if (ans == 1e18)
        cout << n-2 << endl;
    else
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