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
    string s;
    cin >> s;
    int n = s.size();
    ll pre = 0,ans = 0,pre1 = 0;
    umap<int,vector<int>> cnt;
    cnt[0].push_back(0);
    for (int i = 0;i < n;i++)
    {
        int x = 1;
        if (s[i] == '0') x = -1;
        pre += x;
        cnt[pre].push_back(i + 1);
    }   
    for (auto [x,ct] : cnt)
    {
        ll sum = 0;
        for (int j = 0;j < ct.size();j++)
        {
            if (j > 0)
                ans += 1LL * sum * (n - ct[j] + 1) % MOD;
            sum += ct[j] + 1;
            ans %= MOD;
        }
    }
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