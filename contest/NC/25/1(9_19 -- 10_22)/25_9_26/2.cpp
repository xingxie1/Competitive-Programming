#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    long long n,t;
    cin >> n >> t;
    vector<pair<int,int>> num(n);
    for (int i = 0;i < n;i++) cin >> num[i].first;
    for (int i = 0;i < n;i++) cin >> num[i].second;
    long long sum = 0;
    for (int i = 0;i < n;i++)
        sum += num[i].first;
    sort(num.begin(),num.end(),greater<pair<int,int>>());
    if (sum >= t) 
    {
        cout << 0 << endl;
        return ;
    }
    long long cnt = 0;
    for (int i = 0;i < n;i++)
    {
        sum += 1LL * num[i].first * num[i].second;
        cnt += num[i].second;
        if (sum >= t)
        {
            while (sum >= t)
            {
                sum -= num[i].first;
                cnt--;
            }
            cnt++;
            cout << cnt << endl;
            return ;
        }
    }
    cout << -1 << endl;
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_ --) solve();
    return 0;
}