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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    int n, m;
    cin >> n >> m;
    vpii a(n);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    ranges::sort(a);
    vpii ans;
    if (m == 0)
    {
        vll suf (n + 1);
        int j = -1;
        for (int i = n - 2;i >= 0;i--) 
        {
            suf[i] = suf[i + 1] + a[i].fi;
            if (suf[i] >= a[n - 1].fi && j == -1) j = i; 
        }
        if (j == -1) 
        {
            cout << -1 << endl;
            return ;
        }
        for (int i = 0;i < j;i++) 
        {
            ans.push_back({a[i].se,a[i + 1].se});
        }
        for (int i = j + 1;i < n - 1;i++) 
        {
            ans.push_back({a[i].se,a[n - 1].se});
        }
        ans.push_back({a[j].se,a[n - 1].se});
    }
    else if (m * 2 > n)
    {
        cout << -1 << endl;
        return ;
    }
    else 
    {
        int l = n - 2 * (m - 1) - 1,r = n - 2;
        while (l < r)
        {
            ans.push_back({a[r].se,a[l].se});
            l++;
            r--;
        }
        l = n - 2 * (m - 1) - 2;
        int i = 0;
        while (i < l)
        {
            ans.push_back({a[i].se,a[i + 1].se});
            i++;
        }
        ans.push_back({a[n - 1].se,a[l].se});
    }
    cout << ans.size() << endl;
    for (auto& [l,r] : ans) cout << l << " " << r << endl;
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