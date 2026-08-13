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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll sum = 0;
    for (int i = 0;i < n;i++)
    {
        vt b;
        for (int j = 0;j < n;j++)
        {
            if (j != i)
            {
                if (a[j] <= a[i]) b.push_back(a[j]);
            }
        }
        if (b.size() * 1.0 / (n - 1) >= 0.8) sum += a[i];
    }
    cout << sum << endl;

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