// https://codeforces.com/problemset/problem/1807/G2
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
    vt c(n);
    for (int i = 0;i < n;i++) cin >> c[i];
    sort(c.begin(),c.end());
    if (c[0] != 1) 
    {
        cout << "No" << endl;
        return ;
    }
    ll pre = 1;
    for (int i = 1;i < n;i++)
    {
        if (c[i] > pre)
        {
            cout << "No" << endl;
            return ;
        }
        pre += c[i];
    }
    cout << "Yes" << endl;
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