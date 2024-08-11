#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
const int INF = INT_MAX;

int n, m;
int a[MAXN];

struct SegmentTreeInfo
{
    int _min = INF;
    int _equal = 1;
};

SegmentTreeInfo _default;
SegmentTreeInfo st[4 * MAXN];
void _update_condition(int id)
{
    if (st[2 * id]._min < st[2 * id + 1]._min)
    {
        st[id]._min = st[2 * id]._min;
        st[id]._equal = st[2 * id]._equal;
    }
    else if (st[2 * id]._min > st[2 * id + 1]._min)
    {
        st[id]._min = st[2 * id + 1]._min;
        st[id]._equal = st[2 * id + 1]._equal;
    }
    else
    {
        st[id]._min = st[2 * id]._min;
        st[id]._equal = st[2 * id]._equal + st[2 * id + 1]._equal;
    }
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id]._min = a[l];
        st[id]._equal = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    _update_condition(id);
}

void update(int i, int v, int id, int l, int r)
{
    if (i < l || i > r) return;
    if (l == r)
    {
        st[id]._min = v;
        st[id]._equal = 1;
        return;
    }
    int mid = (l + r) / 2;
    update(i, v, 2 * id, l, mid);
    update(i, v, 2 * id + 1, mid + 1, r);
    _update_condition(id);
}

SegmentTreeInfo query(int u, int v, int id, int l, int r)
{
    if (l > v || r < u) return _default;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    SegmentTreeInfo q1 = query(u, v, 2 * id, l, mid);
    SegmentTreeInfo q2 = query(u, v, 2 * id + 1, mid + 1, r);
    SegmentTreeInfo out;
    if (q1._min < q2._min)
    {
        out._min = q1._min;
        out._equal = q1._equal;
    }
    else if (q1._min > q2._min)
    {
        out._min = q2._min;
        out._equal = q2._equal;
    }
    else
    {
        out._min = q1._min;
        out._equal = q1._equal + q2._equal;
    }
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int op, x1, x2;
    while (m)
    {
        cin >> op >> x1 >> x2;
        if (op == 1) update(x1 + 1, x2, 1, 1, n);
        else
        {
            SegmentTreeInfo ans = query(x1 + 1, x2, 1, 1, n);
            cout << ans._min << ' ' << ans._equal << '\n';
        }
        m--;
    }
    return 0;
}
