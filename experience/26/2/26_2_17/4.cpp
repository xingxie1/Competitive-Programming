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
    int l,r;
    cin >> l >> r;
    int n = r - l + 1;
    vt a(n);
    int m = n,cur = 0;
    while (m)
    {
        int r = 1 << (bit_width((uint32_t)m) - 1);
        int l = m - r;
        for (int i = r - 1;i >= l;i--)
        {
            a[i] = cur++;
        }
        for (int i = m - 1;i >= r;i--)
        {
            a[i] = cur++;
        }
        m -= r;
    }
    
    ll s = 0;
    for (int i = 0;i < n;i++)
    {
        s += a[i] | i;
    }
    cout << s << endl;
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
