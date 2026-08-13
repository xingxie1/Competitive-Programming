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
    vvt a(n,vt(3));
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i + 1;
    }
    ranges::sort(a);
    ranges::sort(a.begin(),a.begin() + n / 2,{},[](auto& b) {
        return b[1];
    });
    ranges::sort(a.begin() + n / 2,a.end(),{},[](auto& b) {
        return -b[1];
    });
    ll ans = 0;
    for (int i = 0;i < n / 2;i++)
    {
        cout << a[i][2] << " " << a[i + n / 2][2] << endl;
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