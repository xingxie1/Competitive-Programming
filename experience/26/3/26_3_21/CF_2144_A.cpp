#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt pre(n + 1),suf(n + 1);
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] + a[i];

    for (int i = 1;i < n - 1;i++)
    {
        for (int j = i + 1;j < n;j++)
        {
            int s1 = pre[i] % 3,s2 = (pre[j] - pre[i]) % 3,s3 = (pre[n] - pre[j]) % 3;
            if ((s1 == s2 && s2 == s3) || (s1 != s2 && s2 != s3 && s1 != s3)) 
            {
                cout << i << " " << j << endl;
                return ;
            }
        }
    }
    cout << "0 0" << endl;

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