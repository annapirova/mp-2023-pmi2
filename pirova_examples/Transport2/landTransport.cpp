#include "landTransport.h"
#include <iostream>

const char* ToolNames[] = { "weels", "skies", "track" };

LandTransport::LandTransport(std::string name_, ToolType t, int nT) : Transport(name_), tool(t), nTools(nT)
{
	std::cout << name << " LandTransport Default Constructor\n";
}

LandTransport::LandTransport(std::string name_, double v, int nP, ColorType col, ToolType t, int nT) :
	Transport(name_, v, nP, col), tool(t), nTools(nT)
{
	std::cout << name << " LandTransport Init Constructor\n";
}

LandTransport::LandTransport(const LandTransport& lt) :Transport(lt), tool(lt.tool), nTools(lt.nTools)
{
	std::cout << name << " LandTransport Copy Constructor\n";
}

LandTransport::~LandTransport()
{
	std::cout << name << " LandTransport Destructor\n";
}

void LandTransport::Info()
{
	std::cout << name << " LandTransport Info: " << ToolNames[(int)tool] << " nTools: " << nTools << "\n";
	Transport::Info();
}

void LandTransport::Go()
{
	std::cout << name << " LandTransport Go\n";
}

