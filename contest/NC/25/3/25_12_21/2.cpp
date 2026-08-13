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
    vt a(13),b(13);
    for (int i = 0;i < 13;i++) cin >> a[i];
    int cnt = 0;
    for (int i = 0;i < 13;i++) 
    {
        cin >> b[i];
        if (a[i] + b[i] != 4)
        {
            cnt += abs(a[i] - b[i]);
        }
    }
    cout << cnt / 2;

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