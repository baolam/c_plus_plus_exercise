#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;

int bsearch(int l, int r, int key)
{
    int index = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (s[mid] <= key)
            r = mid - 1;
        else l = mid + 1;
        /// Luôn đảm bảo kiếm đc phần tử đầu tiên
        if (index == -1 || s[index] >= s[mid])
            index = mid;
    }
    return index;
}

void rev(int l, int r)
{
    while (l < r)
    {
        swap(s[l], s[r]);
        l++; r--;
    }
}

bool nextpermutation()
{
    int len = s.length(), i = len - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        i--;
    if (i < 0) return false;
    int index = bsearch(i + 1, len - 1, s[i]);
    swap(s[i], s[index]);
    rev(i + 1, len - 1);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    nextpermutation();
    cout << s;
    return 0;
}
