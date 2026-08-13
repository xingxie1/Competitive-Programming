#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n = 10;
    vt a = {0,1,2,3,4,5,6,7,8,9};
    do
    {
        vt b = a,c = a;
        for (int i = 0;i < n;i++)
        {
            vt bb = b;
            ranges::reverse(bb.begin(),bb.begin() + i);
            ranges::reverse(bb.begin() + i,bb.end());
            ranges::reverse(bb);
            for (int j = 0;j < n;j++)
            {
                vt cc = c;
                ranges::reverse(cc.begin(),cc.begin() + j);
                ranges::reverse(cc.begin() + j,cc.end());
                ranges::reverse(cc);
                vt ans(n);
                for (int k = n - 1;k >= 0;k--)
                {
                    ans[k] += (bb[k] + cc[k]);
                    if (ans[k] >= n && k - 1 >= 0) 
                    {
                        ans[k - 1]++;
                        ans[k] -= n;
                    }
                    if (ans[k] >= n && k == 0) 
                    {
                        continue;
                    }
                }
                // cout << "a : " << endl;
                // for (int x : a) cout << x << " ";
                // cout << endl;
                // cout << "bb : " << endl;
                // for (int x : bb) cout << x << " ";
                // cout << endl;
                // cout << "cc : " << endl;
                // for (int x : cc) cout << x << " ";
                // cout << endl;
                if (a == ans) 
                {
                    cout << "YES" << endl;
                    cout << "a : " << endl;
                    for (int x : a) cout << x << " ";
                    cout << endl;
                    for (int x : bb) cout << x << " ";
                    cout << endl;
                    for (int x : cc) cout << x << " ";
                    cout << endl;
                }
            }
        }

    } while (next_permutation(a.begin(),a.end()));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}