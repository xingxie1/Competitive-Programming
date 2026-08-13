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
    vt a(n),b(n);
    for (int i = 0;i < n;i++)
    {
        a[i] = i;
        b[i] = i;
    }
    int j = 0;
    for (int i = 0;i < 30;i++)
    {
        if ((1 << i) <= n && ((1 << (i + 1)) > n)) 
        {
            j = i;
            break;
        }
    }
    int m = 1 << (j + 1);
    int k;
    if (m - 1 == n) k = n;
    else 
    {
        m >>= 1;
        k = m;
    }
    reverse(a.begin(),a.begin() + k);
    int res = n - m;
    reverse(a.end() - 2 * res,a.end());
    reverse(a.end() - res,a.end());
    int s = 0;
    for (int i = 0;i < n;i++)
    {
        s += a[i] | b[i];
    }
    cout << s << endl;
    for (int x  : a) cout << x << " ";
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