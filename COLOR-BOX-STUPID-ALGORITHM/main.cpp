#include <bits/stdc++.h>
#define N 1000002

using namespace std;
typedef long long ll;

ll n;
ll pos[N];
bool visited[N], tempoary[N];

bool checked(ll l, ll r);
void reset();

int main()
{
    ll res = INT_MAX;
    cin >> n;
    reset();
    for (ll i = 1; i <= n; i++)
        cin >> pos[i];
    for (ll l = 1; l <= n - 1; l++)
    {
        for (ll r = l; r <= n; r++)
        {
            /// Đoạn L, R hàm ý là vị trí đoạn muốn bỏ
            /// Cần kiểm tra liệu đoạn này bỏ có hợp lý hay không
            /// Là hợp lý nếu bỏ đi đoạn này làm cho vị trí phần tử còn lại là thỏa mãn
            /// Nghĩa là vị trí phần tử còn lại không bị lặp
            /// Kiểm tra từ vị trí 1 --> l có lặp hay không
            /// Kiểm tra từ vị trí r + 1 --> n có lặp hay không
            if (checked(l, r))
            {
                res = min(res, r - l + 1);
            }
            reset();
        }
    }
    cout << res;
    return 0;
}

bool checked(ll l, ll r)
{
    for (ll i = 1; i < l; i++)
    {
        if (tempoary[pos[i]])
            return false;
        tempoary[pos[i]] = true;
    }
    for (ll i = r + 1; i <= n; i++)
    {
        if (tempoary[pos[i]])
            return false;
        tempoary[pos[i]] = true;
    }
    return true;
}

void reset()
{
    for (ll i = 1; i <= n; i++)
        tempoary[i] = false;
}
