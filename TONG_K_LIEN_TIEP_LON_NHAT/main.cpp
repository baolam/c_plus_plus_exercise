#include <bits/stdc++.h>
#define maxn 10002

using namespace std;
typedef long long ll;

int n, k, a;
int s[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    s[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        s[i] = s[i - 1] + a;
    }
    int ans = INT_MIN, be, en;
    for (int i = 1; i <= n - k + 1; i++)
    {
        if (ans < s[i +k - 1] - s[i - 1])
        {
            ans = s[i + k - 1] - s[i - 1];
            be = i, en = i + k - 1;
        }
    }
    cout << be << ' ' << en << ' ' << ans;
    return 0;
}
