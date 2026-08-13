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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int N = 40;
    vt ans;
    while (N--)
    {
        ranges::sort(a);
        int x = (a.back() + a[0]) / 2;
        if (x == 0) break;
        for (int& y : a)
        {
            y = abs(y - x);
        }
        ans.push_back(x);
    }
    ranges::sort(a);
    if (a.back() == 0) 
    {
        cout << ans.size() << endl;
        for (int x : ans) cout << x << " ";
        cout << endl;
    }
    else cout << -1 << endl;
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