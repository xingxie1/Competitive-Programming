#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define fi first
#define se second
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<ll>;

void solve()
{
    long double w,x1,x2,y;
    int u,v;
    cin >> w >> x1 >> x2 >> y >> u >> v;

    long double a = 1.0 / v / v - 1.0 / u / u;
    long double b = 2 * x1 / u / u;
    long double c = y * y / v / v - x1 * x1 / u / u;
    long double ans = 1e200;
    if (b * b - 4 * a * c >= 0 && abs(u) != abs(v))
    {
        long double xx1 = (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
        long double xx2 = (-b - sqrt(b * b - 4 * a * c)) / 2 / a;
        ans = min(sqrt(xx1 * xx1 + y * y) / v + (w - y) / v,sqrt(xx2 * xx2 + y * y) / v + (w - y) / v);
    }
    if (abs(u) == abs(v))
    {
        long double xx1 = -c / b;
        ans = min(ans,sqrt(xx1 * xx1 + y * y) / v + (w - y) / v);
    }
    long double t = y / v;
    if (x1 + u * t < 0 && x2 + u * t > 0) {}
    else ans = min(ans,w / v);

    a = 1.0 / v / v - 1.0 / u / u;
    b = 2 * x2 / u / u;
    c = y * y / v / v - x2 * x2 / u / u;
    if (b * b - 4 * a * c >= 0 && abs(u) != abs(v))
    {
        long double xx1 = (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
        long double xx2 = (-b - sqrt(b * b - 4 * a * c)) / 2 / a;
        long double xxxxx = min(sqrt(xx1 * xx1 + y * y) / v + (w - y) / v,sqrt(xx2 * xx2 + y * y) / v + (w - y) / v);
        ans = min(ans,xxxxx);
    }
    if (abs(u) == abs(v))
    {
        long double xx1 = -c / b;
        ans = min(ans,sqrt(xx1 * xx1 + y * y) / v + (w - y) / v);
    }
    t = y / v;
    if (x1 + u * t < 0 && x2 + u * t > 0) {}
    else ans = min(ans,w / v);
    cout << ans << endl;

}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    cout << fixed << setprecision(15);
    while (_--) solve();

    return 0;
}