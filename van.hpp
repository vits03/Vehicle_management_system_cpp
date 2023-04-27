#ifndef  vAN_H
#define VAN_H
#include <string.h>
#include "vehicle.hpp"
class Van :public Vehicle {
 private:
  std::string EngineSize;
 int NoSeat;
 std::string LuggageSpace;

 public:
  Van(std::string make,std::string model,std::string price,std::string enginesize,int noseat,std::string luggagespace,std::string RegNo,std::string colour,std::string IsAvailable,std::string DateAvailable );
  std::string  GetAllDetails();
  std::string GetClassName();
  int DisplayAllDetails();
  std::string GetEngineSize();
  std::string GetNoSeat();
  std::string GetLuggageSpace();
  ~Van() ;
};
#endif