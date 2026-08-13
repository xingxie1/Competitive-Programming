#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

int check(int a)
{
    string s = to_string(a);
    for (char c : s) if (c != '9') return 0;
    return 1;
}
void solve()
{
    ll x;
    cin >> x;
    if (check(x))
    {
        cout << 0 << endl;
        return ;
    }
    vll aa;
    ll s = 9;
    for (int i = 0;i < 18;i++)
    {
        aa.push_back(s);
        s = s * 10 + 9;
    }
    
    ll ans = LLONG_MAX;
    for (ll w : aa)
    {
        if (w < x) continue;
        if (x == w) 
        {
            ans = 0;
            break;
        }
        if (x > w / 9)
        {
            if (x % 9 == 0) ans = min(ans,(w - x) / 9);
        }
        else 
        {
            ll d = w / 9;
            ll c = (d - x) / 9;
            ll t = c + 1;
            ll y = (x + 9 * c) * 9;
            ans = min(ans,t + (w - y) / 9);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}