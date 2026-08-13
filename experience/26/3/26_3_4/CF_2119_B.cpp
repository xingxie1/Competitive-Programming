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
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    int px,py,qx,qy;
    cin >> px >> py >> qx >> qy;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int R = accumulate(a.begin(),a.end(),0);
    int mx = ranges::max(a);
    ll dis = 1LL * (px - qx) * (px - qx) + 1LL * (py - qy) * (py - qy);
    int r = max(mx - (R - mx),0);
    if (dis >= 1LL * r * r && dis <= 1LL * R * R) cout << "Yes" << endl;
    else cout << "No" << endl;
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