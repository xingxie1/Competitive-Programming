#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
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
    vt a(n);
    pqueue<pii> pq;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        if (a[i]) pq.push({a[i],i});
    }
    vpii ans;
    while (pq.size() > 1) 
    {
        auto [c1,i1] = pq.top();
        pq.pop();
        auto [c2,i2] = pq.top();
        pq.pop();
        if (c1 == 0 || c2 == 0) break;
        c1--;c2--;
        ans.push_back({i1,i2});
        if (c1) pq.push({c1,i1});
        if (c2) pq.push({c2,i2});
    }
    cout << ans.size() << endl;
    for (auto & [l, r] : ans) cout << l + 1 << " " << r + 1 << endl;
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