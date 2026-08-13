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
    vt k(n);
    for (int i = 0;i < n;i++) cin >> k[i];
    ranges::sort(k);
    for (int i = 0;i < m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if (c <= 0) cout << "NO" << endl;
        else 
        {
            double x = 2 * sqrt(1LL * a * c);
            auto it = ranges::upper_bound(k,b - x);
            if (it != k.end() && (*it < b + x)) 
            {
                cout << "YES" << endl;
                cout << *it << endl;
            }
            else cout << "NO" << endl;

        }
    }
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