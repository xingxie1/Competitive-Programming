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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    ll sum = 0;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n)
    {
        NO;
        return ;
    }
    int t = sum / n;
    for (int x : a) 
    {
        if (abs(x - t) > 1) 
        {
            NO;
            return ;
        }
    }
    a.insert(a.end(),a.begin(),a.end());
    int j = 0;
    for (int i = 0;i < n;i++)
    {
        if (a[i] > t) 
        {
            j = i;
            break;
        }
    }
    int cnt = 0;
    for (int i = j;i < n + j;i++) 
    {
        if (a[i] > t) cnt++;
        else if (a[i] < t) cnt--;
        if (cnt < 0 || cnt > 1) 
        {
            NO;
            return ;
        }
    }
    YES;
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