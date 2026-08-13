#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    long long n,a;
    cin >> n;
    vt cnt(3);
    for (int i = 0;i < n;i++) 
    {
        cin >> a;
        while (a % 2 == 0)
        {
            cnt[0]++;
            a /= 2;
        }
        while (a % 3 == 0)
        {
            cnt[1]++;
            a /= 3;     
        }
        while (a % 5 == 0)
        {
            cnt[2]++;
            a /= 5;
        }
    }
    int mn = INT_MAX;
    for (int i = 0;i < 3;i++) mn = min(mn,cnt[i]);
    cout << mn;
    
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