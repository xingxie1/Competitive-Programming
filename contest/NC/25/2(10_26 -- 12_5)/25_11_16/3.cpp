#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ax1,ax2,ay1,ay2;
    if (x1 == x2)
    {
        ax1 = x1 + 1;
        ax2 = ax1;
        ay1 = y1;
        ay2 = y2;
    }
    else if (y1 == y2)
    {
        ax1 = x1;
        ax2 = x2;
        ay1 = y1 - 1;
        ay2 = y2 - 1;
    }
    else 
    {

        ax1 = x1;
        ay1 = y2;
        ax2 = x2;
        ay2 = y1;
        
    }
    cout << ax1 << " " << ay1 << " " << ax2 << " " << ay2 ;
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