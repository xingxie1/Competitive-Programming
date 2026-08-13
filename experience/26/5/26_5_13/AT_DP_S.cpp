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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
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
const int MOD = (int)1e9+7;

long long digitDP(string low, string high, int D) {
    string low_s = low;
    string high_s = high;
    int n = high_s.size();
    int diff_lh = n - low_s.size();
    vector memo(n, vector<long long>(D, -1));

    auto dfs = [&](this auto&& dfs, int i, int res, bool limit_low, bool limit_high) -> long long {
        if (i == n) {
            return res == 0;
        }

        if (!limit_low && !limit_high && memo[i][res] >= 0) {
            return memo[i][res];
        }

        int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] - '0' : 0;
        int hi = limit_high ? high_s[i] - '0' : 9;

        long long ans = 0;
        int d = lo;


        for (; d <= hi; d++) {
            // 统计 0 的个数
            ans += dfs(i + 1, (res + d) % D, limit_low && d == lo, limit_high && d == hi);
            ans %= MOD;
        }

        if (!limit_low && !limit_high) {
            memo[i][res] = ans;
        }
        return ans;
    };

    return dfs(0, 0, true, true);
}

void solve()
{
    string s;
    cin >> s;
    int d;
    cin >> d;
    cout << digitDP("1",s,d) << endl;
    
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