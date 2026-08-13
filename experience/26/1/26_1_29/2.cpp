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
    int n,k,q;
    cin >> n >> k >> q;
    vt a(n, 0);
    set<int> s1,s2;
    while (q--)
    {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1)
        {
            for (int i = l;i <= r;i++) s1.insert(i);
        }
        else 
        {
            for (int i = l;i <= r;i++) s2.insert(i);
        }
    }
    for (int i = 0;i < n;i++)
    {
        if (s1.contains(i + 1) && s2.contains(i + 1)) a[i] = k + 1;
        else if (s2.contains(i + 1)) a[i] = i % k;
        else a[i] = k;
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