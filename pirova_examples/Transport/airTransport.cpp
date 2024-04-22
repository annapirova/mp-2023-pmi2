#include "airTransport.h"
#include <iostream>

const char* AirTypeNames[] = {"military", "civilian"};

AirTransport::AirTransport(std::string name_, AirType t, int nE) : Transport(name_), type(t), nEngines(nE)
{
  std::cout << "AirTransport Default Constructor\n";
}

AirTransport::AirTransport(std::string name_, double v, int nP, ColorType col, AirType t, int nE):
  Transport(name_, v, nP, col), type(t), nEngines(nE)
{
  std::cout<<"AirTransport Init Constructor\n";
}

AirTransport::AirTransport(const AirTransport& at) : Transport(at)
{
  type = at.type;
  nEngines = at.nEngines;

  std::cout<<"LandTransport Copy Constructor\n";
}

AirTransport::~AirTransport()
{
  std::cout << "AirTransport Destructor\n";
}

void AirTransport::Info()
{
  std::cout << "AirTransport Info: type " << AirTypeNames[(int)type] << " nEngines " << nEngines << "\n";
  Transport::Info();
}

void AirTransport::Go()
{
  std::cout << "AirTransport Go\n";
}