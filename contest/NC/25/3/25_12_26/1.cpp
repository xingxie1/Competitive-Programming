#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    string a,b;
    cin >> a >> b;
    if (b.back() == '+' && a.back() == '+')
    {
        string tmp1(a.begin(),a.end() - 1);
        string tmp2(b.begin(),b.end() - 1);
        int x = stoi(tmp1);
        int y = stoi(tmp2);
        if (x > y) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if (a.back() == '+')
    {
        string tmp1(a.begin(),a.end() - 1);
        int x = stoi(tmp1);
        int y = stoi(b);
        if (x >= y) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if (b.back() == '+')
    {
        string tmp2(b.begin(),b.end() - 1);
        int x = stoi(a);
        int y = stoi(tmp2);
        if (x > y) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else 
    {
        int x = stoi(a);
        int y = stoi(b);
        if (x > y) cout << "Yes" << endl;
        else cout << "No" << endl;
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