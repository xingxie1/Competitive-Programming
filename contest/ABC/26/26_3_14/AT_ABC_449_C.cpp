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
    int n,L,R;
    cin >> n >> L >> R;
    string s;
    cin >> s;
    ll ans = 0;
    unordered_map<char,vt> p;
    for (int i = 0;i < n;i++)
    {
        p[s[i]].push_back(i);
    }
    for (auto& [c,g] : p)
    {
        for (int i = 1;i < g.size();i++)
        {
            int j = g[i];
            auto it1 = ranges::lower_bound(g.begin(),g.begin() + i,j - R);
            auto it2 = ranges::upper_bound(g.begin(),g.begin() + i,j - L);
            it2--;
            if (it2 - it1 >= 0) ans += it2 - it1 + 1;
        }
    }
    cout << ans << endl;
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