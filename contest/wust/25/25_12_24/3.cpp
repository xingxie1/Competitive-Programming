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

void solve()
{
    int q;
    cin >> q;
    while (q--)
    {
        ll n,m;
        cin >> n >> m;
        vector<int> have;
        ll cnt = 0,mx = 0;
        for (int i = 1;;i++)
        {
            ll x = 1LL * (m * i) % 10;
            if (1LL * m * i > n) break;
            int flag = 0;
            for (int y : have)
            {
                if (x == y) flag = 1;
            }
            if (flag) break;
            mx = 1LL * m * i;
            cnt++;
            have.push_back(x);
        }
        ll ans = 0 ;
        ll sum = 0;
        for (auto x : have) sum += x;
        if (mx >= n) cout << sum << endl;
        else 
        {
            if (mx == 0) 
            {
                cout << 0 << endl;
                continue;
            }
            ans = n / (m * cnt) * sum;
            ll res = (n - n / mx * mx) / m;
            // res--;
            // cout << res << endl;
            // cout <<  mx ;

            for (auto x : have)
            {
                if (res <= 0) break;
                ans += x;
                res--;
            }
            cout << ans << endl;
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}