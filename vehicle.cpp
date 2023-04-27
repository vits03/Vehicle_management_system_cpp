#include <sstream>
#include <string>
#include "vehicle.hpp"
Vehicle::Vehicle(std::string make,std::string model,std::string regno,std::string colour,std::string price,std::string dateAvailable,std::string isAvailable){
  Make = make;
  Model = model;
  RegNo = regno;
  Colour = colour;
  Price = price;
  DateAvailable = dateAvailable;
  IsAvailable =isAvailable;
}


Vehicle::~Vehicle(){}

std::string   Vehicle::GetDetails(){
   std::stringstream ss;
     ss  << Make <<":" <<  Model<<":"<<RegNo<<":"<<Price<<":"<<Colour<<":"<<DateAvailable<<":"<<IsAvailable;
     std::string details = ss.str();
   return details;

}



std::string Vehicle::GetRegNo(){
   return RegNo;
}

std::string Vehicle::GetModel(){
   return Model;
}

std::string Vehicle::GetMake(){
  return Make; 
}

std::string Vehicle::GetColour(){
   return Colour;
}
    
std::string Vehicle::GetPrice(){
    return Price;
}

 std::string Vehicle::GetDateAvailable(){
     return DateAvailable;
}

std::string Vehicle::GetIsAvailable(){
     return IsAvailable;
}
