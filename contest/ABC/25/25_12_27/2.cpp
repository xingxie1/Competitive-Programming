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
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    int ans = INT_MAX;
    for (int i = 0;i <= n - m;i++)
    {
        int cnt = 0;
        for (int j = 0;j < m;j++)
        {
            if (s[i + j] >= t[j])
            {
                cnt += s[i + j] - t[j];
            }
            else 
            {
                cnt += 10 + s[i + j] - t[j];
            }
        }
        ans = min(ans,cnt);
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