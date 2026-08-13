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
    int mxi = 0;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
    }
    for (int i = 0;i < n;i++)
    {
        int flag = 0;
        for (int j = i + 1;j < n;j++)
        {
            if (a[j] < a[i]) flag = 1;
        }
        if (flag) 
        {
            cout << 1 << endl;
            return ;
        }
    }
    cout << n << endl;
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