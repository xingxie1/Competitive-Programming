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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(k,n);
    if (k % 2 == 1)
    {
        for (int i = 0;i < k;i++) cout << n << " " ;
        cout << endl;
        return ;
    }
    int len = bit_width(uint32_t(n));
    int free = 0;
    for (int i = len - 1;i >= 0;i--)
    {
        if (n >> i & 1)
        {
            int pos = min(free,k - 1);
            a[pos] ^= (1 << i);
            free++;
        }
        else 
        {
            for (int j = 0;j < min(free& ~1, k);j++) a[j] |= 1 << i;
        }
    }
    for (int x : a) cout << x << " ";
    cout << endl;
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