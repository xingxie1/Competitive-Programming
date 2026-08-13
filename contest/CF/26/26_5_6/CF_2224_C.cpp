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
    string a,b;
    cin >> a >> b;
    int s1 = 0,s2 = 0;
    for (char c : a) 
    {
        s1 += (c == '(');
        s2 += (c == ')');
    }
    for (char c : b) 
    {
        s1 += (c == '(');
        s2 += (c == ')');
    }
    if (s1 != s2) 
    {
        NO;
        return ;
    }
    s1 = s2 = 0;
    for (int i = 0;i < n;i++) 
    {
        if (a[i] == b[i]) 
        {
            if (a[i] == '(') 
            {
                s1--;
                s2--;
            }
            else 
            {
                s1++;
                s2++;
            }
        }
        else 
        {
            if (s1 < s2) 
            {
                s1++;
                s2--;
            }
            else 
            {
                s1--;
                s2++;
            }
        }
        if (s1 > 0 || s2 > 0) 
        {
            NO;
            return ;
        }
    }
    if (s1 || s2) NO;
    else YES;
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