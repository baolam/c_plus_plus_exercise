/// Ứng dụng của kĩ thuật duyệt vét cạn

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, ans = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    int i = 1, j = 1;
    /// Lặp tìm j
    while (j * j * j + 1 < n)
        j++;
    while (i <= j)
    {
        int k = i * i * i + j * j * j;
        if (k == n)
        {
            ans++;
            i++; j--;
        /// Điểm cần lưu ý
        } else if (k < n)
            i++;
        else j--;
    }
    cout << ans;
    return 0;
}
