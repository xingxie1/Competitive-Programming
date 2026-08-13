#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    int cnt = 0,flag = 0;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];        
    }
    sort(a.begin(),a.end());
    int ans = 0;
    for (int i = 0;i < n; i+= 2)
    {
        ans = max(a[i+1] - a[i],ans);
    }
    cout << ans << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}