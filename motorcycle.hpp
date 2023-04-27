#ifndef  MOTORCYCLE_HPP
#define MOTORYCLE_HPP
#include "vehicle.hpp"

class Motorcycle :public Vehicle {
 private:
  std::string EngineSize;
  std::string PassengerSeat;
  std::string  LuggageSpace;

 public:
 Motorcycle(std::string make,std::string model,std::string price,std::string enginesize,std::string  passengerseat,std::string luggagespace,std::string RegNo,std::string colour,std::string IsAvailable,std::string DateAvailable);
  ~Motorcycle();
  std::string  GetAllDetails();
  std::string GetClassName();
   int DisplayAllDetails();
   std::string GetEngineSize();
std::string GetPassengerSeat();
std::string GetLuggageSpace();
};

#endif