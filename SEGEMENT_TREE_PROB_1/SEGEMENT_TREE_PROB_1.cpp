#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 2;
int n;
int a[N], tree[4 * N];

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

    /// Phần tính toán tổng
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int st, int en, int l, int r)
{
    /// Cài đặt intersect là rỗng
    if (st > r || en < l)
        return 0;
    if (l <= st && en <= r)
        return tree[node];
    //if (st == en)
        //return tree[node];
    int mid = st + (en - st) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);
    return q1 + q2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);

    return 0;
}
