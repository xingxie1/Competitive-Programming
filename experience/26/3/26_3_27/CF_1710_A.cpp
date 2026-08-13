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
    int n,m,k;
    cin >> n >> m >> k;
    vt a(k);
    for (int i = 0;i < k;i++) cin >> a[i];
    ranges::sort(a,{},[&](auto& x) {return -x; });
    auto check = [&](int r,int c)
    {
        int s = 0;
        int f = 0;
        for (int x : a)
        {
            if (x >= 2 * r) 
            {
                if (s + x / r <= c) 
                {
                    s += x / r;
                    if (x / r >= 3) f = 1;
                }
                else 
                {
                    int res = c - s;
                    // cout << "res : " << res << endl;
                    if (res == 1 && !f) return false;
                    return true;
                }
            }
            else break;
        }
        return s >= c;
    };
    if (check(m,n) || check(n,m)) cout << "Yes" << endl;
    else cout << "No" << endl;
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