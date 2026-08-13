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
    int n,k,p,m;
    cin >> n >> k >> p >> m;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int t = a[p - 1];
    int c1 = t,c2 = t;
    if (p > k)
    {
        sort(a.begin(),a.begin() + p - 1);
        c1 += accumulate(a.begin(),a.begin() + p - k,0);
    }
    a.erase(find(a.begin(),a.end(),t));
    ranges::sort(a);
    c2 += accumulate(a.begin(),a.begin() + n - k,0LL);
    if (m < c1) cout << 0 << endl;
    else cout << 1 + (m - c1) / c2 << endl;
    
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