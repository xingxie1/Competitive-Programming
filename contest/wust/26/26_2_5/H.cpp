#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    map<int,vt> p;
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        p[x].push_back(i + 1);
    }
    ll ans = 0;
    for (auto& [x, y] : p)
    {
        y.insert(y.begin(),0);
        for (int i = 1;i < y.size();i++)
        {
            int l = y[i - 1];
            int r = n - y[i] + 1;
            ans += 1LL * r * (r + 1) / 2 * (y[i] - l);
        }
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