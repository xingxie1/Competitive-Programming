#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,q;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    cin >> q;
    vt b;
    for (int i = 0;i < n;i++)
    {
        int j = i;
        while (j < n && a[j] == a[i]) j++;
        
        i = j - 1;
        b.push_back(j - 1);
    }
    // for (int x : b) cout << x << " ";
    // cout << endl;
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        auto it1 = ranges::lower_bound(b,l);
        auto it2 = ranges::lower_bound(b,r);
        if (it1 == it2) cout << -1 << " " << -1 << endl;
        else cout << *it1 + 1 << " " << *it1 + 2 << endl;
    }
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