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
    stack<int> st;
    vt mask(n + 1);
    for (int i = 0;i < n;i++)
    {
        int t = ((s[i] == '(' || s[i] == ')') ? 1 : 2);
        if (st.empty()) st.push(t);
        else if (t == st.top())
        {
            st.pop();
            int dep = st.size();
            if (mask[dep] & 1 << t) 
            {
                NO;
                return;
            }
            mask[dep] |= 1 << t;
        }
        else st.push(t);
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