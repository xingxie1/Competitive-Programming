// https://codeforces.com/problemset/problem/1708/B
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
    int n,l,r;
    cin >> n >> l >> r;
    if (r - l + 1 < n) 
    {
        cout << "No" << endl;
        return ;
    }
    vt a(n + 1);
    for (int i = 1;i <= n;i++)
    {
        for (int j = l + i - 1;;j++)
        {
            if (j % i == 0) 
            {
                a[i] = j;
                break;
            }
        }
    }
    if (a[n] == 0 || a[n] > r)
    {
        cout << "NO" << endl;
        return ;
    }
    cout << "YES" << endl;
    for (int i = 1;i <= n;i++) cout << a[i] << " ";
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