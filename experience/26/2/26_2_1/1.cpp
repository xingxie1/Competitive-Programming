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
    int n, m;
    cin >> n >> m;
    vector g(n,vector<int>(m));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) 
        {
            if (i % 2 == 0) cout << (n / 2 + i / 2) * m + j + 1 << " ";
            else cout << (i / 2) * m + j + 1 << " ";
        }
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