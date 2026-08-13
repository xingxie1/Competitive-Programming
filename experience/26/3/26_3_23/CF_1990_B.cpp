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
    for (int i = y;i <= x;i++) a[i] = 1;
    for (int i = x + 1;i < n;i+=2) 
    {
        a[i] = -1;
        if (i + 1 < n) a[i + 1] = 1;
    }
    for (int i = y - 1;i >= 0;i -= 2)
    {
        a[i] = -1;
        if (i - 1 >= 0) a[i - 1] = 1;
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