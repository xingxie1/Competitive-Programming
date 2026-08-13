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
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> a(n);
    vll suf(n + 1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin(),a.end());
    for (int i = n - 1;i >= 0;i--)
    {
        suf[i] = suf[i + 1] + a[i].fi;
    }
    vll ans(n);
    for (int i = 0;i < n;i++)
    {
        auto j = lower_bound(a.begin(), a.end(), pair{m + 1 - a[i].fi, -1}) - a.begin();
        j--;
        // cout << a[j].fi << endl;
        if (j < i)
        {
            ans[i] += 1LL * (j + 1) * a[i].fi;
            ans[i] -= suf[j + 1];
            ans[i] += a[i].fi;
        }
        else 
        {
            ans[i] += 1LL * j * a[i].fi;
            ans[i] -= suf[j + 1];
            // cout << j << " " << suf[j + 1] << endl;
        }
    }
    vll tmp(n);
    for (int i = 0;i < n;i++)
    {
        int j = a[i].se;
        tmp[j] = ans[i];
    }
    for (ll x : tmp) cout << x << " ";
    // cout << endl;
    // for (int x : ans) cout << x << " ";
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