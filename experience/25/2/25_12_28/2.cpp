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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> b(n,vector<int>(m));
    for (int i = 0;i < n;i ++)
    {
        for (int j = 0;j < m;j++)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 0;i < n;i++)
    {
        sort(b[i].begin(),b[i].end());
    }
    for (auto v : b)
    {
        for (int x : v) cout << x << " ";
        cout << endl;
    }



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