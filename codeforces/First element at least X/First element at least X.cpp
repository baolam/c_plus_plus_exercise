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
    st[id] = max(st[2 * id], st[2 * id + 1]);
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
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int first_above(int x, int id, int l, int r)
{
    if (x > st[id])
        return 0;
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (x <= st[2 * id])
        return first_above(x, 2 * id, l, mid);
    return first_above(x, 2 * id + 1, mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int op;
    while (m)
    {
        cin >> op;
        if (op == 1)
        {
            int i, v;
            cin >> i >> v;
            update(i + 1, v, 1, 1, n);
        }
        else
        {
            int x;
            cin >> x;
            cout << first_above(x, 1, 1, n) - 1 << '\n';
        }
        m--;
    }
    return 0;
}
