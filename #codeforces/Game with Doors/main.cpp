// Miêu tả vấn đề
// Có 100 phòng và 99 cái cửa giữa chúng
// Cửa i kết nối phòng i với phòng i + 1
// Có Alice ở trong phòng đoạn [l, r]
// Có Bob ở trong đoạn [L, R]
// Tìm số cách đóng cửa ít nhất sao cho Alice không thể gặp Bob
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int arr[5];

void solve()
{
  /// Trường hợp không giao nhau
  if (arr[3] > arr[2] || arr[4] < arr[1])
  {
    cout << 1 << '\n';
    return;
  }
  sort(arr + 1, arr + 5);
  int tmp = 0;
  for (int i = 2; i <= 4; i++)
  {
    if (arr[i] == arr[i - 1])
      continue;
    int code = arr[i] - arr[i - 1];
    if ((i == 2 || i == 4) && code > 1)
      code = 1;
    tmp += code;
  }
  cout << tmp << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // freopen("Game_with_Doors.INP", "r", stdin);
  cin >> t;
  while (t--)
  {
    for (int i = 1; i <= 4; i++)
      cin >> arr[i];
    solve();
  }
  return 0;
}