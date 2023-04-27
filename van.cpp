#include <string.h>
#include <sstream>
#include <iostream>
#include "van.hpp"
using namespace std;

Van::Van(std::string make,std::string model,std::string price,std::string enginesize,int noseat,std::string luggagespace,std::string RegNo,std::string colour,std::string IsAvailable,std::string DateAvailable ):Vehicle(make,model,RegNo,colour,price,DateAvailable,IsAvailable){
EngineSize=enginesize;
NoSeat=noseat;
LuggageSpace=luggagespace;
}

Van::~Van(){}

string  Van::GetAllDetails(){
     std::stringstream ss;
      
       ss  << Make <<":" <<  Model<<":"<< Price<<":"<< EngineSize<<":"<<to_string(NoSeat)+" seats"<<":"<<LuggageSpace<<":"<<RegNo<<":"<<Colour<<":"<<IsAvailable<<":"<<DateAvailable;
     string details= ss.str();
     return details;
}
std::string Van::GetEngineSize(){
    return EngineSize;
};

std::string Van::GetNoSeat(){
    return to_string(NoSeat);
};


std::string Van::GetLuggageSpace(){
    return LuggageSpace;
}  ;

int Van::DisplayAllDetails(){
cout << "MAKE: " << Make << "\n" << "MODEL: " << Model << "\n"<< "PRICE: " << Price <<"\n" << "ENGINE SIZE: " << EngineSize << "\n" << "REGISTRATION NUMBER: " << RegNo << "\n";
      cout  << "COLOUR: " << Colour << "\n" << "SEATS: " << NoSeat << "\n" << "Luggage Space: " << LuggageSpace << "\n" << "IS AVAILABLE: " << IsAvailable << "\n"<< "DATE AVAILABLE:  " <<DateAvailable << endl;
      return 0;
}

string Van::GetClassName(){
      return "Van";
}