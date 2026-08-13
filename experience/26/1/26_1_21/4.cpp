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
    cout << 2 * n - 1 << endl;
    for (int i = 1;i < n;i++)
    {
        cout << i << " " << 1 << " " << i << endl;
        cout << i << " " << i + 1 << " " << n << endl;
    }
    cout << n << " " << 1 << " " << n << endl;

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