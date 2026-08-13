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
    int l,r;
    cin >> l >> r;
    int cnt1 = 0,cnt2 = 0,cnt3 = 0;
    l--;
    int a = 0,b = 0,c = 0;
    cnt1 = cnt2 = cnt3 = l / 3;
    if (l % 3 == 1) cnt1++;
    if (l % 3 == 2) cnt2++;

    a = b = c = r / 3;
    if (r % 3 == 1) a++;
    if (r % 3 == 2) b++;

    cout << a - cnt1 << " " << b - cnt2 << " " << c - cnt3 << endl;
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