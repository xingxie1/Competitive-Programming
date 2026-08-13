#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,x,y;
    cin >> n >> x >> y;
    x--;
    y--;
    vt a(n);
    a[x] = 0;
    a[y] = 1;
    for (int i = x + 1;i < y;i++)
    {
        a[i] = (i - x) % 2;
    }
    if (y - x > 1 && a[y - 1] == 1) a[y - 1] = 2;
    int len = n - (y - x + 1);
    int cur = (x - 1 + n) % n;
    for (int i = 1;i <= len;i++)
    {
        a[cur] = i % 2;
        cur = (cur - 1 + n) % n;
    }
    if (len > 0 && a[(y + 1) % n] == a[y]) a[(y + 1) % n] = 2;

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