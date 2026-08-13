#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
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
    vector<vector<int>> a(n,vector<int>(n,0));
    for (int j = n % 2;j < n;j += 2)
    {
        for (int i = 0;i <= j;i++) a[i][j] = 1;
        for (int i = j;i >= 0;i--) a[j][i] = 1;
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++) cout << a[i][j];
        cout << endl;
    }
    cout << endl;
    
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