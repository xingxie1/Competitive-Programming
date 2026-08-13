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
    map<int,int> c1,c2,c3,c4;
    for (int i = 0;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        c1[x]++;
        c2[y]++;
        c3[x + y]++;
        c4[y - x]++;
    }
    auto f = [&](map<int,int> c)
    {
        ll ret = 0;
        for (auto& [x,c0] : c)
        {
            ret += 1LL * (c0 - 1) * c0;
        }
        return ret;
    };
    ll ans = f(c1) + f(c2) + f(c3) + f(c4);
    cout << ans << endl;
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