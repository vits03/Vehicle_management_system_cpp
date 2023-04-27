#include <string>
#include "motorcycle.hpp"
#include <sstream>
#include <iostream>
using namespace  std;
Motorcycle::Motorcycle(string make,string model,string price,string enginesize,string  passengerseat,string luggagespace,string RegNo,string colour,string IsAvailable,string DateAvailable):Vehicle(make,model,RegNo,colour,price,DateAvailable,IsAvailable){
    EngineSize=enginesize;
    PassengerSeat=passengerseat;
    LuggageSpace=luggagespace;
}

Motorcycle::~Motorcycle(){}
string Motorcycle::GetClassName(){
      return "Motorcycle";
}

int Motorcycle::DisplayAllDetails(){
      cout << "MAKE: " << Make << "\n" << "MODEL: " << Model << "\n"<< "PRICE: " << Price <<"\n" << "ENGINE SIZE: " << EngineSize << "\n" << "REGISTRATION NUMBER: " << RegNo << "\n";
      cout  << "COLOUR: " << Colour << "\n" << " PASSENGER SEAT: " << PassengerSeat << "\n" << "Luggage Space: " << LuggageSpace << "\n" << "IS AVAILABLE: " << IsAvailable << "\n"<< "DATE AVAILABLE:  " <<DateAvailable << endl;
      return 0;
}

std::string Motorcycle::GetEngineSize(){
    return EngineSize;
};

std::string Motorcycle::GetPassengerSeat(){
    return PassengerSeat;
};


std::string Motorcycle::GetLuggageSpace(){
    return LuggageSpace;
}  ;


string  Motorcycle::GetAllDetails(){
    std::stringstream ss;
   
   
   ss  << Make <<":" <<  Model<<":"<< Price<<":"<< EngineSize<<":"<<PassengerSeat<<":"<<LuggageSpace<<":"<<RegNo<<":"<<Colour<<":"<<IsAvailable<<":"<<DateAvailable;
      std::string details = ss.str();
    return details;
}