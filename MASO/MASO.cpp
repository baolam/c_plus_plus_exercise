#include <bits/stdc++.h>
#define maxn 30001

using namespace std;
typedef long long ll;

int n, x;
int a[maxn];

int main()
{
    memset(a, 0, sizeof(a));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x, a[x]++;
    for (int i = 1; i <= n; i++)
        if (a[i] == 0)
        {
            cout << i;
            break;
        }
    return 0;
}
