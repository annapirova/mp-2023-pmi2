#ifndef __AIR_TRANSPORT__
#define __AIR_TRANSPORT__

#include "transport.h"

typedef enum {MILITARY, CIVILIAN} AirType;

class AirTransport: public Transport
{
protected:
  AirType type;
  int nEngines;
public:
  AirTransport(std::string name_ = "", AirType t = CIVILIAN, int nE = 2);
  AirTransport(std::string name_, double v, int nP, ColorType col, AirType t, int nE);
  AirTransport(const AirTransport& at);
  ~AirTransport();
  void Info();
  void Go();
};

#endif