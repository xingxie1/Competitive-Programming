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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n, x;
    cin >> n >> x;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    int j = -1;
    for (int i = 1;i <= n;i++) 
    {
        if (a[i] == x) 
        {
            j = i;
            break;
        }
    }
    int l = 1,r = n + 1;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (a[m] <= x) l = m;
        else r = m;
    }
    if (l == j) 
    {
        cout << 0 << endl;
        return ;
    }
    cout << 1 << endl;
    cout << j << " " << l << endl;
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