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
    int n;
    cin >> n;
    vector<string> g(2);
    for (int i = 0;i < 2;i++) cin >> g[i];
    int ans = 0;
    for (int j = 1;j < n - 1;j++)
    {
        auto& s1 = g[0];
        auto& s2 = g[1];
        if (s1[j] == '.' && s2[j] == '.' && s2[j - 1] == 'x' && s2[j + 1] == 'x' && s1[j - 1] == '.' && s1[j + 1] == '.') ans++;
    }
    for (int j = 1;j < n - 1;j++)
    {
        auto& s2 = g[0];
        auto& s1 = g[1];
        if (s1[j] == '.' && s2[j] == '.' && s2[j - 1] == 'x' && s2[j + 1] == 'x' && s1[j - 1] == '.' && s1[j + 1] == '.') ans++;
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