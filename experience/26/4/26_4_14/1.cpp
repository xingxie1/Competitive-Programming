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
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0;i < n;i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string s1;
            cin >> s1;
            if (s.find(s1) != string::npos) cout << s.find(s1) << endl;
            else cout << -1 << endl;
        }
        else if (op == 2)
        {
            string s2,s3;
            cin >> s2 >> s3;
            if (s.find(s2) != string::npos)
            {
                int j = s.find(s2);
                s.erase(s.begin() + j,s.begin() + j + s2.size());
                s.insert(j,s3);
            }   
            cout << s << endl;
        }
        else 
        {
            char c1,c2;
            string s4;
            cin >> c1 >> c2 >> s4;
            vt a;
            for (int i = 1;i < s.size();i++) 
            {
                if (s[i - 1] == c1 && s[i] == c2) a.push_back(i);
            }
            int sz = s4.size(),cnt = 0;
            for (int i : a) 
            {
                s.insert(i + cnt * sz,s4);
                cnt++;
            }
            cout << s << endl;
        }
    }
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