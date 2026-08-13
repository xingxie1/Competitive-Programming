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
    vvt a(n,vt());
    for (int i = 0;i < n;i++)
    {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0;j < m;j++) cin >> a[i][j];
        ranges::reverse(a[i]);
        unordered_set<int> s;
        vt tmp;
        for (int j = 0;j < m;j++)
        {
            if (!s.contains(a[i][j]))
            {
                tmp.push_back(a[i][j]);
                s.insert(a[i][j]);
            }
        }
        a[i] = tmp;
    }
    vt ans;
    unordered_set<int> s;
    int cur = 0;
    while (cur < n)
    {
        ranges::sort(a.begin() + cur,a.end());
        for (int x : a[cur]) 
        {
            if (!s.contains(x))
            {
                ans.push_back(x);
                s.insert(x);
                for (int j = cur + 1;j < n;j++)
                {
                    erase(a[j],x);
                }
            }   
        }
        cur++;
    }
    for (int x : ans) cout << x << " ";
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