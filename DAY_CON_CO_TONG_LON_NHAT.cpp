#include <bits/stdc++.h>
#define maxn 10002

using namespace std;
typedef long long ll;

int n, a[maxn];
int st, en, max_sum, cur_sum, cur_idx;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    max_sum = cur_sum = a[1];
    st = en = cur_idx = 1;
    for (int i = 2; i <= n; i++)
    {
        if (cur_sum < 0)
        {
            cur_sum = a[i];
            cur_idx = i;
        }
        else cur_sum += a[i];
        if (max_sum < cur_sum)
        {
            max_sum = cur_sum;
            st = cur_idx;
            en = i;
        }
    }

    cout << st << ' ' << en << ' ' << max_sum << '\n';
    return 0;
}
