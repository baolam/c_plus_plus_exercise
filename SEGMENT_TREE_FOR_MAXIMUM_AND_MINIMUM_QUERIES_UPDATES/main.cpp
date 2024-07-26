#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 2;

int n, u, v;
int code;
ll a[N], tree[4 * N];

void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = a[st];
        return;
    }

    int mid = st + (en - st) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return INT_MIN;

    if (l <= st && en <= r)
        return tree[node];

    int mid = st + (en - st) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);

    return max(q1, q2);
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        a[st] = val;
        tree[node] = val;
        return;
    }

    int mid = st + (en - st) / 2;
    if (idx <= mid) update(2 * node, st, mid, idx, val);
    else update(2 * node + 1, mid + 1, en, idx, val);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (1)
    {
        cin >> code;
        if (code == -1)
            break;
        if (code == 1)
        {
            cin >> u >> v;
            cout << query(1, 1, n, u, v) << '\n';
        }
        else
        {
            cin >> u >> v;
            update(1, 1, n, u, v);
            cout << query(1, 1, n, 1, n) << '\n';
        }
    }
    return 0;
}
