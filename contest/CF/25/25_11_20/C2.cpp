#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vt a(n + 1),b(n + 1);
    int s1 = 0,s2 = 0;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        s1 ^= a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> b[i];
        s2 ^= b[i];
    }
    if (s1 ==s2)
    {
        cout << "Tie" << endl;
        return ;
    }
    int hi = 31 - __builtin_clz(s1 ^ s2);

    int i;
    for (i = n;i >= 1;i--)
    {
        if ((a[i] ^ b[i]) & (1 << hi)) 
        {
            break;
        }
    }
    if (i % 2) cout << "Ajisai" << endl;
    else cout << "Mai" << endl;  
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