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
    int n,k;
    cin >> n >> k;
    int l = 0,r = INT_MAX;
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        auto check = [&](int x)
        {
            int d = x;
            d -= x / n;
            if (d >= k) return 1;
            else return 0;
        };
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
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