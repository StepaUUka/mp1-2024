#ifndef _TRANSPORT_H_
#define _TRANSPORT_H_

#include <string>

typedef enum {RED, GREEN, BLUE, WHITE, BLACK} ColorType;

class Transport
{
private:
  double velocity;
protected:
  ColorType color;
public:
  int nPassengers;
  std::string name;
  
  Transport(std::string name_, double v = 0.0, int nP = 0, ColorType col = BLACK);
  Transport(const Transport& tr);
  virtual ~Transport(); // �������������
  virtual void Info();
  virtual void Go() = 0;
};

#endif