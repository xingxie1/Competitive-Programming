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
    int n,m;
    cin >> n >> m ;
    vvt a(n,vt(m)),suf(n,vt(m + 1));
    int cnt = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) 
        {
            cin >> a[i][j];
            cnt += a[i][j];
        }
        for (int j = m - 1;j >= 0;j--)
        {
            suf[i][j] = suf[i][j + 1] + a[i][j];
        }
    }
    ll x = (cnt + 1) / 2;
    cout << cnt / 2 * x << endl;
    cnt /= 2;
    int sum = 0,last = 0;
    string ans;
    for (int i = 0;i < n;i++)
    {
        if (sum + suf[i][last] <= cnt || last == m)
        {
            sum += suf[i][last];
            ans += 'D';
        }
        else 
        {
            for (int j = last;j <= m;j++)
            {
                if (sum + suf[i][j]> cnt)
                {
                    ans += 'R';
                }
                else
                {
                    sum += suf[i][j];
                    last = j;
                    ans += 'D';
                    break;
                }
            }
        }
    }
    while (ans.size() < n + m) ans += 'R';
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