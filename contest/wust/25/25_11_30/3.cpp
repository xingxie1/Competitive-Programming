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
    int n,q;
    cin >> n >> q;
    vt a;
    set<int> s;
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        if (x == 1) s.insert(x);
        else a.push_back(x);
    }
    ll lim = (int)1e9 + 5;
    for (int i = 0;i < a.size();i++)
    {
        ll fact = 1;
        for (int j = i;j >= 0;j--)
        {
            fact *= a[j];
            s.insert(fact);
            if (fact > lim) break;
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        if (s.count(x)) cout << "Yes" << endl;
        else cout << "No" <<endl;
    }
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