#include <bits/stdc++.h>
#define maxn 100001

using namespace std;
typedef long long ll;

int n, x;
int a[maxn];

int leftest()
{
    int l = 1, r = n;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if ((m == 0 || a[m - 1] < x) && a[m] == x)
            return m;
        if (x > a[m]) l = m + 1;
        else r = m - 1;
    }
    return 0;
}

int righest()
{
    int l = 1, r = n;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if ((m == n || x < a[m + 1]) && a[m] == x)
            return m;
        if (x < a[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+1+n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    cin >> x;
    int r = righest();
    int l = leftest();
    cout << x << " o trai cung la: " << l << '\n';
    cout << x << " o phai cung la: " << r << '\n';
    cout << x << " co so phan tu la: " << r - l + 1 << '\n';
    return 0;
}
