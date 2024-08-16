#include <bits/stdc++.h>
#define maxn 100002
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair <ll, ll> II;

int n;
ll h[maxn];
II a[maxn];

bool Compare(II z, II t)
{
    if (z.x == t.x)
        return z.y <= t.y;
    return z.x < t.x;
}

int main()
{
    memset(h, 0, sizeof(h));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("VAO.INP", "r", stdin);
    //freopen("RA.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a+1, a+1+n, Compare);
    int nRobots = 0;
    for (int i = 1; i <= n; i++)
    {
        int tungdo = a[i].y;
        int l = 1, r = nRobots;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (h[m] > tungdo)
                l = m + 1;
            else r = m;
        }
        h[l] = tungdo;
        if (l > nRobots)
            nRobots++;
    }
    cout << nRobots;
    return 0;
}
