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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,k,q;
    cin >> n >> k >> q;
    vvt a(n,vt(k)),b(k,vt(n));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < k;j++) cin >> a[i][j];
    }
    for (int j = 0;j < n;j++)
    {
        for (int i = 0;i < k;i++)
        {
            if (j == 0) b[i][j] = a[j][i];
            else b[i][j] = b[i][j - 1] | a[j][i];
        }
    }
    // for (int i = 0;i < k;i++)
    // {
    //     for (int x : b[i]) cout << x << " ";
    //     cout << endl;
    // }
    while (q--)
    {
        int m;
        cin >> m;
        int mn = 1,mx = n;
        for (int i = 0;i < m;i++)
        {
            int r,c;
            char op;
            cin >> r >> op >> c;
            r--;
            if (op == '>')
            {
                int j = ranges::upper_bound(b[r],c) - b[r].begin();
                mn = max(mn,j + 1);
            }
            else 
            {
                int j = ranges::lower_bound(b[r],c) - b[r].begin();
                mx = min(mx,j);
            }
        }
        if (mn <= mx) cout << mn << endl;
        else cout << -1 << endl;
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