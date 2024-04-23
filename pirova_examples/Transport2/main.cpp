#include "transport.h"
#include "landTransport.h"
#include "airTransport.h"
#include <iostream>


const int n = 5;

void main()
{
  // нельзя, т.к. Transport стал абстрактным классом  
  //Transport man(5.0, 1), tortoise(0.1, 0, RED);
  //man.Info();
  //tortoise.Info();

  LandTransport car("car", 60.0, 4, BLUE, WEELS, 4), car2(car), snowmobile("snowmobile");
//  car.Info();
//  car2.Info();
//  snowmobile.Info();

  //AirTransport plane(800.0, 120, WHITE, CIVILIAN, 4),
  //  helicopter(300.0, 4, GREEN, MILITARY, 1);

  Plane  plane(CIVILIAN, 4), plane2(plane);

  Transport** transpTable = new Transport* [n];
  //transpTable[0] = &plane;
  //transpTable[1] = &helicopter;
  transpTable[0] = &plane;
  transpTable[1] = &plane2;
  transpTable[2] = &car;
  transpTable[3] = &car2;
  transpTable[4] = &snowmobile;

  std::cout << "****************\n";
  for(int i = 0; i < n; i++)
    transpTable[i]->Go();
  std::cout << "****************\n";

  delete[] transpTable;

  Transport& r = plane; 
  r.Go(); // Plane->Go
  AirTransport& a = dynamic_cast<AirTransport&>(r); // теперь можно
  AirTransport* b = dynamic_cast<AirTransport*>(&car);
  if (b)
	  std::cout << "b is AirTransport\n";
  else
	  std::cout << "b is not AirTransport\n";
  std::cout << "****************\n";
}