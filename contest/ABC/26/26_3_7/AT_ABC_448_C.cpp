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
    int n,q;
    cin >> n >> q;
    vt a(n);
    map<int,set<int>> p;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        p[a[i]].insert(i);
    }
    ranges::sort(a);
    set<int> s;
    while (q--)
    {
        int k;
        cin >> k;
        set<int> b;
        for (int i = 0;i < k;i++) 
        {
            int x;
            cin >> x;
            b.insert(x - 1);
        }
        int j = 0,flag = 1;
        for (int i = 0;i < n;i++)
        {
            int ff = 1;
            for (int j : p[a[i]]) 
            {
                if (!b.contains(j)) 
                {
                    cout << a[i] << endl;
                    ff = 0;
                    flag = 0;
                    break;
                }
            }
            if (!ff) break;
        }
        if (flag) cout << a[k] << endl;
    }
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