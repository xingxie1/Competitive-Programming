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
    vt b(n);
    for (int i = 0;i < n;i++) cin >> b[i];
    map<int,int> cnt;
    int flag = 0;
    for (int x : b)
    {
        if (cnt.count(x))
        {
            flag = 1;
            break;
        }
        cnt[x]++;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

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