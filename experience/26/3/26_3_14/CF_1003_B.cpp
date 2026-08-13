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
    int a,b,x;
    cin >> a >> b >> x;
    char c = '0';
    if (b > a) c = '1';
    string s;
    while (x > 1)
    {
        s += c;
        x--;
        if (c == '0') 
        {
            c = '1';
            a--;
        }
        else 
        {
            c = '0';
            b--;
        }
        if (x == 1) 
        {
            break;
        }
    }
    if (c == '0') 
    {
        s.insert(s.end(),a,'0');
        s.insert(s.end(),b,'1');
    }
    else 
    {
        s.insert(s.end(),b,'1');
        s.insert(s.end(),a,'0');
    }
    cout << s << endl;
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