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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int ans = 0;
    for (int h1 = 0;h1 < n;h1++)
    {
        for (int h2 = h1;h2 < n;h2++)
        {
            for (int w1 = 0;w1 < m;w1++)
            {
                for (int w2 = w1;w2 < m;w2++)
                {
                    int f = 1;
                    for (int i = h1;i <= h2;i++)
                    {
                        for (int j = w1;j <= w2;j++)
                        {
                            if (a[i][j] != a[h1 + h2 - i][w1 + w2 - j]) f = 0;
                        }
                    }
                    if (f) ans++;
                }
            }
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