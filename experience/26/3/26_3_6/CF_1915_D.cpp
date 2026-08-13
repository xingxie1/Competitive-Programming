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
    string s;
    cin >> s;
    set<char> V = {'a','e'},C = {'b','c','d'};
    string ans;
    for (int i = 0;i < n;i++)
    {
        if (C.contains(s[i])) ans += s[i];
        else
        {
            ans += s[i];
            if (i + 1 >= n) break;
            if (i + 2 >= n) 
            {
                ans += s[i + 1];
                break;
            }
            if (C.contains(s[i + 2]))
            {
                ans += s[i + 1];
                ans += '.';
                i++;
            }
            else 
            {
                ans += '.';
            }
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