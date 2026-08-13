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
    multiset<int> a;
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    ll x = *prev(a.end());
    for (int i = 1;i <= x;i++)
    {
        if (x % i == 0)
        {
            a.erase(a.find(i));
        }
    }
    cout << x << " " << *prev(a.end()) << endl;

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