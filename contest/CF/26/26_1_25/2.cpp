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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int start = 0,end = 0;
    int m = n;
    while (start < n && a[start] == m)
    {
        start++;
        m--;
    }
    end = start;
    for (int i = start + 1;i < n;i++) if (a[i] > a[end]) end= i;
    reverse(a.begin() + start,a.begin() + end + 1);
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