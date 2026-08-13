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
    int n;
    cin >> n;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    int ans = 0;
    for (int i = 0;i < n;i++)
    {
        int g;
        if (i == n - 1) 
        {
            g = gcd(a[i],a[i - 1]);
            if (g == 1 && (a[i] != 1 || b[i] > 1))
            {
                ans++;
                continue;
            }
            for (int j = g;j <= b[i];j += g) 
            {
                if (j == a[i]) continue;
                if (gcd(j,a[i - 1]) == g) 
                {
                    ans++;
                    break;
                }
            }
        }
        else if (i == 0) 
        {
            g = gcd(a[i],a[i + 1]);
            if (g == 1 && (a[i] != 1 || b[i] > 1))
            {
                ans++;
                continue;
            }
            for (int j = g;j <= b[i];j += g) 
            {
                if (j == a[i]) continue;
                if (gcd(j,a[i + 1]) == g) 
                {
                    ans++;
                    break;
                }
            }
        }
        else 
        {
            int g1 = gcd(a[i],a[i + 1]);
            int g2 = gcd(a[i],a[i - 1]);
            int lc = lcm(g1,g2);
            if (lc == 1 && (a[i] != 1 || b[i] > 1))
            {
                ans++;
                continue;
            }
            for (int j = lc;j <= b[i];j += lc) 
            {
                if (j == a[i]) continue;
                if (gcd(j,a[i + 1]) == g1 && gcd(j,a[i - 1]) == g2) 
                {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;

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