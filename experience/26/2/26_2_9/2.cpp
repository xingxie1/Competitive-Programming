#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    map<int,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int q;
    cin >> q;
    auto check = [&](ll x) ->bool
    {
        if (x < 0) return false;
        ll r = round(sqrt(x));
        return r * r == x;
    };
    while (q--)
    {
        ll x,y;
        cin >> x >> y;
        ll t = 1LL * x * x - 4 * y;
        if (!check(t)) 
        {
            cout << 0 << " ";
            continue;
        }
        ll a1 = x + sqrt(t),a2 = x - sqrt(t);
        if (a1 % 2) 
        {
            cout << 0 << " ";
            continue;
        }
        a1 /= 2;
        a2 /= 2;
        ll b1 = x - a1;
        ll b2 = x - a2;
        ll ans = 0;
        if (cnt.count(a1) && cnt.count(b1)) 
        {
            if (a1 == b1) ans += 1LL * cnt[a1] * (cnt[a1] - 1) / 2;
            else ans += 1LL * cnt[a1] * cnt[b1];
        }
        if (cnt.count(a2) && cnt.count(b2)) 
        {
            if (a2 == b2) ans += 1LL * cnt[a2] * (cnt[a2] - 1) / 2;
            else ans += 1LL * cnt[a2] * cnt[b2];
        }
        cout << ans / 2 << " ";
    }
    cout << endl;
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