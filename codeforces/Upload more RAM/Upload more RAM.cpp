#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> k;
        cout << n * k - k + 1 << '\n';
    }
    return 0;
}
