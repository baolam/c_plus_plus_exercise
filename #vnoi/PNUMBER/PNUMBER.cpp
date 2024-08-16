#include <bits/stdc++.h>
#define maxn 200002

using namespace std;
typedef long long ll;

bool prime[maxn];
ll A, B;

void sieve()
{
    prime[1] = false;
    ll j = 2;
    while (j <= B)
    {
        if (prime[j])
            for (ll i = j * j; i <= B; i += j)
                prime[i] = false;
        j++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(prime, true, sizeof(prime));

    cin >> A >> B;
    sieve();

    for (ll i = A; i <= B; i++)
        if (prime[i])
            cout << i << '\n';
    return 0;
}
