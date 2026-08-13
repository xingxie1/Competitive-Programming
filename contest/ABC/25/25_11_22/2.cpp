#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++)
    {
        int flag = 1;
        for (int j = i - 1;j >= 0;j--)
        {
            if (a[j] > a[i]) 
            {
                flag = 0;
                cout << j << " ";
                break;
            }
        }
        if (flag) cout << "-1 ";
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