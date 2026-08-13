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
    vector<string> a(2);
    for (int i = 0;i < 2;i++) cin >> a[i];
    vvt dp(2,vt(n));
    dp[0][0] = 1;
    int i = 0,j = 0;
    while (j != n - 1)
    {
        if (!dp[i][j])
        {
            i ^= 1;
            j++;
            continue;
        }
        if (j + 2 < n && a[i][j + 1] == '>') dp[i][j + 2] = 1;
        if (j + 1 < n && a[i ^ 1][j] == '>') dp[i ^ 1][j + 1] = 1;
        i ^= 1;
        j++;
    }
    if (dp[1][n - 1]) cout << "YES" << endl;
    else cout << "NO" << endl;

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