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
    unordered_map<int,int> cnt;
    for (int i = 0;i < 2 * n;i++) 
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    auto it = cnt.begin();
    int a = 0,b = 0,c = 0;
    while (it != cnt.end())
    {
        int x = it->se;
        if (x == 0) continue;

        if (x & 1) a++;
        else if (x % 4) b++;
        else c++;

        it++;
    }
    int ans = a + 2 * b + 2 * c;
    if ((c & 1) && a == 0) ans -= 2;
    cout << ans << endl;
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