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
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ranges::sort(a);
    vll pre(n + 1),suf(n + 1);
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] + a[i];
    for (int i = n - 1;i >= 0;i--) suf[i] = suf[i + 1] + a[i];
    ll ans = LLONG_MAX;
    int j = 0;
    for (int i = 0;i < n;i++)
    {
        int x = a[i];
        ll add = 1LL * i * x - pre[i],mn = suf[i + 1] - 1LL * (n - i - 1) * x;
        if (add >= mn) 
        {
            j = i;
            ans = add;
            break;
        }
    }   
    if (j == 0)
    {
        cout << ans << endl;
        return ;
    }

    int l = a[j - 1] - 1,r;
    if (j < n - 1) r = a[j + 1] + 1;
    else r = a[j] + 1;
    auto check = [&](ll x)
    {
        ll add = 1LL * j * x - pre[j],mn = suf[j + 1] - 1LL * (n - j - 1) * x;
        if (x < a[j]) mn += a[j] - x;
        else if (x > a[j]) add += x - a[j];
        if (add >= mn) 
        {
            ans = min(ans,add);
            return 1;
        }
        return 0;
    };
    while (l + 1 < r)
    {
        ll m = l + (r - l) / 2;
        if (check(m)) r = m;
        else l = m;
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