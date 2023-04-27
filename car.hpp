#ifndef  CAR_HPP
#define CAR_HPP
#include "vehicle.hpp"
#include <string>

class Car :public Vehicle {
 private:
  std::string EngineSize;
 int NoSeat;
 int NoDoor;

 public:
 Car(std::string make,std::string model,std::string price,std::string enginesize,int noseat,int nodoor,std::string RegNo,std::string colour,std::string IsAvailable, std::string DateAvailable);
  ~Car();
  std::string  GetAllDetails();
  std::string GetClassName();
  int DisplayAllDetails();
  std::string GetEngineSize();

  std::string GetNoseat();

  std::string GetNoDoor();


};
#endif