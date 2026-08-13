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
    for (int i = 0;i < n;i++) cin >> a[i];
    int s = abs(a[0]),cnt = 0;
    for (int i = 1;i < n;i ++) cnt += abs(a[i]);
    
    if ((s % 2 + 2) % 2 == cnt % 2 && cnt >= s)
    {
        vpii ans;
        int l = 1,sum = a[0];
        for (int i = 1;i < n;i++)
        {
            if (a[i] == 0) continue;
            else if (a[i] == 1)
            {
                if (sum == -1)
                {
                    ans.push_back({l,i});
                    l = i + 1;
                    sum = 0;
                }
                else if (sum == 0)
                {
                    sum = 1;
                    ans.push_back({l,i});
                    l = i + 1;
                }
                else 
                {
                    int d = i - l + 1;
                    if (d % 2 == 0)
                    {
                        ans.push_back({l,l});
                        l++;
                    }
                    sum = 0;
                }
            }
            else 
            {
                if (sum == 1)
                {
                    ans.push_back({l,i});
                    l = i + 1;
                    sum = 0;
                }
                else if (sum == 0)
                {
                    sum = -1;
                    ans.push_back({l,i});
                    l = i + 1;
                }
                else 
                {
                    int d = i - l + 1;
                    if (d % 2 == 0)
                    {
                        ans.push_back({l,l});
                        l++;
                    }
                    sum = 0;
                }
            }
        }
        ans.push_back({l,n});
        cout << ans.size() << endl;
        for (auto&[l,r] : ans) cout << l << " " << r << endl;
    }
    else 
    {
        cout << -1 << endl;
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