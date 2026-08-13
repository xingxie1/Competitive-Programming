#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;
double PI = acos(-1);

void solve()
{
    int a,b,k,c;
    cin >> a >> b >> k >> c;
    double k1 = 1.0 * a * k / b,b1 = 1.0 * c / b;
    double x = -1.0 * b1 / (k1 + 1.0 / k1);
    double y = 1.0 * b1 / (k1 * (k1 + 1.0 / k1));
    double d = sqrt(x * x + y * y);
    double theta = acos(d);
    double s = theta - 1.0 / 2 * sin(2 * theta);
    double ans = (PI - s) * a * b;
    cout << fixed << setprecision(10);
    cout << ans << endl;

    // int t = 1e6,sum = 0,cnt1 = 0,cnt2 = 0;
    // srand (time(nullptr));
    // auto f = [&](int mn,int mx)
    // {
    //     double r = 1.0 * rand() / (RAND_MAX + 1);
    //     return mn + r * (mx - mn);
    // };
    // while (sum <= 2e7)
    // {
    //     double x = f(-a,a),y = f(-b,b);
    //     if (1.0 * x * x * b * b + 1.0 * a * a * y * y <= 1.0 * a * a * b * b)
    //     {
    //         sum++;
    //         if (y >= k * x + m) cnt1++;
    //         else cnt2++;
    //     }
    // }
    // // cout << cnt1 << " " << cnt2 << endl;
    // // cout << PI * a * b << endl;
    // cout << fixed << setprecision(10);
    // cout << 1.0 * max(cnt1,cnt2) / sum * PI * a * b << endl;
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