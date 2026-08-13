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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    auto f = [&]() ->pair<vvt,vvt>
    {
        vvt r(n,vt(m)),c(m,vt(n));
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
            {
                cin >> r[i][j];
                c[j][i] = r[i][j];
            }
            ranges::sort(r[i]);
        }
        for (int i = 0;i < m;i++) ranges::sort(c[i]);

        ranges::sort(r);
        ranges::sort(c);
        return {r,c};
    };
    auto [r1,c1] = f();
    auto [r2,c2] = f();
    if (r1 == r2 && c1 == c2) cout << "YES" << endl;
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