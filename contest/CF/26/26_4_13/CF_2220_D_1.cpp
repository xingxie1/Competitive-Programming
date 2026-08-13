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
// #define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    int l = 0,r = 2 * n + 2;
    vt ans;
    auto check = [&](int p,vt& a)
    {
        int k = p;
        cout << "? " << k + a.size() << " ";
        for (int i = 1;i <= k;i++) cout << i << " ";
        for (int x : a) cout << x << " ";
        cout << endl;
        int ret;
        cin >> ret;
        return (k + a.size() - ret) % 2; 
    };
    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;
        if (check(m,ans)) r = m;
        else l = m;
    }
    ans.push_back(r);
    l = 0;
    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;
        if (check(m,ans)) r = m;
        else l = m;
    }
    ans.push_back(r);
    l = 0;
    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;
        if (check(m,ans)) r = m;
        else l = m;
    }
    ans.push_back(r);
    cout << "! " << ans[0] << " " << ans[1] << " " << ans[2] << endl;
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