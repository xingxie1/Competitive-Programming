#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    auto check = [&](int x)
    {
        ll l = -1,r = 1e4;
        while (l + 1 < r)
        {
            ll m = l + (r - l) / 2;
            if (m * (m + 1) / 2 > x) r = m;
            else l = m;
        }
        return l * (l + 1) / 2 == x;
    };
    if (check(n))
    {
        ll ans = 0,cnt = 1;
        for (int i = 1;;i++)
        {
            if (cnt > n) break;
            ans += cnt * cnt;
            cnt += i + 1;
        }
        cout << ans << endl;
        return ;
    }
    vll pre(3e5 + 1);
    for (int i = 1;i <= 3e5;i++) pre[i] = pre[i - 1] + i * i;
    ll l = -1,r = 1e4;
    while (l + 1 < r)
    {
        ll m = l + (r - l) / 2;
        if (m * (m + 1) / 2 > n) r = m;
        else l = m;
    }
    int d = l + 1;
    int L = n,R = n;
    ll ans = 0;
    for (int i = d;i >= 1;i--)
    {
        if (R - L == i) 
        {
            // cout << "@@@@@" << R << endl;
            ans += pre[R] - pre[L - 1];
            break;
        }
        for (int j = L;j <= R;j++) ans += 1LL * j * j;
        if (check(L - 1)) L = L - i + 1;
        else L = L - i;
        if (check(R)) R = R - i;
        else R = R - i + 1;
    }
    // cout << d << endl;
    cout << ans << endl;
    // cout << endl;
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