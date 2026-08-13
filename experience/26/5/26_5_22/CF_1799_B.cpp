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
    for (int i = 0;i < n;i++) cin >> a[i];
    vt b = a;
    ranges::sort(b);
    if (n == 1 || b[0] == b.back()) 
    {
        cout << 0 << endl;
        return ;
    }
    int mni = 0;
    for (int i = 0;i < n;i++) 
    {
        if (a[i] < a[mni]) mni = i;
    }
    if (a[mni] == 1) 
    {
        cout << -1 << endl;
        return ;
    }
    vpii ans;
    while (1) 
    {
        int mxi = 0,mni = 0;
        for (int i = 0;i < n;i++)
        {
            if (a[i] < a[mni]) mni = i;
            if (a[i] > a[mxi]) mxi = i;
        }
        if (mni == mxi) break;
        a[mxi] = (a[mxi] + a[mni] - 1) / a[mni];
        ans.push_back({mxi,mni});
    }
    cout << ans.size() << endl;
    for (auto& [l,r] : ans) cout << l + 1 << " " << r + 1 << endl;
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