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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int p,q;
    cin >> p >> q;
    int g = gcd(p,2 * q);
    int sum = p + 2 * q;
    for (int i = 1;i <= sqrt(sum);i++)
    {
        ll l = i - 1,r = INT_MAX / 2;
        while (l + 1 < r)
        {
            ll m = l + (r - l) / 2;
            if (i * (m + 1) + (i + 1) * m > sum) r = m;
            else l = m;
        }
        int m = i,n = l;
        if (m * (n + 1) + (m + 1) * n == sum) 
        {
            int mx = m * (n + 1);
            if (q <= mx) 
            {
                cout << m << " " << n << endl;
                return ;
            }
        }

    }
    cout << -1 << endl;

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