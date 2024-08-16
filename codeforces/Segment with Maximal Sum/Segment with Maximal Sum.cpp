#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
int a[MAXN];

struct SegmentTree
{
    ll seg = 0;
    ll pref = 0;
    ll suff = 0;
    ll sum = 0;

    void assign_value(int val)
    {
        seg = val;
        pref = val;
        suff = val;
        sum = val;
    }
};

int n, m;
SegmentTree st[4 * MAXN];

SegmentTree operator+(SegmentTree x1, SegmentTree x2)
{
    SegmentTree out;
    out.sum = x1.sum + x2.sum;
    out.pref = max(x1.pref, x1.sum + x2.pref);
    out.suff = max(x2.suff, x2.sum + x1.suff);
    out.seg = max(x1.seg, max(x2.seg, x1.suff + x2.pref));
    return out;
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id].assign_value(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = st[2 * id] + st[2 * id + 1];
}

void update(int i, int v, int id, int l, int r)
{
    if (i < l || i > r) return;
    if (l == r)
    {
        st[id].assign_value(v);
        return;
    }
    int mid = (l + r) / 2;
    update(i, v, 2 * id, l, mid);
    update(i, v, 2 * id + 1, mid + 1, r);
    st[id] = st[2 * id] + st[2 * id + 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    ll vl = st[1].seg < 0 ? 0 : st[1].seg;
    cout << vl << '\n';
    int i, v;
    while(m)
    {
        cin >> i >> v;
        update(i + 1, v, 1, 1, n);
        vl = st[1].seg < 0 ? 0 : st[1].seg;
        cout << vl << '\n';
        m--;
    }
    return 0;
}
