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
    int n,k;
    cin >> n >> k;
    vt b(36);
    for (int i = 0;i < 36;i++)
    {
        b[i] = i * (i + 1) / 2;
    }
    vt a(n,-1000);
    auto j = ranges::lower_bound(b,k) - b.begin();
    if (b[j] == k)
    {
        for (int i = 0;i < j;i++) a[i] = 1;
        for (int x : a) cout << x << " ";
        cout << endl;
        return ;
    }
    j--;
    int res = k - b[j];
    for (int i = 0;i < j;i++) a[i] = 2;
    if (j + 1 < n)
    {
        res--;
        a[j + 1] = 1000 - (j - res) * 2 - 1;
    }
    else 
    {
        a[j] = -(j - res) * 2 - 1;
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