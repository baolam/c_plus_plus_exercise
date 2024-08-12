#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
int n, m;
int a[MAXN];

struct SegmentTree
{
    int idx = -1;
    int sum = 1;

    void assgn(int i)
    {
        idx = i;
        sum = a[i];
    }
};

SegmentTree operator+(SegmentTree x1, SegmentTree x2)
{
    SegmentTree out;
    out.sum = x1.sum + x2.sum;
    return out;
}

SegmentTree st[4 * MAXN];
void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id].assgn(l);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = st[2 * id] + st[2 * id + 1];
}

void update(int i, int id, int l, int r)
{
    if (i < l || i > r) return;
    if (l == r)
    {
        st[id].sum = ! st[id].sum;
        return;
    }
    int mid = (l + r) / 2;
    update(i, 2 * id, l, mid);
    update(i, 2 * id + 1, mid + 1, r);
    st[id] = st[2 * id] + st[2 * id + 1];
}

int query(int k, int id)
{
    if (k == 0)
        return st[id].idx;
    if (k < st[id].sum)
        return query(k, 2 * id);
    else return query(k - st[2 * id].sum, 2 * id + 1);
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int op, x;
    while (m)
    {
        cin >> op >> x;
        if (op == 1) update(x + 1, 1, 1, n);
        else cout << query(x + 1, 1) << '\n';
        m--;
    }
    return 0;
}
