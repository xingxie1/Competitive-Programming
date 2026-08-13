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
    int n,d,k;
    cin >> n >> d >> k;
    vvt g(n + 1,vt());
    int m = 0;
    for (int i = 0;i < d;i++) 
    {
        g[i + 1].push_back(i + 2);
        g[i + 2].push_back(i + 1);
        m++;
    }
    int x = d + 2;
    for (int i = 2;i <= d;i++)
    {
        int res = min(i - 1,d + 1 - i);
        auto dfs = [&](this auto&& self,)
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}