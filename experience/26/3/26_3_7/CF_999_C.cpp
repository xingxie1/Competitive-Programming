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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vt cnt(26),pre(27);
    for (char c : s) cnt[c - 'a']++;
    for (int i = 0;i < 26;i++) pre[i + 1] = pre[i] + cnt[i];
    auto j = ranges::lower_bound(pre,k) - pre.begin();
    j--;
    int res = k - pre[j];
    string ans;
    for (char c : s)
    {
        if (pre[c - 'a' + 1] > k && pre[c - 'a'] >= k) ans += c;
        else if (pre[c - 'a' + 1] > k && pre[c - 'a'] < k)
        {
            if (res <= 0) ans += c;
            res--;
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