#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll h, m, a, b;

int main()
{
    cin >> h >> m >> a >> b;
    // Đổi sang muối giờ gốc
    h -= a;
    // Ví dụ
    if (h < 0)
        h = 24 + h;
    if (h > 24)
        h -= 24;
    h += b;
    if (h < 0)
        h = 24 + h;
    if (h > 24)
        h -= 24;
    if (h == 24)
        h = 0;
    cout << h << " " << m;
    return 0;
}
