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
    int cnt = 0;
    for (char c : s) cnt += c == ')';
    if (cnt != n - cnt)
    {
        cout << -1 << endl;
        return ;
    }
    auto f = [&](char t)
    {
        stack<int> st;
        vt a(n);
        for (int i = 0;i < n;i++)
        {
            if (s[i] == t) st.push(i);
            else 
            {
                if (!st.empty()) 
                {
                    a[st.top()] = a[i] = 1;
                    st.pop();
                }
            }
        }
        int tt = ranges::max(a) + 1;
        for (int& x : a)
        {
            if (x == 0) x = tt;
        }
        return a;
    };
    vt ans = f('(');
    vt tmp = f(')');
    if (ranges::max(tmp) < ranges::max(ans)) ans = tmp;
    
    cout << ranges::max(ans) << endl;
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