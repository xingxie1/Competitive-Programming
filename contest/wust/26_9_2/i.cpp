#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using i128 = __int128_t;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    if (s[0] == '-' || s[n - 1] == '-') 
    {
        cout << "invalid" << endl;
        return ;
    }
    for (int i = 0;i < n;i++)
    {
        if (s[i] != '-') continue;
        cnt++;
        if (i + 1 < n && s[i + 1] == '-') 
        {
            cout << "invalid" << endl;
            return ;
        }
    }
    if (n - cnt != 10) 
    {
        cout << "invalid" << endl;
        return ;
    }
    if (cnt > 3) 
    {
        cout << "invalid" << endl;
        return ;
    }
    if (cnt == 3 && s[n - 2] != '-')
    {
        cout << "invalid" << endl;
        return ;
    }
    int x = 10;
    int sum = 0;
    for (char c : s)
    {
        if (c == '-') continue;
        if (c >= '0' && c <= '9') 
        {
            sum = (sum + (c - '0') * x) % 11;
            x--;
        }
        else sum = (sum + 10) % 11;
    }
    if (sum) 
    {
        cout << "invalid" << endl;
        return ;
    }
    string ans = "978-";
    for (int i = 0;i < n - 1;i++) ans += s[i];
    int f = 1;
    sum = 0;
    for (char c : ans)
    {
        if (c == '-') continue;
        sum = sum + f * (c - '0');
        if (f == 1) f = 3;
        else f = 1;
    }
    sum %= 10;
    ans += ('0' + (10 - sum) % 10);
    cout << ans << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();
}