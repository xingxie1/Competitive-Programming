#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ranges::sort(a);
    vt ans;
    for (int i = 0;i < n;i++)
    {
        vt tmp;
        tmp.push_back(a[i]);
        for (int j = 0;j <= 30;j++)
        {
            int t = (1 << j);
            auto it = ranges::lower_bound(a,a[i] + t);
            if (it != a.end() && *it == a[i] + t) 
            {
                tmp.push_back(*it);
                if (j == 30) break;
                auto it2 = ranges::lower_bound(a,a[i] + t * 2);
                if (it2 != a.end() && *it2 == a[i] + t * 2) 
                {
                    tmp.push_back(*it2);
                    break;
                }
                else 
                {
                    if (ans.size() < tmp.size()) ans = tmp;
                    tmp.pop_back();
                }
            }
        }
        if (tmp.size() > ans.size())
        {
            ans = tmp;
        }
        if (ans.size() == 3) break;
    }
    cout << ans.size() << endl;
    for (int x : ans) cout<< x << " ";
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