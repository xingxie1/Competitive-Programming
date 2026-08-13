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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    string s = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
    // string s = "012345";
    auto f = [&](char d,char o)
    {
        if (d == '0')
        {
            if (o == '0') return '3';
            else if (o == '1') return '0';
            else if (o == '2') return '1';
            else if (o == '3') return '2';
            else if (o == '4') return '1';
            else return '3';
        }
        else if (d == '1')
        {
            if (o == '0') return '2';
            else if (o == '1') return '3';
            else if (o == '2') return '0';
            else if (o == '3') return '1';
            else if (o == '4') return '2';
            else return '0';
        }
        else if (d == '2')
        {
            if (o == '0') return '1';
            else if (o == '1') return '2';
            else if (o == '2') return '3';
            else if (o == '3') return '0';
            else if (o == '4') return '3';
            else return '1';
        }
        else 
        {
            if (o == '0') return '0';
            else if (o == '1') return '1';
            else if (o == '2') return '2';
            else if (o == '3') return '3';
            else if (o == '4') return '0';
            else return '2';
        }
    };
    char cur = '0';
    for (char c : s)
    {
        cur = f(cur,c);
        cout << cur;
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