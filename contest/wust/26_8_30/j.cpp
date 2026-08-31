#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using vll = vector<ll>;

void solve()
{
    int n;
    while (cin >> n)
    {
        vector<string> a(n);
        for (int i = 0;i < n;i++) cin >> a[i];
        vt cnt(26);
        for (int i = 0;i < n;i++) 
        {
            for (char c : a[i]) cnt[c - 'A']++;
        }
        char ans;
        int ax = 0,ay = 0;
        int fff = 0;
        for (int i = 0;i < 26;i++) 
        {
            if (cnt[i] == 1) 
            {
                for (int x = 0;x < n;x++)
                {
                    for (int y = 0;y < n;y++)
                    {
                        if (a[x][y] - 'A' == i)
                        {
                            ax = x + 1;
                            ay = y + 1;
                        }
                        if (cnt[a[x][y] - 'A'] == n - 1) 
                        {
                            ans = a[x][y];
                        }
                    }
                }
                cout << ax << " " << ay << " " << ans << endl;
            }
            else if (cnt[i] == n + 1)
            {
                fff = 1;
                for (int x = 0;x < n;x++)
                {
                    for (int y = 0;y < n;y++)
                    {
                        if (cnt[a[x][y] - 'A'] == n - 1) 
                        {
                            ans = a[x][y];
                        }
                    }
                }
                for (int x = 0;x < n;x++)
                {
                    for (int y = 0;y < n;y++)
                    {
                        if (a[x][y] == i + 'A') 
                        {
                            int f1 = 0,f2 = 0;
                            for (int x1 = 0;x1 < n;x1++) 
                            {
                                if (x1 == x) continue;
                                if (a[x1][y] == i + 'A') f1 = 1;
                            }
                            for (int y1 = 0;y1 < n;y1++)
                            {
                                if (y1 == y) continue;
                                if (a[x][y1] == i + 'A') f2 = 1;
                            }
                            if (f1 && f2) 
                            {
                                // cout << x + 1 << " " << y + 1 << ans << endl;
                                ax = x + 1;
                                ay = y + 1;
                            }
                        }
                    }
                }
                
            }
        }
        if (fff) 
        {
            cout << ax << " " << ay << " " << ans << endl;
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}