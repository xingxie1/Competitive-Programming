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
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1,vector<int>(n + 1));
    g[0][(n - 1)/ 2] = 1;
    int r = 0,c = (n - 1) / 2,k = 2,cnt = 1;
    while (cnt < n * n)
    {
        int i = (r - 1) % n,j = (c + 1) % n;
        if (i < 0) i += n;
        if (g[i][j] == 0) 
        {
            g[i][j] = k;
            r = i;
            c = j;
        }
        else 
        {
            g[(r + 1) % n][c] = k;
            r = (r + 1) % n;
        }
        k++;
        cnt++;
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
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