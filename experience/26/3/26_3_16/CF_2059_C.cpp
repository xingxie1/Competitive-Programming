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
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vvt a(n,vt(n));
    vt cnt(n);
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++) 
        {
            cin >> a[i][j];
        }
        for (int j = n - 1;j >= 0;j--)
        {
            if (a[i][j] == 1) cnt[i]++;
            else break;
        }
    }
    ranges::sort(cnt,{},[&](auto& x){
        return -x;
    });
    int ans = 0;
    for (int mex = n;mex > 0;mex--)
    {
        int flag = 1;
        for (int i = 0;i < mex;i++)
        {
            if (cnt[i] < mex - i - 1) flag = 0;
        }
        if (flag)
        {
            ans = mex;
            break;
        }
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