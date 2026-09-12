#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;

void solve()
{
    int n,p;
    cin >> n >> p;
    int sum = 0;
    for (int i = 0;i < n;i++)
    {
        string s;
        cin >> s;
        if (s == "UnreasonableProblemArrangement") sum += 10;
        else 
        {
            char c1 = s.back();
            if (c1 < 'A' || c1 > 'Z') continue;
            s.pop_back();
            char c2 = s.back();
            if (c2 >= 'A' && c2 <= 'Z') continue;
            if (c1 > 'L') continue;
            if (s == "WrongProblem") sum += 100;
            else if (s == "SameProblem") sum += 30;
            else if (s == "UnreasonableLimitForProblem") sum += 5;
            else if (s == "WeakTestsForProblem") sum += 3;
            else if (s == "BadProblem") sum += 1;
        }
    }
    // cout << sum << endl;
    if (sum > p) cout << "Joker" << endl;
    else cout << "Judger" << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

}