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
    if (k % 2)
    {
        cout << "NO" << endl;
        return ;
    }
    if (k == 0)
    {
        cout << "Yes" << endl;
        for (int i = 1;i <= n;i++) cout << i << " ";
        cout << endl;
        return ;
    }
    ll mx = 0;
    if (n % 2) mx = 1LL * n / 2 * (n + 1);
    else mx = 1LL * n / 2 * n;
    if (k > mx)
    {
        cout << "No" << endl;
        return ;
    }
    cout << "Yes" << endl;
    vt a(n);
    ranges::iota(a,1);
    ll sum = 0;
    int l = 0;
    while (sum < k)
    {
        ll res = k - sum,m = (n - 2 * (l + 1) + 1) * 2;
        if (res >= m)
        {
            swap(a[l],a[n - l - 1]);
            sum += m;
        }
        else 
        {
            res /= 2;
            swap(a[l],a[l + res]);
            sum = k;
        }
        l++;
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