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
    int n;
    cin >> n;
    ll t = 1LL * n * (n + 1) / 2;
    set<ll> b;
    for (int i = 1;i <= sqrt(t);i++)
    {
        b.insert(1LL * i * i);
        if (1LL * i * i == t)
        {
            cout << -1 << endl;
            return ;
        }
    }
    vt a(n);
    for (int i = 0;i < n;i++) a[i] = i + 1;
    ll s = 0;
    for (int i = 0;i < n;i++)
    {
        if (b.contains(s + a[i])) swap(a[i],a[i + 1]);
        s += a[i];
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