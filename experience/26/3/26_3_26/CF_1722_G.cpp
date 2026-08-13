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
    int n;
    cin >> n;
    vt a(n);
    int x = 1;
    for (int i = 0;i < n;i++)
    {
        a[i] = x++;
    }

    if (n % 4 == 0) a[n - 1] = 0;
    else if (n % 4 == 1) a[0] = 0;
    else if (n % 4 == 2) 
    {
        int m = bit_width(1u * a[n - 2]);
        a[n - 1] = 1 << m;
        a[n - 3] = 1 << m;
        a[n - 3] += a[n - 2];
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