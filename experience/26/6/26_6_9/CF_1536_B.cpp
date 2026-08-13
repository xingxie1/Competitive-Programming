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
    string s;
    cin >> s;
    set<string> st;
    for (int i = 0;i < n;i++) 
    {
        for (int len = 1;len <= 3;len++)
        {
            st.insert(s.substr(i,len));
        }
    }
    for (int i = 0;i < 26;i++) 
    {
        string s;
        s += 'a' + i;
        if (!st.contains(s)) 
        {
            cout << s << endl;
            return ;
        }
    }
    for (int i = 0;i < 26;i++) 
    {
        for (int j = 0;j < 26;j++) 
        {
            string s;
            s += 'a' + i;
            s += 'a' + j;
            if (!st.contains(s)) 
            {
                cout << s << endl;
                return;
            }
        }
    }
    for (int i = 0;i < 26;i++) 
    {
        for (int j = 0;j < 26;j++) 
        {
            for (int k = 0;k < 26;k++) 
            {
                string s;
                s += 'a' + i;
                s += 'a' + j;
                s += 'a' + k;
                if (!st.contains(s)) 
                {
                    cout << s << endl;
                    return ;
                }
            }
        }
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