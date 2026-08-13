#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

long long count(string& s,char c)
{
    long long n = s.size(),ans = 0,cnt = 0;
    for (int i = n - 1;i >= 0;i--)
    {
        if (s[i] == c) 
        {
            ans += abs(n - 1 - i - cnt);
            cnt += 2;
        }
    }
    return ans;
}
void solve()
{
    string s;
    cin >> s;
    int cnt0 = 0,cnt1 = 0;
    for (char c : s)
    {
        if (c == '0') cnt0++;
        else cnt1++;
    }
    long long ans;
    if (cnt0 > cnt1) ans = count(s,'0');
    else ans = min(count(s,'0'),count(s,'1'));
    
    cout << ans;
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