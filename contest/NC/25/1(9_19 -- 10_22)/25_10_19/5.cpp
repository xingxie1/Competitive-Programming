#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    if (b > a || c > a) cout << -1 << endl;
    else if (a == 0 && b == 0 && c == 0)
    {
        cout << 0 << endl;
    }
    else 
    {
        int n = a + 2;
        vt ans (n);
        int mn = min (b,c);
        for (int i = 0;i < mn + 2;i++) ans[i] = 2;
        if (mn == c)
        {
            int d = b - mn;
            for (int i = mn + 2;i < mn + d + 2;i++)
            {
                if (ans[i-1] == 4) ans[i] = 2;
                else ans[i] = 4;
            }
            ans[b+2] = 1;
            for (int i = b+3;i < n;i++)
            {
                if (ans[i-1] == 1) ans[i] = 2;
                else if (ans[i-1] == 2) ans[i] = 4;
                else ans[i] =1;
            }
        }
        else 
        {
            int d = c - mn;
            for (int i = mn + 2;i < mn + d + 2;i++)
            {
                if (ans[i-1] == 2 && ans[i-2] == 2) ans[i] = 5;
                else if (ans[i-1] == 5 && ans[i-2] == 2) ans[i] = 2;
                else if (ans[i-1] == 2 && ans[i-2] == 5) ans[i] = 2;
            }
            ans[c+2] = 1;
            if (ans[c] == 2 && ans[c+1] == 5) 
            {
                for (int i = c + 3;i < n;i++)
                {
                    if (ans[i-1] == 5) ans[i] = 1;
                    else if (ans[i-1] == 1) ans[i] = 2;
                    else ans[i] = 5;
                }
            }
            else 
            {
                for (int i = c + 3;i < n;i++)
                {
                    if (ans[i-1] == 2) ans[i] = 1;
                    else if (ans[i-1] == 1) ans[i] = 5;
                    else ans[i] = 2;
                }
            }
            
            
        }
        cout << n << endl;
        for (int i = 0;i < n;i++)
        {
            cout << ans[i] << " ";
        }
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