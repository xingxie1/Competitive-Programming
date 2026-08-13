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
    string a,b;
    cin >> a >> b;
    int f = 0;
    for (int i = 0;i < n;i++)
    {
        if (a[i] == b[i]) f = 1;
    }
    if (!(a == b || !f))
    {
        cout << "NO" << endl;
        return ;
    }
    vpii ans;
    if (a != b) 
    {
        ans.push_back({0,n - 1});
        a = b;
    }
    int cnt = 0;
    for (int i = 0;i < n;i++)
    {
        if (a[i] == '1') 
        {
            ans.push_back({i,i});
            cnt++;
        }
    }
    if (cnt % 2)
    {
        ans.push_back({0,n - 1});
        ans.push_back({0,0});
        ans.push_back({1,n - 1});
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto& [l,r] : ans) cout << l + 1 << " " << r + 1 << endl;
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