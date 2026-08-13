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
    int n,m,k;
    cin >> n >> m >> k;
    vt a(m);
    for (int i = 0;i < m;i++) cin >> a[i];
    int q = n / k,r = n % k;
    int mx = ranges::max(a);
    if (mx > q + 1) 
    {
        cout << "NO" << endl;
        return ;
    }
    int cnt = 0;
    for (int x : a) if (x == q + 1) cnt++;
    if (cnt > r) 
    {
        cout << "NO" << endl;
        return ;
    }
    cout << "YES" << endl;
    
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