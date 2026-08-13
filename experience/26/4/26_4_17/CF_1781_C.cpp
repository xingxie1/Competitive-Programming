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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vpii cnt(26);
    for (int i = 0;i < 26;i++) cnt[i].se = i;
    for (int i = 0;i < n;i++)
    {
        cnt[s[i] - 'a'].fi++; 
    }
    ranges::sort(cnt,{},[&](auto& a){
        return -a.fi;
    });
    string ans;
    int mn = INT_MAX,k = -1;
    for (int c = 1;c <= min(26,n);c++)
    {
        if (n % c) continue;
        int tt = n / c;
        int sum = 0;
        for (int i = 0;i < c;i++)
        {
            sum += max(0,tt - cnt[i].fi);
        }
        if (sum >= mn) continue;
        mn = sum;
        k = c;
    }
    int c = n / k;
    string t = s;
    set<char> st;
    vector<char> p;
    for (int i = 0;i < k;i++)
    {
        st.insert(cnt[i].se + 'a');
        char ch = cnt[i].se + 'a';
        int have = min(cnt[i].fi,c);
        int need = c - have;
        for (int j = 0;j < need;j++) 
        {
            p.push_back(ch);
        }
    }
    vt kept(26);
    int j = 0;
    for (int i = 0;i < n;i++)
    {
        if (st.contains(s[i]) && kept[s[i] - 'a'] < c) 
        {
            kept[s[i] - 'a']++;
        }
        else 
        {
            t[i] = p[j++];
        }
    }
    cout << mn << endl;
    cout << t << endl;

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