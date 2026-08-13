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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt tmp = a;
    ranges::sort(tmp);
    if (tmp == a)
    {
        cout << 0 << endl;
        return ;
    }
    if ((a[0] + a[n - 1]) % 2)
    {
        a[n - 1] = a[0];
    }
    int x = a[0]; 
    vpii ans;
    ans.push_back({1,n});
    for (int i = 1;i < n - 1;i++)
    {
        if ((a[i] + x) % 2)
        {
            ans.push_back({1,i + 1});
        }
        else 
        {
            ans.push_back({i + 1,n});
        }
    }
    cout << ans.size() << endl;
    for (auto [l,r] : ans ) cout << l << " " << r << endl;
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