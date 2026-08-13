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
    vt a(3);
    for (int i = 0;i < 3;i++) cin >> a[i];
    sort(a.begin(),a.end());
    if (a[2] - a[0] >= 10) cout << "check again";
    else cout << "final " << a[1];

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