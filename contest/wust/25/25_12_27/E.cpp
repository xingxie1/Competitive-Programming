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
    string s;
    cin >> s;
    vt a;
    for (int i = 0;i < s.size();i++)
    {
        if (s[i] == 'h' && s[i + 1] == 'y' && s[i + 2] == 'w') a.push_back(i + 1);
    }
    int ans = 0;
    for (int x : a)
    {
        ans ^= x;
    }
    cout << ans << endl;

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