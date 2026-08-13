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
    cin >> n>> m;
    vt a(n);
    set<int> p;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) 
    {
        int x;
        cin >> x;
        p.insert(x);
    }
    int flag = 1;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n - i - 1;j++)
        {
            if (a[j] > a[j + 1])
            {
                if (!p.count(j + 1)) 
                {
                    flag = 0;
                    break;
                }
                swap(a[j],a[j + 1]);
            }
        }
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