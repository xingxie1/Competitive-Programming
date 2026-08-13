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
    int c0 = 0,c1 = 0,mni = 0,mxi = 0; 
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        if (a[i] >= 0)
        {
            c1 ++;
            if (a[i] > a[mxi]) mxi = i;
        }
        else 
        {
            c0++;
            if(a[i] < a[mni]) mni = i;
        }
    }
    vpii ans;
    if (c1 >= c0)
    {
        if (a[mxi] >= -a[mni])
        {
            for (int i = 0;i < n;i++)
            {
                if (a[i] < 0) 
                {
                    ans.push_back({i + 1,mxi + 1});
                }
            }
            for (int i = 1;i < n;i++) ans.push_back({i + 1,i});
        }
        else if (c0 <= 7 && a[mxi] > 0)
        {
            for (int i = 1;i <= 5;i++) ans.push_back({mxi + 1,mxi + 1});
            for (int i = 0;i < n;i++)
            {
                if (a[i] < 0) 
                {
                    ans.push_back({i + 1,mxi + 1});
                }
            }
            for (int i = 1;i < n;i++) ans.push_back({i + 1,i});
        }
        else 
        {
            for (int i = 0;i < n;i++)
            {
                if (a[i] > 0) ans.push_back({i + 1,mni + 1});
            }
            for (int i = n - 2;i >= 0;i--) ans.push_back({i + 1,i + 2});
        }
    }
    else 
    {
        if (-a[mni] >= a[mxi])
        {
            for (int i = 0;i < n;i++)
            {
                if (a[i] > 0) ans.push_back({i + 1,mni + 1});
            }
            for (int i = n - 2;i >= 0;i--) ans.push_back({i + 1,i + 2});
        }
        else if (c1 <= 7)
        {
            for (int i = 1;i <= 5;i++) ans.push_back({mni + 1,mni + 1});
            for (int i = 0;i < n;i++)
            {
                if (a[i] > 0) ans.push_back({i + 1,mni + 1});
            }
            for (int i = n - 2;i >= 0;i--) ans.push_back({i + 1,i + 2});
        }
        else 
        {
            for (int i = 0;i < n;i++)
            {
                if (a[i] < 0) 
                {
                    ans.push_back({i + 1,mxi + 1});
                }
            }
            for (int i = 1;i < n;i++) ans.push_back({i + 1,i});
        }
    }
    cout << ans.size() << endl;
    for (auto& [l,r] : ans) cout << l << " " << r << endl;
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