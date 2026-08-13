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
    string s[7] = {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};
    vector<pair<int,int>> a(7);
    for (int i = 0;i < 7;i++) 
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin(),a.end());
    cout << s[a[6].se];
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