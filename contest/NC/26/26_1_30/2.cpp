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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int flag = 0;
    for (int& x : a)
    {
        int cnt = 0;
        int t = x;
        for (int i = 2;i <= t;i++)
        {
            if (x % i == 0) 
            {
                cnt++;
                while (x % i == 0) x /= i;
            }
        }
        if (cnt == 1) 
        {
            flag = 1;
            break;
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