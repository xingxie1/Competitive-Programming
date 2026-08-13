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
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt p(k);
    for (int i = 0;i < k;i++) cin >> p[i];
    for (int & x : p) x--;
    p.push_back(n - 1);
    k++;
    int ans = 0;
    int l = 0;
    // for (int j = 0;j < k - 1;j++)
    // {
    //     int c1 = 0,c2 = 0;
    //     int m = p[j],r = p[j + 1];
    //     for (int i = l;i < m;i++)
    //     {
    //         if (a[i] != a[i + 1]) c1++;
    //     }
    //     for (int i = m;i < r - 1;i++)
    //     {
    //         if (a[i] != a[i + 1]) c2++;
    //     }
    //     l = m;
    //     int cnt = max(c1,c2);
    //     ans += cnt;
    // }
    for (int j : p)
    {
        for (int i = 0;i < )
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