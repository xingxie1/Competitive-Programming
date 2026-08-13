#include<iostream>
#include<vector>
using namespace std;

using vt = vector<int>;
using vll = vector<long long>;
void solve()
{
    int n;
    cin >> n;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 1;i < n;i++) cin >> b[i];
    b[0] = INT_MAX / 2;
    vector<int> dp(n);
    dp[0] = a[0]; 
    if (n > 1)
        dp[1] = min(a[0] + a[1],b[1]);
    for (int i = 2;i < n;i++)
    {   
        dp[i] = min(dp[i - 1] + a[i],dp[i - 2] + b[i]);
    }
    int s = dp[n - 1];
    int m = s / 60;
    s -= m * 60;
    int h = m / 60;
    m -= h * 60;
    int start = 8;
    start += h;
    if (start <= 9) cout << 0 << start << ":";
    else cout << start << ":";
    if (m < 10) cout << "0" << m << ":";
    else  cout << m << ":";
    if (s < 10) cout << 0;
    cout << s << " ";
    if (h <= 12) cout << "am" << endl;
    else cout << "pm" << endl;

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