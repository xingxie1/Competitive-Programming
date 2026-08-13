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
    ll x;
    cin >> x;
    auto f = [](ll x)
    {
        int ret = 0;
        while (x)
        {
            ret += x % 10;
            x /= 10;
        }
        return ret;
    };
    int m = f(x);
    if (m == f(m)) cout << 0 << endl;
    else 
    {
        int ans = INT_MAX;
        for (int k = 1;k <= 9;k++)
        {
            int cnt = 0,sum = 0,t = f(x) - k;
            string s = to_string(x);
            while (sum < t)
            {
                int mxi = 1;
                for (int i = 1;i < s.size();i++)
                {
                    if (s[i] > s[mxi]) mxi = i;
                }
                if (s[0] - 1 > s[mxi]) mxi = 0;
                int d = s[mxi] - '0';
                if (mxi == 0) d--;
                if (sum + d <= t) sum += d;
                else sum = t;
                cnt++;
                s[mxi] = '0';
            }
            ans = min(ans,cnt);
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