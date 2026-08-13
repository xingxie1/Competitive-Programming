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
    int x;
    cin >> x;
    if (x & 1) cout << -1 << endl;
    else 
    {
        for (int i = bit_width((uint32_t) x) - 1;i >= 0;i--)
        {
            if ((x >> i & 1) && (x >> (i + 1) & 1)) 
            {
                cout << -1 << endl;
                return ;
            }
        }
        cout << x / 2 << " " << 1LL * x / 2 + x << endl;
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