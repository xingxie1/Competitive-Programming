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
// #define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s;
    auto query = [&](string s)
    {
        cout << "? " << s << endl;
        int a;
        cin >> a;
        return a;
    };
    while (s.size() < n)
    {
        string t1 = s,t2 = s;
        t1 += '1';
        t2 += '0';
        int a;
        a = query(t1);
        if (a == 1)
        {
            s = t1;
            if (s.size() == n) break;
            continue;
        }
        a = query(t2);
        if (a == 1) 
        {
            s = t2;
        }
        else break;
        if (s.size() == n) break;
    }
    while (s.size() < n)
    {
        string t1(1,'0'),t2(1,'1');
        t1 += s;
        t2 += s;
        int a = query(t1);
        if (a == 1)
        {
            s = t1;
            if (s.size() == n) break;
            continue;
        }
        s = t2;
        if (s.size() == n) break;
    }
    cout << "! " << s << endl;
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