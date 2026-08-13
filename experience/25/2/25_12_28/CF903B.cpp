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
    int h1,a1,c1,h2,a2;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    vector<string> ans;
    while (h2 > 0)
    {
        if (h2 <= a1)
        {
            ans.push_back("STRIKE");
            break;
        }
        else if (h1 <= a2)
        {
            ans.push_back("HEAL");
            h1 += c1;
        }
        else 
        {
            ans.push_back("STRIKE");
            h2 -= a1;
        }
        h1 -= a2;
    }
    cout << ans.size() << endl;
    for (string s : ans) cout << s << endl;
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