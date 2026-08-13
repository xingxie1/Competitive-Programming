#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    int pow2 = (int)pow(2,n);
    int ans = 0;
    for (int i = 0;i < pow2;i++)
    {
        int i1 = i;
        int x;
        cin >> x;
        while (i1 || x)
        {
            if ((x & 1) != (i1 & 1)) ans++;
            i1 >>= 1;
            x >>= 1;

        }
    }
    cout << ans / 2<< endl;
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