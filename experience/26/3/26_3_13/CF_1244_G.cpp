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
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    ll n,k;
    cin >> n >> k;
    vt a(n),b(n);
    if (1LL * (n + 1) * n / 2 > k) 
    {
        cout << -1 << endl;
        return ;
    }
    ll res = k - 1LL * n * (n + 1) / 2;
    ll s = 1LL * n * (n + 1) / 2;
    iota(a.begin(),a.end(),1);
    iota(b.begin(),b.end(),1);
    int l = 0,r = n - 1;
    while (l < r && res >= n - 2 * l - 1)
    {
        res -= (n - 2 * l - 1);
        s += (n - 2 * l - 1);
        swap(b[l],b[r]);
        l++;
        r--;
    }
    while (l < r) 
    {
        while (l < r && b[r] - b[l] > res) r--;
        if (l != r)
        {
            res -= (b[r] - b[l]);
            s += b[r] - b[l];
            swap(b[l],b[r]);
            l++;
            r--;
        }
    }
    cout << s << endl;
    for (int x : a) cout << x << " ";
    cout << endl;
    for (int x : b) cout << x << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}