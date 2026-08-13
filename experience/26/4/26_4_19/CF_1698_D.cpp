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
// #define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    auto query = [&](int l,int r)
    {
        cout << "? " << l << " " << r << endl;
        int n = r - l + 1;
        int cnt = 0;
        for (int i = 0;i < n;i++) 
        {
            int x;
            cin >> x;
            if (x >= l && x <= r) cnt++;
        }
        return cnt;
    };
    int l = 1,r = n;
    auto check = [&](int m) -> bool  {
        int len = m - l + 1;
        int t = query(l, m);
        if (len % 2) {
            if (t % 2) {
                return 1;
            }
            return 0;
        }
        else {
            if (t % 2) {
                return 1;
            }
            return 0;
        }
    };
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << "! " << l << endl;
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