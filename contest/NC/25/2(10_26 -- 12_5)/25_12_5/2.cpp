#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    ll ans = 0;
    vector<vector<int>> b(m,vector<int>(3));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            int a;
            cin >> a;
            if (a == 0) b[j][0]++;
            else if (a == 1) b[j][1]++;
            else b[j][2]++;
        }
        
    }
    for (int i = 0;i < m;i++)
    {
        int x = b[i][0],y = b[i][1],cnt = b[i][2];
        if (x < y)
        {
            if (x + cnt <= y) x += cnt;
            else 
            {
                cnt -= (y - x);
                x = y;
                if (cnt & 1) 
                {
                    int aaa = cnt / 2;
                    x += aaa + 1;
                    y += aaa;
                }
                else 
                {
                    x += cnt / 2;
                    y += cnt / 2;
                }

            }
        }
        else if (x == y)
        {
            if (cnt & 1)
            {
                x += cnt / 2 + 1;
                y += cnt / 2;
            }
            else 
            {
                x += cnt / 2;
                y += cnt / 2;
            }
        }
        else 
        {
            if (y + cnt <= x) y += cnt;
            else 
            {
                cnt -= (x - y);
                y = x;
                if (cnt & 1) 
                {
                    x += cnt / 2 + 1;
                    y += cnt / 2;
                }
                else 
                {
                    x += cnt / 2;
                    y += cnt / 2;
                }
            }
        }
        ans += 2LL * x * y + n;
    }
    
    cout << ans << endl;
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