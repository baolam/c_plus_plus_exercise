/// Dãy con có tổng chia hết cho n
/// Áp dụng nguyên lí Dirichlet
/// Phát biểu đề bài:
/// Cho số nguyên dương n và mảng A có n phần tử. Có thể tạo ra một dãy con liên tiếp mà tổng
/// các phần tử chia hết cho n hay không?

/// Xây dựng mảng cộng dồn si = a1 + a2 + ... + ai
/// Do có n phần tử mà số dư chỉ có từ 0 đến n - 1 nên theo nguyên lí sẽ tồn tại 2 vị trí giống nhau
/// Giả sử hai vị trí đó là i, j.
/// Yêu cầu là cần tìm ra vị trí đó.

#include <bits/stdc++.h>
#define maxn 10002

using namespace std;
typedef long long ll;

int n, a[maxn], s[maxn];
// Mảng dùng để lưu trữ
int b[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(b, 0, sizeof(b));
    s[0] = 0;
    cin >> n;
    int st = 0, en = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        int r = s[i] % n;
        if (r == 0)
        {
            st = 1, en = i;
            break;
        }
        else if (b[r] != 0) {
            st = b[r] + 1, en = i;
            break;
        }
        b[r] = i;
    }
    cout << st << ' ' << en;
    return 0;
}
