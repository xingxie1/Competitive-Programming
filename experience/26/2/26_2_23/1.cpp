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
    int n;
    cin >> n;
    vt a(n),d(n);
    for (int i = 0;i < n;i++) cin >> d[i];
    a[0] = d[0];
    for (int i = 1;i < n;i++)
    {
        if (d[i] == 0)
        {
            a[i] = a[i - 1];
        }
        else if (a[i - 1] + d[i] >= 0 && a[i - 1] - d[i] <= 0)
        {
            if (a[i - 1] - d[i] == 0) 
            {
                cout << -1 << endl;
                return ;
            }
            a[i] = a[i - 1] + d[i];
        }
        else 
        {
            cout << -1 << endl;
            return ;
        }
    }
    for (int x : a) cout << x << " ";
    cout << endl;
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