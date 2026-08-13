#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    int mn = min({a,b,c});
    int mx = max({a,b,c});
    int md = a + b + c - mx - mn;
    if (mn + md <= mx)
    {
        cout << "wtnl";
    }
    else 
    {
        cout << "Yes" << endl;
        vector<double> r(3);
        double s = (a + b + c) / 2.0;
        r[0] = s - c;
        r[1] = s - b;
        r[2] = s - a;
        sort(r.begin(),r.end());
        printf ("%.2lf %.2lf %.2lf",r[0],r[1],r[2]);
    }
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