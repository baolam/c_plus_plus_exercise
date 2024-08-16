#include <bits/stdc++.h>
#define N 1000002

using namespace std;
typedef long long ll;

ll n;
ll types[N], pos[N];
ll visited[N];

/// Mảng POS lưu trữ vị trí ô đã gặp

int main()
{
    /// Yêu cầu của cậu bé
    /// Bộ màu gồm các thanh màu đôi một khác nhau
    /// Không thích bộ màu giống nhau

    /// Nhận định 1
    /// Nếu vị trí cây màu thứ i trùng với i cây màu trước đó thì tiến hành nhớ vị trí
    /// Số cây màu chọn luôn có tính kế thừa hay
    /// Nếu nếu cây màu ở vị trí x không thỏa cách một khoảng thỏa rùi tới vị trí x mới không thỏa thì đoạn l, r nhớ bằng
    /// vị trí x bắt đầu tới vị trí x đã xét
    /// Nhận định này không chặt

    /// Xét số cây màu từ vị trí đầu tiên tới vị trí i hiện tại thỏa điều kiện đề bài
    /// Nếu cây màu tại vị trí i + 1 trùng với i 1 cây màu nào đó trong i cây màu trước đó thì
    /// Hai trường hợp của bài toán
    /// Bỏ đoạn phần tử trước đó
    /// Bỏ đoạn phần tử hiện tại

    cin >> n;
    for (ll i = 1; i <= n; i++) {
        visited[i] = 0;
        pos[i] = 0;
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> types[i];
        if (visited[types[i]] != 0)
        {
            pos[i] = visited[types[i]];
        }
        visited[types[i]] = i;
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << pos[i] << " ";
    }
    return 0;
}
