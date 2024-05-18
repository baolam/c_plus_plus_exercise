#include <bits/stdc++.h>
#define maxn 1000002

using namespace std;
typedef long long ll;

ll n, p;
ll a[maxn], s[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> p;
    s[0] = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], s[i] = s[i - 1] + a[i];
        for (int j = 1; j <= i; j++)
            if (s[i] - s[j - 1] == p)
                cnt++;
    }
    cout << cnt;
    return 0;
}
