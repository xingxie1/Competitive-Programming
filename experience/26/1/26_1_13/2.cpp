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
    int s,k,m;
    cin >> s >> k >> m;
    int a = m / k;
    int b = m % k;
    if (a % 2 == 0) cout << max(0,s - b) << endl;
    else cout << max(0,min(k,s) - b) << endl;

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