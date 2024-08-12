// https://oj.vnoi.info/problem/qmax
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 5e4 + 1;
int n, m, p;
int u, v, k;
int a[MAXN], d[MAXN];
int st[4 * MAXN];

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

int query(int u, int v, int id, int l, int r)
{
    if (u > r || v < l) return INT_MIN;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    int q1 = query(u, v, 2 * id, l, mid);
    int q2 = query(u, v, 2 * id + 1, mid + 1, r);
    return max(q1, q2);
}

int main()
{
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> k;
        d[u] += k;
        d[v + 1] -= k;
    }
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + d[i];
    build(1, 1, n);
    cin >> p;
    while(p)
    {
        cin >> u >> v;
        cout << query(u, v, 1, 1, n) << '\n';
        p--;
    }
    return 0;
}
