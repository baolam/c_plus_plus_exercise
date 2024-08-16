#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 12;
int n;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("PERMUTE.INP", "r", stdin);
    freopen("PERMUTE.OUT", "w", stdout);
    cin >> n;
    a[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    int i = n;
    do
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << '\n';
        i = n;
        while (i > 0 && a[i] < a[i - 1])
            i--;
        i--;
        if (i > 0)
        {
            int j = n;
            for (; j >= i + 1; j--)
            {
                if (a[j] > a[i])
                    break;
            }
            swap(a[i], a[j]);
            int l = i + 1, r = n;
            while (l <= r)
            {
                swap(a[l], a[r]);
                l++; r--;
            }
        }

    } while (i > 0);
    return 0;
}
