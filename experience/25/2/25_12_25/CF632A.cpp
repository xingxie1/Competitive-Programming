// https://codeforces.com/problemset/problem/632/A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,p;
    cin >> n>> p;
    ll ans = 0;
    vector<string>ss;
    while (n--)
    {
        string s;
        cin >> s;
        ss.push_back(s);
    }
    n = ss.size();
    ll cur = 0;
    for (int i = n - 1;i >= 0;i--)
    {
        if (ss[i] == "halfplus")
        {
            cur = 1LL * cur * 2 + 1;
            ans += 1LL * cur / 2 * p + p / 2;
        }   
        else 
        {
            cur = 1LL * cur * 2;
            ans += 1LL * cur / 2 * p;
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