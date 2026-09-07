#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using vll = vector<ll>;
using pii = pair<int,int>;

struct Node
{
    Node* son[26]{};
    bool end = false;
    int cnt = 0;
    int len = 0;
};
class Trie
{
    Node* root = new Node();
public:
    vt mx;
    ll ans;
    int t;
    Trie(int n) 
    {
        mx.assign(n + 1,0);
        ans = 0;
        t = 0;
    }
    void insert(string s) 
    {
        Node* cur = root;
        t++;
        for (char c : s) 
        {
            c -= 'a';
            if (cur -> son[c] == nullptr) 
            {
                cur->son[c] = new Node();
                cur->son[c]->len = cur->len + 1;
            }
            cur = cur->son[c];
            (cur -> cnt)++;
            if (mx[cur -> cnt] < (cur->len)) 
            {
                if (mx[cur -> cnt] > 0) ans -= mx[cur -> cnt] ^ (cur -> cnt);
                else if (mx[cur -> cnt] < 0) ans -= cur -> cnt;
                // cout << mx[cur -> cnt] << " " << cur -> cnt << " " << cur -> len << endl; 
                ans += (cur -> len) ^ (cur -> cnt);
                mx[cur -> cnt] = cur -> len;
            }
        }
        if (mx[t] == 0) 
        {
            // cout << "t : " << t << endl;
            ans += t;
            mx[t] = -1;
        }
        cur -> end = true;
    }
    void print()
    {
        for (int x : mx) cout << x << " ";
        cout << endl;
    }
};
void solve()
{
    int n;
    cin >> n;
    Trie tr(n);
    for (int i = 0;i < n;i++)
    {
        string s;
        cin >> s;
        tr.insert(s);
        // tr.print();
        cout << tr.ans << endl;
        // cout << endl;
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}