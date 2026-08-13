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
    int n;
    cin >> n;
    vt b(n);
    for (int i = 0;i < n;i++) cin >> b[i];
    sort(b.begin(),b.end());

    int cnt = 0;
    for (int i = n - 1;i >= 0;i--)
    {
        while (b[i] > 1 && cnt < n) 
        {
            b[i]--;
            cnt++;
        }
        if (cnt == n) break;
    }
    long long ans = 0;
    int j = n;
    if (cnt >= n - 1)
    {
        for (int i = 0;i < n;i++)
        {
            if (b[i])
            {
                j = i;
                break;
            }
        }
        ans = n - j;
    }
    else 
    {
        for (int i = 0;i < n;i++)
        {
            if (b[i]) 
            {
                b[i]--;
                cnt++;
                
            }
            if (cnt == n) 
            {
                if (i == n - 1) 
                {
                    ans = 1;
                    break;
                }
                else 
                {
                    ans = n - i;
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