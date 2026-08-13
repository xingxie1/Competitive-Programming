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
    ll n;
    cin >> n;
    if ((n & (n - 1)) == 0) 
    {
        cout << 1 << endl << n << endl;
        return ;
    }
    cout << __builtin_popcountll(n) + 1 << endl;
    for (int i = 63 - __builtin_clzll(n);i >= 0;i--)
    {
        if ((n >> i) & 1LL)
        {
            cout << (n ^ (1LL << i)) << " ";
        }
    } 
    cout << n << endl;

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