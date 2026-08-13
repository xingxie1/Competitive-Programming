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
    int n, k;
    cin >> n >> k;
    vt a(n),b;
    for (int i = 0;i < n;i++) cin >> a[i];
    if (n == k)
    {
        for (int i = 1;i < n;i += 2) b.push_back(a[i]);
    }
    else 
    {
        for (int i = 1;i < n - k + 2;i++)
        {
            if (a[i] != 1) 
            {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
        return ;
    }
    for (int i = 0;i < b.size();i++)
    {
        if (b[i] != i + 1) 
        {
            cout << i + 1 << endl;
            return ;
        }
    }
    cout << b.size() + 1 << endl;
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