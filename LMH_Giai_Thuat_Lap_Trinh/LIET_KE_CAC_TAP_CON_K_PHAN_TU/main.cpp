#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 30;
int n, k;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("SUBSET.INP", "r", stdin);
    freopen("SUBSET.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        a[i] = i;
    int i = k;
    do
    {
        for (int i = 1; i <= k; i++)
            cout << a[i] << ' ';
        cout << '\n';
        i = k;
        while (i > 0 && a[i] == n - k + i)
            i--;
        if (i > 0)
        {
            a[i]++;
            for (int j = i + 1; j <= k; j++)
                a[j] = a[j - 1] + 1;
        }

    } while (i > 0);
    return 0;
}
