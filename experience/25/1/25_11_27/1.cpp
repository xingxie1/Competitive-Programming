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
    string tmp;
    for (int i = 0;i < n;i++) tmp += '*';
    for (int i = 0;i < 2 * n;i++) tmp += '.';
    for (int i = 0;i < n;i++) tmp += '*';
    for (int i = 0;i < 3 * n;i++)
    {
        cout << tmp << endl;
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j <= i;j++) cout << '.';
        for (int j = 0;j < n;j++) cout << '*';
        for (int j = 0;j < 2 * (n - i - 1);j++) cout << '.';
        for (int j = 0;j < n;j++) cout << '*';
        for (int j = 0;j <= i;j++) cout << '.';
        
        cout << endl;
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