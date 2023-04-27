#include <string>
#include <sstream>
#include <iostream>
#include "car.hpp"
using namespace std;

Car::Car(std::string make,std::string model,std::string price,std::string enginesize,int noseat,int nodoor,std::string RegNo,std::string colour,std::string IsAvailable, std::string DateAvailable):Vehicle(make,model,RegNo,colour,price,DateAvailable,IsAvailable){
EngineSize=enginesize;
NoSeat=noseat;
NoDoor=nodoor;
}

Car::~Car(){}

string Car::GetAllDetails(){
      std::stringstream ss;
     ss  << Make <<":" <<  Model<<":"<< Price<<":"<< EngineSize<<":"<<to_string(NoSeat)+" seats"<<":"<<to_string(NoDoor)+" door"<<":"<<RegNo<<":"<<Colour<<":"<<IsAvailable<<":"<<DateAvailable;
     string details = ss.str();
     return details;

}
 std::string Car::GetEngineSize(){
      return EngineSize;
};

  std::string Car::GetNoseat(){
      return to_string(NoSeat);
  };

  std::string Car::GetNoDoor(){
      return to_string(NoDoor);
  };

string Car::GetClassName(){
      return "Car";
}


int Car::DisplayAllDetails(){
      cout << "MAKE: " << Make << "\n" << "MODEL: " << Model << "\n"<< "PRICE: " << Price <<"\n" << "ENGINE SIZE: " << EngineSize << "\n" << "REGISTRATION NUMBER: " << RegNo << "\n";
      cout  << "COLOUR: " << Colour << "\n" << "SEATS: " << NoSeat << "\n" << "DOORS: " << NoDoor << "\n" << "IS AVAILABLE: " << IsAvailable << "\n"<< "DATE AVAILABLE:  " <<DateAvailable << endl;
      return 0;
}