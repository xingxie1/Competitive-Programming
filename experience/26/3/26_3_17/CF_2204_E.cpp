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
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    int sum = 0;
    vt cnt(10);
    auto getsum = [&](string& s)
    {
        int sum = 0;
        for (char c : s) sum += c - '0';
        return sum;
    };
    auto getcnt = [&](string& s)
    {
        vt cnt(10);
        for (char c : s) cnt[c - '0']++;
        return cnt;
    };
    auto cmp = [&](vt& c1,vt& c2)
    {
        for (int i = 0;i < 10;i++)
        {
            if (c1[i] > c2[i]) return 0;
        }
        return 1;
    };
    sum = getsum(s);
    cnt = getcnt(s);
    if (s.size() == 1) 
    {
        cout << s << endl;
        return ;
    }
    for (int i = 1;i <= 9 * s.size();i++)
    {
        string t;
        int v = i;
        while (1)
        {
            string tt = to_string(v);
            t += tt;
            if (v <= 9) break;
            v = getsum(tt);
        }
        int sum1 = getsum(t);
        vt cnt1 = getcnt(t);
        if (sum1 + i != sum) continue;
        if (cmp(cnt1,cnt))
        {
            string ans;
            for (int i = 1;i < 10;i++)
            {
                int d = cnt[i] - cnt1[i];
                ans.insert(ans.end(),d,'0' + i);
            }
            if (cnt[0] - cnt1[0] > 0) ans.insert(ans.end(),cnt[0] - cnt1[0],'0');
            ans += t;
            cout << ans << endl;
            return ;
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