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
    vector<string> a(n);
    for (int i  = 0;i < n;i++) cin >> a[i];
    ranges::sort(a,{},[](const auto& s){
        return s.size();
    });
    set<string> st;
    for (string& s : a) 
    {
        for (auto& t : st)
        {
            if (s.find(t) == string::npos) 
            {
                cout << "NO" << endl;
                return ;
            }
        }
        st.insert(s);
    }
    cout << "YES" << endl;
    for (auto& s : a) cout << s << endl;
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