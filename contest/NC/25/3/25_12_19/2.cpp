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
    int N = 1e6 + 10;
    vector<int> d(N,0);
    for (int i = 1;i < N;i++)
    {
        if (!d[i])
        {
            for (int j = 1;i * j * j < N;j++)
            {
                d[i * j * j] = i;
            }
        }
    }
    int n;
    cin >> n;
    vector<vector<int>> g(N);
    vt a(n);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        g[d[a[i]]].push_back(a[i]);
    }
    for (int i = 0;i < N;i++)
    {
        if (g[i].empty()) continue;
        sort(g[i].begin(),g[i].end(),greater<int>());
    }
    vector<int> b(n);
    for (int i = 0;i < n;i++)
    {
        b[i] = g[d[a[i]]].back();
        g[d[a[i]]].pop_back();
    }
    for (int i = 0;i < n - 1;i++)
    {
        if (b[i] > b[i + 1]) 
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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