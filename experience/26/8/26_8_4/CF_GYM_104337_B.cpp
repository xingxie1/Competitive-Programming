#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
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
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

vector<umap<ll,ll>> memo(20);
long long digitDP(long long low, long long high) {
    string low_s = to_string(low);
    string high_s = to_string(high);
    int n = high_s.size();
    int diff_lh = n - low_s.size();
    vt cnt(10);

    auto dfs = [&](this auto&& dfs, int i, bool limit_low, bool limit_high) -> long long {
        if (i == n) {
            return ranges::max(cnt);
        }
        auto get = [&](vt cc)
        {
            ranges::sort(cc);
            ll id = 0;
            for (int x : cc) id = id * 20 + x;
            return id;
        };
        int left = n - i;
        ll state = 0;
        if (!limit_low && !limit_high) {
            state = get(cnt);
            if (memo[left].contains(state)) return memo[left][state];
        }
        int lo = limit_low && i >= diff_lh ? low_s[i - diff_lh] - '0' : 0;
        int hi = limit_high ? high_s[i] - '0' : 9;

        long long res = 0;
        int d = lo;

        // 通过 limit_low 和 i 可以判断能否不填数字，无需 is_num 参数
        // 如果前导零不影响答案，去掉这个 if block
        if (limit_low && i < diff_lh) {
            // 不填数字，上界不受约束
            res = dfs(i + 1, true, false);
            d = 1;
        }

        for (; d <= hi; d++) {
            cnt[d]++;
            res += dfs(i + 1, limit_low && d == lo, limit_high && d == hi);
            cnt[d]--;
        }

        if (!limit_low && !limit_high) {
            memo[left][state] = res;
        }
        return res;
    };

    return dfs(0, true, true);
}

void solve()
{
    ll l,r;
    cin >> l >> r;
    cout << digitDP(l,r) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}