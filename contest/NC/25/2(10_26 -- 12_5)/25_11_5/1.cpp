#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int Gcd(int a,int b,int n,int& ans)
{
    ans = max(ans,a + b);
    if (b == 0 )
    {
        if (n == 0)
        {
            ans = min(ans,a + b);
        }
        return a;
    }
    return Gcd(b,a % b,n - 1,ans);
}
void solve()
{
    int n;
    cin >> n;
    int ans = INT_MAX;
    for (int i = 0;i < 10000;i++)
    {
        for (int j = 0;j < i;j++)
        {
            Gcd(i,j,n,ans);
        }
    }
    cout << ans << endl;
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