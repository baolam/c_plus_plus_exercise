#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> m;
        if (n >= m)
        {
            int delta = n - m;
            if (delta % 2 == 0)
                cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
        else cout << "No" << '\n';
    }
    return 0;
}
