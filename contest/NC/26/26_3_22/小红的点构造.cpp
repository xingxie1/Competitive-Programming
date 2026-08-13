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
    int n,k;
    cin >> n >> k;
    for (int i = 1;i <= sqrt(n);i++)
    {
        int m = n / i;
        int mx = (2 * i - 1) * m - i,sum = 0,res = n - i * m,cnt = 0;
        if (mx + res >= k) 
        {
            cout << "Yes" << endl;
            for (int j = 1;j <= i;j++)
            {
                for (int x = 1;x <= m;x++)
                {
                    cnt++;
                    if (j == 1 && x > 1)
                    {
                        sum++;
                    }
                    else if (j > 1)
                    {
                        if (x == 1)
                        {
                            sum++;
                        }
                        else 
                        {
                            if (sum + 2 > k)
                            {
                                cout << j + 1 << " " << 1 << endl;
                                sum++;
                                break;
                            }
                            else sum += 2;
                        }
                    }
                    cout << j << " " << x << endl;
                    if (sum == k) break;
                }
                if (sum == k) break;
            }
            int y = 1;
            while (sum < k)
            {
                cout << i + y << " " << 1 << endl;
                y++;
                cnt++;
            }
            while (cnt < n)
            {
                cout << 10000000 + cnt << " " << 10000000 + cnt << endl;
                cnt++;
            }
            return ;
        }
    }
    cout << "No" << endl;
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