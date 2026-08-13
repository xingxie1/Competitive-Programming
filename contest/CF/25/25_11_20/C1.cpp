#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    int cnt0 = 0,cnt1 = 0,cnt2 = 0;//奇数位置 a,b只有一个1  偶数位置,a,b 一个1   a,b都是1
    int flag = 0;
    vt a(n + 1),b (n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) cin >> b[i];
    for (int i = 1;i <= n;i++)
    {
        if (a[i] ^ b[i] == 1 && i % 2 == 1) 
        {
            flag = 1;
            cnt0++;
        }
        if (a[i] ^ b[i] == 1 && i % 2 == 0) 
        {
            flag = 2;
            cnt1++;
        }
        if (a[i] == 1 && b[i] == 1) cnt2++;
    }
    if (flag == 0)
    {
        cout << "Tie" << endl;
    }
    else if (flag == 1)
    {
        if ((cnt0 - 1 + cnt1 + cnt2 * 2) % 2) cout << "Tie" << endl;
        else cout << "Ajisai" << endl;
    }
    else 
    {
        if ((cnt0 - 1 + cnt1 + cnt2 * 2) % 2) cout << "Tie" << endl;
        else cout << "Mai" << endl;
    }

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