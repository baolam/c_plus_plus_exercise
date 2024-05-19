#include <bits/stdc++.h>
#define maxn 50

using namespace std;
typedef long long ll;

ll n;
vector<ll> permute;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        permute.push_back(i);
    do {
        // Xử lí subset
    } while(next_permutation(permute.begin(), permute.end()));
    return 0;
}
