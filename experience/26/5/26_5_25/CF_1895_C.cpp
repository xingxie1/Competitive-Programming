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
    vector<string> a(n);
    vvll cnt(6,vll(50));
    auto f = [&](string& s) 
    {
        int sum = 0;
        for (char c : s) sum += c - '0';
        return sum;
    };
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        int len = a[i].size();
        cnt[len][f(a[i])]++;
    }
    ll ans = 0;
    for (auto& s : a) 
    {
        int x = f(s);
        int len = s.size();
        if (len == 1) 
        {
            ans += cnt[1][x];
        }
        else if (len == 2) 
        {
            ans += cnt[2][x];
        }
        else if (len == 3) 
        {
            ans += cnt[3][x]; 
            int x1 = s[0] - '0';
            int x2 = s.back() - '0';
            int t1 = x - 2 * x1;
            int t2 = x - 2 * x2;
            if (t1 > 0) ans += cnt[1][t1];
            if (t2 > 0) ans += cnt[1][t2];
        }
        else if (len == 4) 
        {
            ans += cnt[4][x];
            int x1 = s[0] - '0';
            int x2 = s.back() - '0';
            int t1 = x - 2 * x1;
            int t2 = x - 2 * x2;
            if (t1 > 0) ans += cnt[2][t1];
            if (t2 > 0) ans += cnt[2][t2];
        }
        else if (len == 5)
        {
            ans += cnt[5][x];
            int x1 = s[0] - '0';
            int x2 = s.back() - '0';
            int t1 = x - 2 * x1;
            int t2 = x - 2 * x2;
            if (t1 > 0) ans += cnt[3][t1];
            if (t2 > 0) ans += cnt[3][t2];
            x1 = s[0] - '0' + s[1] - '0';
            x2 = s.back() - '0' + s[len - 2] - '0';
            t1 = x - 2 * x1;
            t2 = x - 2 * x2;
            if (t1 > 0) ans += cnt[1][t1];
            if (t2 > 0) ans += cnt[1][t2];
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