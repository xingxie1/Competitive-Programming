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
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,H,A;
    cin >> n >> H >> A;
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi;
    for (int i = 0;i < n;i++) cin >> a[i].se;
    ranges::sort(a,{},[&](auto& b){
        return pair{b.fi,-b.se};
    });
    vt b;
    for (int i = 0;i < n;i++)
    {
        if (a[i].fi >= H) break;
        if (a[i].se < A) b.push_back(a[i].se);
    }
    vt g;
    for (int x : b)
    {
        auto it = ranges::lower_bound(g,x);
        if (it == g.end()) g.push_back(x);
        else *it = x;
    }
    cout << g.size();
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