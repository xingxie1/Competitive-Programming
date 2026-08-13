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
    string s;
    cin >> s;
    if (n % 2) 
    {
        cout << -1 << endl;
        return ;
    }
    vt cnt(26);
    for (char c : s) cnt[c - 'a']++;
    if (ranges::max(cnt) > n / 2)
    {
        cout << -1 << endl;
        return ;
    }
    for (int& x : cnt) x = 0;
    for (int i = 0;i < n / 2;i++)
    {
        if (s[i] == s[n - i - 1]) 
        {
            cnt[s[i] - 'a']++;
        }
    }
    int mx = ranges::max(cnt);
    int sum = accumulate(cnt.begin(),cnt.end(),0);
    int ans = max((sum + 1) / 2,mx);
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