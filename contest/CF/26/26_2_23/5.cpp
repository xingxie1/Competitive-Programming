#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    if (k < n || k > 2 * n - 1) cout << "NO" << endl;
    else 
    {
        cout << "YES" << endl;
        vt a(2 * n);
        for (int i = 0;i < 2 * n;i += 2)
        {
            a[i] = a[i + 1] = (i + 2) / 2;
        }
        int res = k - n;
        int l = 2 * res - 1,r = 2 * res + 1;
        int tmp = a[r];
        while (l >= 1)
        {
            a[r] = a[l];
            r -= 2;
            l -= 2;
        }
        a[1] = tmp;
        for (int x : a) cout << x << " ";
        cout << endl;
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