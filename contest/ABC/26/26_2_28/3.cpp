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
    string s,t;
    cin >> s >> t;
    int n = s.size(),m = t.size();
    map<char,int> cnt1,cnt2;
    for (int i = 0;i < s.size();i++)
    {
        if (s[i] != 'A') cnt1[s[i]]++;
    }   
    for (int i = 0;i < t.size();i++)
    {
        if (t[i] != 'A') cnt2[t[i]]++;
    } 
    if (cnt1 != cnt2) 
    {
        cout << -1 << endl;
        return ;
    }
    int j = 0,ans = 0;
    for (int i = 0;i < m;i++)
    {
        if (s[j] != t[i])
        {
            if (s[j] == 'A')
            {
                while (j < n && s[j] == 'A')
                {
                    ans++;
                    j++;
                }
                if (j == n) 
                {
                    ans += m - i;
                    break;
                }
            }
            if (t[i] == 'A')
            {
                while (i < m && t[i] == 'A')
                {
                    i++;
                    ans++;
                }
            }
            if (j < n && i < m && s[j] != t[i])
            {
                cout << -1 << endl;
                return ;
            }
        }
        j++;
    }
    if (j < n) ans += n - j;
    cout << ans;
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