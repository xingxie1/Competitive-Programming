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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    string s1,s2;
    cin >> s1 >> s2;
    int t,Q;
    cin >> t >> Q;
    int n = s1.size();
    vt p(n);
    for (int i = 0;i < n;i++)
    {
        if (s1[i] != s2[i]) p[i] = 0;
        else p[i] = 1;
    }
    int cnt = n - accumulate(p.begin(),p.end(),0);
    int time = 0;
    queue<int> q;
    // cout << cnt << endl;
    while (Q--)
    {
        int op;
        cin >> op;
        while (!q.empty() && time >= q.front()) 
        {
            q.pop();
            cnt++;
        }
        if (op == 1)
        {
            int pos;
            cin >> pos;
            pos--;
            // cout << s1[pos] << " " << s2[pos] << endl;
            if (!p[pos]) 
            {
                cnt--;
                q.push(time + t);
            }
        }
        else if (op == 2)
        {
            int id1,id2,pos1,pos2;
            cin >> id1 >> pos1 >> id2 >> pos2;
            pos1--,pos2--;
            if (!p[pos1]) cnt--;
            if (pos1 != pos2 && !p[pos2]) cnt--;
            char& c1 = (id1 == 1) ? s1[pos1] : s2[pos1];
            char& c2 = (id2 == 1) ? s1[pos2] : s2[pos2];
            swap(c1,c2);
            p[pos1] = (s1[pos1] == s2[pos1] ? 1 : 0);
            p[pos2] = (s1[pos2] == s2[pos2] ? 1 : 0);
            if (!p[pos1]) cnt++;
            if (pos1 != pos2 && !p[pos2]) cnt++;
        }
        else 
        {
            if (!cnt) YES;
            else NO;
        }
        // cout << cnt << endl;
        time++;
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