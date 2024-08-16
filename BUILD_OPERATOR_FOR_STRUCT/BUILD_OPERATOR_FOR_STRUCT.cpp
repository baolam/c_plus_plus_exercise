#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Object
{
    int _min = INT_MAX;
    int _equal = 1;
    bool operator<(Object other)
    {
        return _min < other._min;
    }

    bool operator>(Object other)
    {
        return _min > other._min;
    }

    bool operator==(Object other)
    {
        return _min == other._min;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Object s1, s2, s3;
    s1._min = 5;
    s2._min = 9;
    return 0;
}
