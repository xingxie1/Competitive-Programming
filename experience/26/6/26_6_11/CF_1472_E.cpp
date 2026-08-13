#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vvt a(n);
    vt ans(n,-1);
    for (int i = 0;i < n;i++) 
    {
        int x,y;
        cin >> x >> y;
        int mn = min(x,y);
        int mx = max(x,y);
        vt tmp = {mn,mx,i + 1};
        a[i] = tmp;
    }
    ranges::sort(a);
    int bestid = -1,mn = INT_MAX;
    for (int i = 0;i < n;i++) 
    {
        int y = a[i][1];
        int j = i;
        while (j < n && a[j][0] == a[i][0]) 
        {
            if (a[j][1] > mn) 
            {
                ans[a[j][2] - 1] = bestid;
            }
            j++;
        }
        for (int k = i;k < j;k++)
        {
            if (a[k][1] < mn) 
            {
                mn = a[k][1];
                bestid = a[k][2];
            }
        }
        i = j - 1;
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
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