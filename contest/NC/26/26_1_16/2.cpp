#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector<vector<int>> g(k,vector<int>());
    for(int x : a)
    {
        int y = x % k;
        g[y].push_back(x);
    }
    int flag = 1;
    for (auto f : g)
    {
        if (f.size() % 2 == 1) flag = 0;
        cout << f.size() << endl;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
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