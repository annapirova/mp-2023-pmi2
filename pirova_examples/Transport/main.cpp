#include "transport.h"
#include "landTransport.h"
#include "airTransport.h"
#include <iostream>

const int n = 5;

void main()
{
  Transport man("man", 5.0, 1), tortoise("tortoise", 0.1, 0, RED);
  man.Info();

  LandTransport car("car", 60.0, 4, BLUE, WEELS, 4), car2(car), snowmobile("snowmobile");
  car.Transport::Info();
  car.Info();
  snowmobile.Info();

  AirTransport plane("plane", 800.0, 120, WHITE, CIVILIAN, 4),
    helicopter("hel", 300.0, 4, GREEN, MILITARY, 1);

  Transport** transpTable = new Transport* [n];
  transpTable[0] = &plane;
  transpTable[1] = &helicopter;
  transpTable[2] = &car;
  transpTable[3] = &car2;
  transpTable[4] = &snowmobile;

  std::cout << "****************\n";
  for(int i = 0; i < n; i++)
    transpTable[i]->Info();
  std::cout << "****************\n";

  delete[] transpTable;
}