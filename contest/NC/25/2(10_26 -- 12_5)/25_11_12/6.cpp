#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    int mxx = INT_MIN,mnx = INT_MAX;
    vector<int> mxy,mny;
    // vector<pair<int,int>> a(n);
    for (int i = 0;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        if (x >= mxx)
        {
            if (x > mxx)
            {
                mxx = x;
                mxy.clear();
                mxy.push_back(y);
            }
            else mxy.push_back(y);
        }
        if (x <= mnx)
        {
           if (x < mnx)
           {
                mnx = x;
                mny.clear();
            mny.push_back(y);
           }
           else mny.push_back(y);
        }
    }
    double ans = INT_MAX;
    for (int i = 0;i < mxy.size();i++)
    {
        double dx = pow(mxx - mnx,2);
        for (int j = 0;j < mny.size();j++)
        {
            double dy = pow(abs(mny[j]) + abs(mxy[i]),2);
            ans = min(ans,sqrt(dx + dy));
        }
    }
    cout << ans;
    // cout << mny[0];

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