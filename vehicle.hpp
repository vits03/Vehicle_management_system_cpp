#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include <string>



class Vehicle
 {
 protected:
  std::string Make;
  std::string Model;
  std::string RegNo;
  std::string Colour;
  std::string  Price;
  std::string DateAvailable;
  std::string IsAvailable;
  
 public:
  Vehicle(std::string make,std::string model,std::string regno,std::string colour,std::string price,std::string dateAvailable,std::string isAvailable);
  virtual ~Vehicle();
  virtual std::string  GetAllDetails()=0;
  virtual std::string  GetClassName()=0;
  virtual int DisplayAllDetails()=0;
  std::string   GetDetails();
  std::string GetRegNo();
  std::string GetModel();
  std::string GetMake();
   std::string GetColour();
    std::string GetPrice();
     std::string GetDateAvailable();
     std::string GetIsAvailable();
};
#endif