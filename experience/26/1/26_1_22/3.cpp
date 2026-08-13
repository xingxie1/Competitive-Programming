#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    double n,L;
    cin >> n >> L;
    L *= 1e10;
    vector<double> a(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        a[i] *= 1e10;
    }
    ranges::sort(a);
    // for (double x : a) cout << x << " ";
    auto check = [&](double x)
    {
        for (int i = 1;i < n;i++)
        {
            if (a[i] - a[i - 1] > 2 * x) return 0;
        }
        if (a[0] > x || L - a[n - 1] > x) return 0;
        return 1;
    };
    double l = 0,r = 1e20 + 1;
    int N = 100;
    while (N--)
    {
        double mid = (l + r) / 2.0;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%.10lf",r * 1e-10);
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