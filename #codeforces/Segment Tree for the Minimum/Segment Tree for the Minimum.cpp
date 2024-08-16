#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
const int INF = INT_MAX;

int a[MAXN], st[4 * MAXN];
int n;

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

void update(int i, int v, int id, int l, int r)
{
    if (i < l || i > r) return;
    if (l == r)
    {
        st[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(i, v, 2 * id, l, mid);
    update(i, v, 2 * id + 1, mid + 1, r);
    st[id] = min(st[2 * id], st[2 * id + 1]);
}

int query(int u, int v, int id, int l, int r)
{
    if (u > r || v < l) return INF;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    int m1 = query(u, v, 2 * id, l, mid);
    int m2 = query(u, v, 2 * id + 1, mid + 1, r);
    return min(m1, m2);
}

int main()
{
    int m;
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
        else cout << query(x1 + 1, x2, 1, 1, n) << '\n';
        m--;
    }
    return 0;
}
