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
    unordered_map<int,int> cnt;
    for (int i = 0;i < 2 * n;i++) 
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int s1 = 0,s2 = 0;
    auto it = cnt.begin();
    long long ans = 0;
    while (it != cnt.end())
    {
        if ((it->se & 1) == 0)
        {
            int x = it->se / 2;
            if (x & 1) 
            {
                ans += 2;
                s1 += x;
                s2 += x;
            }
            else 
            {
                if ((s1 + x == n) || (s2 + x == n)) 
                {
                    s1 += x;
                    s2 += x;
                    it++;
                    continue;
                }
                x /= 2;
                if (s1 > s2)
                {
                    s1 += x - 1;
                    s2 += x + 1;
                }
                else 
                {
                    s1 += x + 1;
                    s2 += x - 1;
                }
                ans += 2;
            }
        }
        it++;
    }
    it = cnt.begin();
    while (it != cnt.end())
    {
        if ((it->se & 1) == 0) 
        {
            it++;
            continue;
        }
        ans++;
        it++;
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