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
    int n, x;
    cin >> n >> x;
    vpii a(n);
    vt b(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    for (int i = 0;i < n;i++) cin >> b[i];
    ranges::sort(a);
    ranges::sort(b);
    vt ans(n);
    for (int i = 0;i < n - x;i++)
    {
        ans[a[i].se] = b[i + x];
        if (a[i].fi > b[i + x])
        {
            cout << "No" << endl;
            return ;
        }
    }
    for (int i = n - x;i < n;i++)
    {
        ans[a[i].se] = b[i - (n - x)];
        if (a[i].fi <= b[i - (n - x)])
        {
            cout << "No" << endl;
            return ;
        }
    }
    cout << "Yes" << endl;
    for (int x : ans) cout << x << " ";
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