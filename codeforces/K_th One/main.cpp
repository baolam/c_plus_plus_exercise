#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
int n, m;
int a[MAXN], st[4 * MAXN];

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
    st[id] = st[2 * id] + st[2 * id + 1];
}

void update(int i, int id, int l, int r)
{
    if (i < l || i > r) return;
    if (l == r)
    {
        st[id] = st[id] == 1 ? 0 : 1;
        cout << "Update " << i << ' ' << st[id] << '\n';
        return;
    }
    int mid = (l + r) / 2;
    update(i, 2 * id, l, mid);
    update(i, 2 * id, mid + 1, r);
    st[id] = st[2 * id] + st[2 * id + 1];
}

int query(int k, int id, int l, int r)
{
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (k <= st[2 * id])
        return query(k, 2 * id, l, mid);
    return query(k - st[2 * id], 2 * id + 1, mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int op, x1;
    while (m)
    {
        cin >> op >> x1;
        if (op == 1) update(x1 + 1, 1, 1, n);
        else cout << query(x1 + 1, 1, 1, n) << '\n';
        m--;
    }
    return 0;
}
