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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (a[i][j] >= '1' && a[i][j] <= '9')
            {
                int t = a[i][j] - '0';
                a[i][j] = '.';
                for (int i1 = -9;i1 <= 9;i1++)
                {
                    for (int j1 = -9;j1 <= 9;j1++)
                    {
                        int x = i + i1,y = j + j1;
                        if (x < 0 || x >= n || y < 0 || y >= m) continue;
                        if (abs(i1) + abs(j1) <= t && a[x][y] == '#') a[x][y] = '.';
                    }
                }
            }
        }
    }
    for (int i = 0;i < n;i++)
    {
        cout << a[i] << endl;
    }
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