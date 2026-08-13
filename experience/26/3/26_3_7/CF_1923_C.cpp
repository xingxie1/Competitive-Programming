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
    int n,q;
    cin >> n >> q;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll pre(n + 1),cnt(n + 1);
    for (int i = 0;i < n;i++) 
    {
        pre[i + 1] = pre[i] + a[i] - 1;
        cnt[i + 1] = cnt[i] + (a[i] == 1);
    }
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        if (l == r)
        {
            cout << "NO" << endl;
            continue;
        }
        ll s = pre[r] - pre[l - 1];
        if (s >= cnt[r] - cnt[l - 1]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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