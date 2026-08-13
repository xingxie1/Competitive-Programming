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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    int n,m;
    cin >> n >> m;
    if (2 * m > n || n > 1 + 1LL * m * (m + 1) / 2) 
    {
        NO;
        return ;
    }
    YES;
    int sum = n;
    for (int i = 0;i < m;i++)
    {
        cout << i + 1 << " " << i + 2 << endl;
    }
    sum -= m + 1;
    int x = m + 2;
    for (int i = m - 1;i >= 1;i--)
    {
        if (sum > i)
        {
            int j = i;
            int cnt = 0;
            if (sum - (j - 1) > i)
            {
                cnt = j - 1;
                sum -= j - 1;
                j = 1;
            }
            else 
            {
                while (sum > i && j > 1)
                {
                    sum--;
                    j--;
                    cnt++;
                }
            }
            cout << j << " " << x << endl;
            // cout << cnt << endl;
            for (int k = 1;k <= cnt;k++)
            {
                cout << x << " " << x + 1 << endl;
                x++;
            }
            x++;
            sum--;
        }
        else 
        {
            sum--;
            cout << i << " " << x << endl;
            x++;
        }
        // cout << sum << endl;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}