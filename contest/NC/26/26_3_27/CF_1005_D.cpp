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
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    vt cnt(3);
    for (int i = 0;i < n;i++)
    {
        int x = s[i] - '0';
        if (x % 3 == 0) 
        {
            ans ++;
            cnt[1] = cnt[2] = 0;
        }
        else if (x % 3 == 1) cnt[1]++;
        else if (x % 3 == 2) cnt[2]++;
        if (cnt[1] >= 1 && cnt[2] >= 1) 
        {
            ans++;
            cnt[1] = cnt[2] = 0;
        }
        if (cnt[1] >= 3)
        {
            cnt[1] = cnt[2] = 0;
            ans++;
        }
        if (cnt[2] >= 3)
        {
            cnt[1] = cnt[2] = 0;
            ans++;
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