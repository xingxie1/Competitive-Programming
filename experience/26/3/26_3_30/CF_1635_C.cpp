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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    if (a[n - 2] > a[n - 1])
    {
        cout << -1 << endl;
        return ;
    }
    int f = 1;
    for (int i = 0;i < n - 1;i++)
    {
        if (a[i] > a[i + 1]) 
        {
            f = 0;
            break;
        }
    }
    if (f)
    {
        cout << 0 << endl;
        return ;
    }
    if (a[n - 2] < 0 && a[n - 1] < 0)
    {
        cout << -1 << endl;
        return ;
    }
    
    vvt ans;
    for (int i = n - 3;i >= 0;i--)
    {
        ans.push_back({i + 1,i + 2,n});
    }
    cout << ans.size() << endl;
    for (auto& b : ans) cout << b[0] << " " << b[1] << " " << b[2] << endl;
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