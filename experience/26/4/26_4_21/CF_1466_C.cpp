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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 1;i < n;i++) 
    {
        if (s[i] == s[i - 1]) 
        {
            ans++;
            char c;
            set<char> st;
            for (int j = i - 2;j <= i + 2;j++) 
            {
                if (j >= 0 && j < n) st.insert(s[j]);
            }
            for (char ch = 'a';ch <= 'z';ch++) 
            {
                if (!st.contains(ch)) 
                {
                    c = ch;
                    break;
                }
            }
            s[i] = c;
        }
        if (i >= 2 && s[i] == s[i - 2]) 
        {
            ans++;
            char c;
            set<char> st;
            for (int j = i - 2;j <= i + 2;j++) 
            {
                if (j >= 0 && j < n) st.insert(s[j]);
            }
            for (char ch = 'a';ch <= 'z';ch++) 
            {
                if (!st.contains(ch)) 
                {
                    c = ch;
                    break;
                }
            }
            s[i] = c;
        }
    }
    cout << ans << endl;

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