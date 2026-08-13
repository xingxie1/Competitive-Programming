#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
// #define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    int mni = 1,mxi = 1;
    auto f = [&](int x,int y) 
    {
        char ch;
        cout << "? " << x <<  " " << y << endl;
        cin >> ch;
        return ch;
    };
    if (n % 2 == 0) 
    {
        char c = f(1,2);
        if (c == '<') mxi = 2;
        else mni = 2;
        for (int i = 3;i + 1 <= n;i+=2) 
        {
            char ch = f(i,i + 1);  
            if (ch != '>') 
            {
                char ch2 = f(mni,i);
                if (ch2 == '>') mni = i; 
                ch2 = f(mxi,i + 1);
                if (ch2 == '<') mxi = i + 1;
            }
            else
            {
                char ch2 = f(mni,i + 1);
                if (ch2 == '>') mni = i + 1; 
                ch2 = f(mxi,i);
                if (ch2 == '<') mxi = i;
            }
        }
    }
    else 
    {
        for (int i = 2;i + 1 <= n;i += 2)
        {
            char ch = f(i,i + 1);  
            if (ch != '>') 
            {
                char ch2 = f(mni,i);
                if (ch2 == '>') mni = i; 
                ch2 = f(mxi,i + 1);
                if (ch2 == '<') mxi = i + 1;
            }
            else
            {
                char ch2 = f(mni,i + 1);
                if (ch2 == '>') mni = i + 1; 
                ch2 = f(mxi,i);
                if (ch2 == '<') mxi = i;
            }
        }
    }
    cout << "! " << mni << " " << mxi << endl;
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