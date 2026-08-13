// https://codeforces.com/problemset/problem/482/A
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
    int n,k;
    cin >> n >> k;
    vt a(n);
    int s = 1,e = n;
    int cnt = 1;
    for (int i = 0;i < n;i++)
    {
        if (cnt <= k)
        {
            if (i & 1) a[i] = e--;
            else a[i] = s++;
        }
        else 
        {
            if (k % 2 == 0)
                a[i] = e--;
            else a[i] = s++;
        }
        cnt++;
    }
    for (int x : a) cout << x << " ";
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