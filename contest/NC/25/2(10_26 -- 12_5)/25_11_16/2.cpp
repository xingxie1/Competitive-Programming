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
    double mxd = 0;
    int ax1,ax2,ay1,ay2;
    for (int i = 0;i < n;i++)
    {
        for (int j = i + 1;j < n;j++)
        {
            int x1 = a[i].first,y1 = a[i].second;
            int x2 = a[j].first,y2 = a[j].second;
            double nd = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
            if (nd > mxd)
            {
                mxd = nd;
                ax1 = x1;
                ay1 = y1;
                ax2 = x2;
                ay2 = y2;
            }
        }
    }
    cout << ax1 << " "<< ay1 << " " << ax2 << " " << ay2;
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