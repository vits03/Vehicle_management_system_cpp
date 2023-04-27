#define CATCH_CONFIG_MAIN
#include "car.hpp"
#include "van.hpp"
#include "motorcycle.hpp"
#include <iostream>
#include <cmath>
#include <string.h>
#include "catch.hpp"

TEST_CASE("Van Getter functions","[object data]")
{
     
     Van Van1 = Van("Ford","Transit","£40","2L",3,"15.1 cubic meters luggage space","TV71YNP","black","Yes","N/A");
   REQUIRE( Van1.GetPrice() == "£40");
    REQUIRE( Van1.GetClassName() == "Van");
      REQUIRE( Van1.GetRegNo() == "TV71YNP");
   REQUIRE( Van1.GetMake() == "Ford");
     REQUIRE( Van1.GetModel() == "Transit");
     REQUIRE( Van1.GetEngineSize() == "2L");
       REQUIRE( Van1.GetLuggageSpace() == "15.1 cubic meters luggage space");
    REQUIRE( Van1.GetNoSeat() == "3");
    REQUIRE( Van1.GetColour() == "black");
    REQUIRE( Van1.GetIsAvailable() == "Yes");
    REQUIRE( Van1.GetDateAvailable() == "N/A");
    REQUIRE( Van1.GetAllDetails() == "Ford:Transit:£40:2L:3 seats:15.1 cubic meters luggage space:TV71YNP:black:Yes:N/A");
   
}

TEST_CASE("Car getter functions ","[object ata]")
{
     
    Car CarObj = Car("Nissan","Micra","£50","1.2L",5,5,"NR69UZE","blue","Yes","N/A");
     REQUIRE( CarObj.GetPrice() == "£50");
     REQUIRE( CarObj.GetClassName() == "Car");
    REQUIRE(CarObj.GetRegNo() == "NR69UZE");
    REQUIRE( CarObj.GetMake() == "Nissan");
      REQUIRE( CarObj.GetNoDoor() == "5");
     REQUIRE( CarObj.GetModel() == "Micra");
       REQUIRE( CarObj.GetEngineSize() == "1.2L");
    REQUIRE( CarObj.GetColour() == "blue");
    REQUIRE( CarObj.GetIsAvailable() == "Yes");
    REQUIRE(CarObj.GetDateAvailable() == "N/A");
     REQUIRE( CarObj.GetAllDetails() == "Nissan:Micra:£50:1.2L:5 seats:5 door:NR69UZE:blue:Yes:N/A");
}


TEST_CASE("Moto getter Functions","[obsject ata]")
{
     
    Motorcycle motoObj = Motorcycle("Honda","Goldwing","£85","1833cc","Passenger seat","Has luggage","CP71OVG","green","No","17/1/2023");
    
 REQUIRE( motoObj.GetPrice() == "£85");
     REQUIRE( motoObj.GetClassName() == "Motorcycle");
    REQUIRE(motoObj.GetRegNo() == "CP71OVG");
      REQUIRE(motoObj.GetLuggageSpace() == "Has luggage");
      REQUIRE(motoObj.GetPassengerSeat() == "Passenger seat");
    REQUIRE( motoObj.GetMake() == "Honda");
     REQUIRE( motoObj.GetModel() == "Goldwing");
       REQUIRE( motoObj.GetEngineSize() == "1833cc");
    REQUIRE( motoObj.GetColour() == "green");
    REQUIRE( motoObj.GetIsAvailable() == "No");
    REQUIRE(motoObj.GetDateAvailable() == "17/1/2023");
    REQUIRE( motoObj.GetAllDetails() == "Honda:Goldwing:£85:1833cc:Passenger seat:Has luggage:CP71OVG:green:No:17/1/2023");
    
}