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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    int m;
    cin >> m;
    multiset<int> s;
    int last,flag = 0;
    for (int i = 0;i < m;i++)
    {
        int x;
        cin >> x;
        s.insert(x);
        if (i == m - 1) last = x;
    }
    for (int i = 0;i < n;i++)
    {
        if (a[i] != b[i])
        {
            if (s.contains(b[i]))
            {
                s.erase(s.find(b[i]));
            }
            else 
            {
                cout << "NO" << endl;
                return ;
            }
        }
        if (b[i] == last) flag = 1;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
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