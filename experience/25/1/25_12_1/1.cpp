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
    string s;
    cin >> s;
    int cnt = 0,flag = 0;
    for (char c : s)
    {
        if (c == '1' && flag == 0)
        {
            cnt++;
            flag = 1;
        }
        else if (c == '0' && flag == 1)
        {
            cnt++;
            flag = 0;
        }
    }
    cout << cnt << endl;
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