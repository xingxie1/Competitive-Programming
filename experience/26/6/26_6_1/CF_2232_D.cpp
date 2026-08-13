#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) 
    {
        if (a[i] >= i) 
        {
            NO;
            return ;
        }
    }
    YES;
    vvt ans;
    auto move = [&](auto&& self,int n,int s,int t) -> void
    {
        if (n <= 0) return ;
        int u = 6 - s - t;
        if (a[n] == 0) 
        {
            self(self,n - 1,s,u);
            ans.push_back({n,s,t});
            self(self,n - 1,u,t);
        }
        else 
        {
            self(self,n - 1 - a[n],s,u);
            ans.push_back({n,s,t});
            self(self,n - 1 - a[n],u,s);
            self(self,n - 1,s,t);
        }
    };
    move(move,n,1,3);
    cout << ans.size() << endl;
    for (auto& v : ans) cout << v[0] << " " << v[1] << " " << v[2] << endl;
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