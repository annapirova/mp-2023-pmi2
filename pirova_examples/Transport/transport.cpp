#include "transport.h"
#include <iostream>

const char* ColorNames[] = {"red", "green", "blue", "white", "black"};

Transport::Transport(std::string name_, double v, int nP, ColorType col):
	velocity(v), nPassengers(nP), color (col), name(name_)
{
  std::cout<<name << " Transport Default constructor\n";
}

Transport::Transport(const Transport& tr)
{
  velocity = tr.velocity;
  nPassengers = tr.nPassengers;
  color = tr.color;
  name = tr.name;
  std::cout<<" Transport Copy constructor\n";
}

Transport::~Transport()
{
  std::cout << name <<" Transport Destructor\n";
}

void Transport::Info()
{
  std::cout << name << " Transport info: " << "v " << velocity << " number of passangers " 
    << nPassengers << " color " << ColorNames[color] << "\n";
}

void Transport::Go()
{
  std::cout << name << " Transport Go\n";
}