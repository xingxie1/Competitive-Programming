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
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int la,ra,lb,rb;
    cin >> la >> ra >> lb >> rb;
    if (ra - la >= 10 || rb - lb >= 10) cout << 9 << endl;
    else 
    {
        auto f = [&](int n)
        {
            int ans = 0;
            while (n)
            {
                ans = max(ans,n % 10);
                n /= 10;
            }
            return ans;
        };
        int ans = 0;
        for (int a = la;a <= ra;a++)
        {
            for (int b = lb;b <= rb;b++)
            {
                ans = max(ans,f(a + b));
            }
        }
        cout << ans << endl;
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