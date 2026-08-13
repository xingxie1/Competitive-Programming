#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int a,b,c,x;
    cin >> a >> b >> c >> x;
    if (c == x || b-c == x || a-b-c==x) cout <<"Yes"<<endl;
    else if ((a-2*b != 0) && (x - c) % (a - 2*b) == 0) cout << "Yes"<<endl;
    else if ((a-2*b != 0) && (x+c+a-3*b)%(2*b-a)==0)cout << "Yes"<<endl;
    else if ((a-2*b != 0) && (x+c-2*a+3*b)%(2*b-a)==0)cout << "Yes"<<endl;
    else cout << "No" << endl;
} 

int main()
{
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}