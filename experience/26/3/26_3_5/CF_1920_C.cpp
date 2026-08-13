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
    int mx = ranges::max(a);
    auto check = [&](int len)
    {
        int g = 0;
        for (int i = 0;i < len;i++)
        {
            for (int j = i + len;j < n;j += len)
            {
                g = gcd(g,abs(a[j] - a[j - len]));
            }
        }
        if (g == 1) return 0;
        return 1;
    };
    int ans = 0;
    for (int k = 1;k <= sqrt(n);k++)
    {
        if (n % k) continue;
        int len1 = k,len2 = n / k;
        if (check(len1)) ans++;
        if (len1 != len2 && check(len2)) ans++;
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