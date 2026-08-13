#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end());
    int flag = 1;
    for (int i = 0;i < n - 1;i++)
    {
        int l1 = a[i].first,r1 = a[i].second;
        int l2 = a[i + 1].first,r2 = a[i + 1].second;
        if ((l2 < l1 && r1 < r2) || (l1 < l2 && r2 < r1)) 
        {
            flag = 0;
            break;
        }
        else if (r1 < l2 || l1 > r2) 
        {
            flag = 0;
            break;
        }
    }
    if (flag && a[0].second >= a[n - 1].first) cout << "Yes" << endl;
    else cout << "No" << endl; 
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