#include <bits/stdc++.h>
#define maxn 200
#define maxk 200
#define maxv 40000

using namespace std;
typedef long long ll;

int n;
int t[maxs], a[maxn], kq[maxn];

int main()
{
    memset(t, 0, sizeof(t));
    // Đánh dấu cách chia
    memset(kq, 0, sizeof(kq));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("CHIA_KEO.INP", "r", stdin);
    freopen("CHIA_KEO.OUT", "w", stdout);

    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];

    int _m = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = _m; j >= 0; j--)
            if (t[j] > 0 && t[j + a[i]] == 0)
                t[j + a[i]] = i;
        _m += a[i];
    }
    int tong = sum / 2;
    while (t[tong] == 0)
        tong--;
    do {
        kq[t[tong]] = 1;
        tong -= a[t[tong]];
    } while (tong != 0);

    return 0;
}
