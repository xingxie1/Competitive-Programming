#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
using vt = vector<int>;
using vll = vector<ll>;

void solve()
{
    int n = 6;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    ll k;
    cin >> k;
    sort(a.begin(),a.end());
    vll ans;
    // for (ll x0 = 0;x0 <= 6;x0++)
    // {
    //     for (ll x1 = 0;x1 <= 6;x1++)
    //     {
    //         for (ll x2 = 0;x2 <= 6;x2++)
    //         {
    //             for (ll x3 = 0;x3 <= 6;x3++)
    //             {
    //                 for (ll x4 = 0;x4 <= 6;x4++)
    //                 {
    //                     for (ll x5 = 0;x5 <= 6;x5++)
    //                     {
    //                         for (ll x6 = 0;x6 <= 6;x6++)
    //                         {
    //                             if (x0 + x1 + x2 + x3 + x4 + x5 + x6 != 6) continue;
    //                             // cout << 1 << endl;
    //                             ll s = x0 * (a[0] + 1) + x1 * (a[1] + 1) + x2 * (a[2] + 1) + 
    //                                    x3 * (a[3] + 1) + x4 * (a[4] + 1) + x5 * (a[5] + 1) + 
    //                                    x6 * (a[6] + 1);
    //                             if (s > k) continue;
    //                             // cout << 2 << endl;
    //                             int cnt = x1 + x2 * 2 + x3 * 3 + x4 * 4 + x5 * 5 + x6 * 6;
    //                             if (cnt < 19) continue;
    //                             // cout << 3 << endl;
    //                             vll ans;
    //                             if (x0) 
    //                             {
    //                                 for (int i = 0;i < x0;i++) ans.push_back(a[0] + 1);
    //                             }
    //                             if (x1) 
    //                             {
    //                                 for (int i = 0;i < x1;i++) ans.push_back(a[1] + 1);
    //                             }
    //                             if (x2) 
    //                             {
    //                                 for (int i = 0;i < x2;i++) ans.push_back(a[2] + 1);
    //                             }
    //                             if (x3) 
    //                             {
    //                                 for (int i = 0;i < x3;i++) ans.push_back(a[3] + 1);
    //                             }
    //                             if (x4) 
    //                             {
    //                                 for (int i = 0;i < x4;i++) ans.push_back(a[4] + 1);
    //                             }
    //                             if (x5) 
    //                             {
    //                                 for (int i = 0;i < x5;i++) ans.push_back(a[5] + 1);
    //                             }
    //                             if (x6) 
    //                             {
    //                                 for (int i = 0;i < x6;i++) ans.push_back(a[6] + 1);
    //                             }
    //                             // cout << s << " " << k << endl;
    //                             if (s < k) ans[0] += k - s;
    //                             sort(ans.begin(),ans.end());
    //                             cout << "YES" << endl;
    //                             for (ll x : ans) cout << x << " ";
    //                             cout << endl;
    //                             return ;
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout << "NO" << endl;
    auto dfs = [&](auto&& self,int i,int c,int cnt,ll s)
    {
        if (i == n + 1) return s <= k && cnt >= 19;
        cout << 1 << endl;
        for (int x = 0;x <= 6;x++)
        {
            if (c + x <= 6)
            {
                // for (int j = 0;j < x;j++) ans.push_back(a[i] + 1);
                // if (self(self,i + 1,c + x,cnt + x * i,s + 1LL * (a[i] + 1) * x)) return true;
                // for (int j = 0;j < x;j++) ans.pop_back();
                // self(self,i + 1,c + x,cnt + x * i,s + 1LL * (a[i] + 1) * x);
            }
        }
        return false;
    };
    dfs(dfs,0,0,0,0);
    // if (dfs(dfs,0,0,0,0)) 
    // {
    //     cout << "YES" << endl;
    //     for (ll x : ans) cout << x << " ";
    //     cout << endl;
    // }
    // else cout << "No" << endl;

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

    return 0;
}