#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a, b, c;
ll res = 0;

int main()
{
    cin >> a >> b >> c;

    /// Mặc định số kết quả sẽ là c
    /// do c là số 3 lớn nhất
    res = c;

    /// Tiến hành phân tách a + b con số còn lại
    /// Nhận định
    /// Hai con số 2 không kết hợp được với nhau
    /// Do sẽ lớn hơn 3 -> Chọn kết hợp một con số 2 với 1 con số 1
    /// 4 con số 3 không tạo thành kết quả thỏa

    /// Tiến hành chọn số b

    /// Tiến hành chọn số 2
    res += min(a, b);
    a -= b;

    if (a > 0)
        res += a / 3;
    cout << res;
    return 0;
}
