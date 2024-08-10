#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 1;
const int INF = INT_MAX;
ll segment_tree[4 * MAXN];

int a[MAXN];
int n;

void build(int id, int l, int r)
{
    if (l == r)
    {
        segment_tree[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);
    segment_tree[id] = segment_tree[2 * id] + segment_tree[2 * id + 1];
}

void update(int i, int v, int id, int l, int r)
{
    if (i < l || r < i) return;
    if (l == r)
    {
        segment_tree[id] = v;
        return;
    }
    int m = (l + r) / 2;
    if (i <= m) update(i, v, 2 * id, l, m);
    else update(i, v, 2 * id + 1, m + 1, r);
    segment_tree[id] = segment_tree[2 * id] + segment_tree[2 * id + 1];
}

ll sum(int u, int v, int id, int l, int r)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return segment_tree[id];
    int m = (l + r) / 2;
    ll s1 = sum(u, v, 2 * id, l, m);
    ll s2 = sum(u, v, 2 * id + 1, m + 1, r);
    return s1 + s2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("VAO.INP", "r", stdin);
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int op, x1, x2;
    for (int i = 1; i <= m; i++)
    {
        cin >> op >> x1 >> x2;
        if (op == 1) update(x1 + 1, x2, 1, 1, n);
        else cout << sum(x1 + 1, x2, 1, 1, n) << '\n';
    }
    return 0;
}
