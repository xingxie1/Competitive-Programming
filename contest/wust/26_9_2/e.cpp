#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using i128 = __int128_t;

void print_128(i128 x)
{
    string s;
    while (x)
    {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    ranges::reverse(s);
    cout << s << endl;
}
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if (s.back() == 'E') 
    {
        cout << "INVALID" << endl;
        return ;
    }
    for (int i = 0;i < n - 1;i++)
    {
        if (s[i] == 'O' && s[i + 1] == 'O') 
        {
            cout << "INVALID" << endl;
            return ;
        }
    }
    ranges::reverse(s);
    i128 ans = (i128)LLONG_MAX * (1LL << 60);
    for (i128 i = 1;i <= ((i128)1 << 80);i <<= 1)
    {
        i128 x = i;
        int f = 1;
        for (char c : s)
        {
            if (c == 'O')
            {
                if ((x - 1) % 3)
                {
                    f = 0;
                    break;
                }
                x = (x - 1) / 3;
                if (x == 1 || (x % 2 == 0)) 
                {
                    f = 0;
                    break;
                }
            }
            else 
            {
                x *= 2;
                if ((x & (x - 1)) == 0) 
                {
                    f = 0;
                    break;
                }
            }
        }
        if (f)
        {
            ans = min(ans,x);
        }
    }
    if (ans != (i128)LLONG_MAX * (1LL << 60) && ans != 0) print_128(ans);
    else cout << "INVALID" << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}