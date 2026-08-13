#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    int l = -1,r = INT_MAX / 2;
    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;
        auto check = [&](int k)
        {
            int mn = 0,mx = 0;
            for (auto& [L, R] : a)
            {
                mx = mx + k;
                mn = mn - k;
                mx = min(mx,R);
                mn = max(mn,L);
                if (mn > mx) return 0;
            }
            return 1;
            cout << k << endl;
        };
        if (check(m)) r = m;
        else l = m;
    }
    cout << r << endl;
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