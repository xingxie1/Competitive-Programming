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
    int n,q;
    cin >> n >> q;
    vt d(q);
    for (int i = 0;i < q;i++) cin >> d[i];
    vvt g(n + 1);
    for (int i = 1;i < n;i++) cout << i << " " << i + 1 << endl;
    int cur = n - 1;
    int lastv= n - 1;
    for (int x : d)
    {
        if (cur == x) 
        {
            cout << -1 << " " << -1 << " " << -1 << endl;
            continue;
        }
        cout << n << " " << lastv << " " << x << endl;
        lastv = x;
        cur = x;
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