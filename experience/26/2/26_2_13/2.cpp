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
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int ans = ranges::max(a);
    int l = 0,r = INT_MAX;
    auto check = [&](int x)
    {
        for (int i = 0;i < n;i++)
        {
            if (a[i] >= x) return 1;
            int s = x - a[i],t = x;
            if (s > k) continue;
            for (int j = i + 1;j < n;j++)
            {
                if (a[j] >= t - 1) return 1;
                t--;
                s += (t - a[j]);
                if (s > k) break;
            }
        }
        return 0;
    };
    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << endl;
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