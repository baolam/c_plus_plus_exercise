#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll Q;
ll A, B;

bool backtracking(ll x);
ll for_double(ll x);
ll for_add_1(ll x);

int main()
{
    ///cin >> A >> B;
    /// Nhận định về bài toán:
    // Gấp đôi giá trị A
    // Thêm số 1 vào phía cuối số A

    // Nếu số B được cho là một số lẻ
    // Ý ưởng dùng quay lui
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> A >> B;
        if (backtracking(A))
            cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}

bool backtracking(ll x)
{
    /// Hai kết quả tượng trưng cho hai trạng thái
    /// Một là gấp đôi
    /// Hai là thêm số 1
    /// Cải thiện thuật toán backtracking
    /// Nhận định 1
    /// Những con số có tính kế thừa
    /// Hay mỗi lần duyệt cần chắc chắn những con số cuối giống những con số cuối tương ứng
    for (int i = 0; i <= 1; i++)
    {
        ll z = x;
        if (i == 0)
            z = for_double(z);
        if (i == 1)
            z = for_add_1(z);
        if (z == B)
            return true;
        if (z > B)
            return false;
        if (backtracking(z))
            return true;
    }
}

ll for_double(ll x)
{
    return x * 2;
}

ll for_add_1(ll x)
{
    return x * 10 + 1;
}
