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
    int xa,ya,xb,yb;
    cin >> xa >> ya >> xb >> yb;
    if (xa == xb)
    {
        int h = abs(ya - yb);
        if (h == 0)
        {
            cout << "no answer" << endl;
            return ;
        }
        double d = 4.0 / h;
        printf ("%.10lf",d + xa); 
    }
    else if (ya == 0 && yb == 0)
    {
        cout << "no answer" << endl;
    }
    else if (ya == 0)
    {
        double h = abs(yb);
        double d = 4.0 / h;
        printf("%.10lf",xa + d);
    }
    else if (yb == 0)
    {
        double h = abs(ya);
        double d = 4.0 / h;
        printf("%.10lf",xb + d);
    }
    else if (ya == yb)
    {
        int h = abs(ya);
        int d = abs(xa - xb);
        if (abs(h * d - 4) <= 0.001)
        {
            cout << 1 << endl;
        }
        else 
        {
            cout << "no answer" << endl;
        }
    }
    else 
    {
        int A = ya - yb,B = xb - xa,C = ya * (xa - xb) - xa * (ya - yb);
        double x0 = (-4 - C) * 1.0 / A;
        printf("%.10lf",x0);
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