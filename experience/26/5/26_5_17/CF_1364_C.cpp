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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int mex = 0,mx = 1e6;
    vt p;
    vt b(n);
    for (int i = 0;i < n;i++) 
    {
        if (mex == a[i]) p.push_back(i);
        else if (a[i] > mex)
        {
            for (int x = mex + 1;x < a[i];x++) 
            {
                if (p.empty()) 
                {
                    cout << -1 << endl;
                    return ;
                }
                int j = p.back();
                p.pop_back();
                b[j] = x;
            }
            b[i] = mex;
            mex = a[i];
        }
        else 
        {
            cout << -1 << endl;
            return ;
        }
    }
    while (!p.empty()) 
    {
        b[p.back()] = mx;
        p.pop_back();
    }
    for (int x : b) cout << x << " ";
    cout << endl;

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