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
    int n,m;
    cin >> n >> m;
    vvt a(n,vt(m));
    int sum = 0;
    vt cnt(n);
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            cin >> a[i][j];
            cnt[i] += a[i][j];
            sum += a[i][j];
        }
    }   
    if (sum % n) 
    {
        cout << -1 << endl;
        return ;
    }
    // for (int x : cnt) cout << x << endl;
    int t = sum / n;
    vvt ans;
    for (int j = 0;j < m;j++)
    {
        vt p0,p1;
        for (int i = 0;i < n;i++)
        {
            if (a[i][j] && cnt[i] > t)
            {
                // cout << i << " " << j << endl;
                if (p0.size()) 
                {
                    ans.push_back({i + 1,p0.back() + 1,j + 1});
                    cnt[i]--;
                    cnt[p0.back()]++;
                    p0.pop_back();
                }
                else p1.push_back(i);
            }
            else if (!a[i][j] && cnt[i] < t)
            {
                if (p1.size())
                {
                    ans.push_back({i + 1,p1.back() + 1,j + 1});
                    cnt[i]++;
                    cnt[p1.back()]--;
                    p1.pop_back();
                }
                else p0.push_back(i);
            }
        }
    }
    for (int x : cnt) 
    {
        if (x != t) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    cout << ans.size() << endl;
    for (auto& g : ans) 
    {
        cout << g[0] << " " << g[1] << " " << g[2] << endl;
    }
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