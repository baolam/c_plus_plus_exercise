#include <iostream>
#include <math.h>
#include "menu.h"

using namespace std;

int menu_code;

void handle_menu()
{
  switch (menu_code)
  {
  case 0:
    cout << "Dao nguoc so: " << DaoNguocSo(12345) << '\n';
    break;
    // case 1:
    //   xuLi2();
    //   break;
    // case 2:
    //   xuLi3();
    //   break;
  }
}

int main()
{
  cin >> menu_code;
  handle_menu();
  return 0;
}