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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    int sum = 0;
    int len1 = 0,len2 = INT_MAX;
    for (char c : s)
    {
        if (c == '+')
        {
            sum++;
            if (sum == 1) len1 = 1;
        }
        else if (c == '-')
        {
            sum--;
            len1 = min(len1,sum);
            if (len2 > sum) len2 = INT_MAX;
        }
        else if (c == '1')
        {
            len1 = sum;
            if (len2 <= sum) 
            {
                cout << "NO" << endl;
                return ;
            }
        }
        else 
        {
            if (sum < 2) 
            {
                cout << "NO" << endl;
                return ;
            }
            if (len1 == sum)
            {
                cout << "NO" << endl;
                return ;
            }
            len2 = min(len2,sum);
        }
        
    }
    cout << "YES" << endl;
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