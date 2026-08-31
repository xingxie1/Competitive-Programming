class FenwickTree
{
    vt tr;
public:
    FenwickTree (int n) : tr(n + 1) {}
    void update(int i,int v) 
    {
        for (;i < tr.size();i += i & -i) tr[i] += v;
    }
    int pre(int i) 
    {
        int res = 0;
        for (;i > 0;i &= i - 1) 
        {
            res += tr[i];
        }
        return res;
    }
    int qyery(int l,int r) 
    {
        if (r < l) return 0;
        return pre(r) - pre(l - 1);
    }
};