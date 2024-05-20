#ifndef _LAND_TRANSPORT_H_
#define _LAND_TRANSPORT_H_

#include "transport.h"

typedef enum {WEELS, SKIES, TRACK} ToolType;

class LandTransport: public Transport
{
protected:
  ToolType tool;
  int nTools;
public:
  LandTransport(std::string name, ToolType t = WEELS, int nT = 4);
  LandTransport(std::string name, double v, int nP, ColorType col, ToolType t, int nT);
  LandTransport(const LandTransport& lt);
  ~LandTransport();
  void Info();
  void Go();
};






#endif