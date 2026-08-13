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
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int s = a[0];
    if (n % 2)
    {
        cout << -1 << endl;
        return ;
    }
    int last = 1;
    vpii ans;
    for (int i = 0;i < n;i+=2)
    {
        if (a[i] + a[i + 1] == 0)
        {
            ans.push_back({i + 1,i + 1});
            ans.push_back({i + 2,i + 2});
        }
        else
        {
            ans.push_back({i + 1,i + 2});
        }
    }
    cout << ans.size() << endl;
    for (auto& [l, r] : ans) cout << l << " " << r << endl; 
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