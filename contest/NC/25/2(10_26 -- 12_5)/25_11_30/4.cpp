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
    int n,m;
    string a,b;
    cin >> n >> m;
    cin >> a >> b;
    int mx = max(m,n);
    if (n != m)
    {
        mx = lcm(m,n);
        string tmp1 = a;
        string tmp2 = b;
        while (a.size() < mx) a += tmp1;
        while (b.size() < mx) b += tmp2;
    }

    string ans;

    mx *= 2;
    string tmp = a;
    a += tmp;
    tmp = b;
    b += tmp;
    

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    cout << a << endl;
    cout << b << endl;

    for (int i = 0;i < mx;i++)
    {
        if (a[i] >= b[i]) ans.push_back(a[i] - b[i] + '0');
        else 
        {
            if (i + 1 < mx)
                a[i + 1] = a[i + 1] - 1;
            int x = a[i] - b[i] + 10;
            ans.push_back(x + '0');
        }
    }
    // cout << ans;
    reverse(ans.begin(),ans.end());
    cout << mx / 2 << endl;
    for (int i = 0;i < mx / 2;i++) cout << ans[i];
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