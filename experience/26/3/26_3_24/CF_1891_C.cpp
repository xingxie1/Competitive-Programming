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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ranges::sort(a);
    int l = 0,r = n - 1;
    ll ans = 0,cnt = 0;
    while (l <= r)
    {
        if (l == r)
        {
            int x = (a[l] - cnt) / 2;
            cnt += x;
            ans += x;
            a[r] -= cnt;
            a[r] -= x;
            if (cnt > 0) ans++;
            cnt = 0;
            ans += a[r];
            break;
        }
        if (cnt + a[l] < a[r])
        {
            cnt += a[l];
            ans += a[l];
        }
        else 
        {
            int d = a[r] - cnt;
            ans += d;
            a[l] -= d;
            ans++;
            r--;
            cnt = 0;
            if (l == r)
            {
                int x = a[l] / 2;
                cnt += x;
                ans += x;
                a[r] -= cnt;
                a[r] -= x;
                if (cnt > 0) ans++;
                ans += a[r];
                break;
            }
            ans += a[l];
            cnt += a[l];
        }
        l++;
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