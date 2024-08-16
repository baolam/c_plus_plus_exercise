#include <bits/stdc++.h>
#define HAS_FILE

#ifdef HAS_FILE
#define FILE_NAME "ABC"
#define READ FILE_NAME ".INP"
#define WRITE FILE_NAME ".OUT"
#endif

using namespace std;
typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifdef HAS_FILE
  freopen(READ, "r", stdin);
  freopen(WRITE, "w", stdout);
#endif
  return 0;
}