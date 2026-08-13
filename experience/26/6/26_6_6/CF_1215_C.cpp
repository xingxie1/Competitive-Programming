#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> ab, ba;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[i]) continue;

        if (s[i] == 'a' && t[i] == 'b') ab.push_back(i + 1);
        else ba.push_back(i + 1);
    }
    if ((ab.size() + ba.size()) % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }
    vpii ans;
    for (int i = 0; i + 1 < ab.size(); i += 2)
    {
        ans.push_back({ab[i], ab[i + 1]});
    }
    for (int i = 0; i + 1 < ba.size(); i += 2)
    {
        ans.push_back({ba[i], ba[i + 1]});
    }
    if (ab.size() % 2 == 1)
    {
        int x = ab.back();
        int y = ba.back();

        ans.push_back({x, x});
        ans.push_back({x, y});
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans)
    {
        cout << x << " " << y << endl;
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