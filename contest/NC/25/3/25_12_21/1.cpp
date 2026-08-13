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
    int n1,n2;
    char c1,c2;
    cin >> n1 >> c1 >> n2 >> c2;
    if (n1 > n2) cout << "Yes" ;
    else if (n1 == n2)
    {
        if (c1 < c2) cout << "Yes";
        else cout << "No";
    }
    else cout << "No";
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