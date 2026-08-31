#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
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
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    cin.ignore();
    map<string,set<string>> p;
    map<string,int> pos;
    for (int i = 0;i < n;i++) 
    {
        string s;
        getline(cin,s);
        string ss;
        for (char c : s) 
        {
            if (c == ' ') continue;
            ss += c;
        }
        s = ss;
        string t;
        for (char c : s) 
        {
            if (c <= 'Z') t += c;
        }
        p[t].insert(s);//缩写,原
        pos[s] = i;
        // cout << t << endl;
    }
    while (1)
    {
        // cout << cnt << endl;
        map<string,set<string>> np = p;
        for (auto& [s,st] : p)
        {
            if (st.size() == 1) continue;
            for (string t : st)
            {
                if (s == t) continue;
                string tt;
                int j = s.size(),cnt = 0;
                for (int i = 0;i < s.size();i++) 
                {
                    if (t[i] != s[i]) 
                    {
                        j = i;
                        for (int k = i;k < t.size();k++) 
                        {
                            if (t[k] <= 'Z') break;
                            cnt++;
                        }
                        tt += t.substr(i,cnt);
                        tt += s.substr(i);
                        break;
                    }
                    tt += s[i];
                }
                if (j == s.size()) tt += t.substr(j);

                    // cout << tt << endl;
                np[tt].insert(t);
                np[s].erase(t);
                if (np[s].empty()) np.erase(s);
                
            }
        }
        if (p == np) break;
        p = np;
    }
    vector<string> ans(n);
    for (auto& [s,st] : p)
    {
        string t = *st.begin();
        // cout << s << endl;
        ans[pos[t]] = s;
    }
    for (string s : ans) cout << s << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}