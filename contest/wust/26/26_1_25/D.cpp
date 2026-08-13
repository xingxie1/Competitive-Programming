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
    // for (int i = 0;i <= n;i++)
    // {
    //     for (int j = 0;j <= m;j++)
    //     {
    //         int x = i & j,y = i ^ j;
    //         if (x * y == i * j) 
    //         {
    //             cout << i << " " << j << endl;
    //         }
    //     }
    // }
    cout << n + m + 1 << endl;
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