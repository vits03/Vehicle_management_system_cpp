#include <iostream>

#include <iomanip>

#include <string>

#include <fstream>

#include <vector>

#include <sstream>

#include <typeinfo>

#include <algorithm>

#include <regex>

#include "car.hpp"

#include "van.hpp"

#include "motorcycle.hpp"

using namespace std;


//vector stores object of type vehicle
std::vector < Vehicle * > vehicles;
std::vector < string > arr;
std::string FileName;

bool duplicate_regno(string regno) {
  //iterate through vector and compare reg no
  for (long unsigned int j = 0; j < vehicles.size(); j++) {

    if (vehicles[j] -> GetRegNo().compare(regno) == 0)
      return true;

  }
  return false;
}

void extract_Car(string details) {
  string extracted[10];
  string data;
  int seats;
  int doors;
  int position;

  string extract_data = details;
  //loop extracts each data element seperated by a ":" and stores it in an array.
  for (int i = 0; i < 10; i++) {
    position = extract_data.find(":");
    data = extract_data.substr(0, position);
    extracted[i] = data;
    extract_data = extract_data.substr(position + 1);

  }
  //converts extracted data to integer type
  seats = std::stoi(extracted[4].substr(0, extracted[4].find(" ")));
  doors = std::stoi(extracted[5].substr(0, extracted[5].find(" ")));

  //creates new car objects and appends it to vector
  vehicles.push_back(new Car(extracted[0], extracted[1], extracted[2], extracted[3], seats, doors, extracted[6], extracted[7], extracted[8], extracted[9]));
}

void extract_Bike(string details) {
  string extracted[10];
  string data;
  int position;
  string extract_data = details;
  //loop extracts each data element seperated by a ":" and stores it in an array.
  for (int i = 0; i < 10; i++) {
    position = extract_data.find(":");
    data = extract_data.substr(0, position);
    extracted[i] = data;
    extract_data = extract_data.substr(position + 1);

  }
  //creates new motorcycle objects and appends it to vector
  vehicles.push_back(new Motorcycle(extracted[0], extracted[1], extracted[2], extracted[3], extracted[4], extracted[5], extracted[6], extracted[7], extracted[8], extracted[9]));
}

void extract_Van(string details) {
  string extracted[10];
  string data;
  int seats;
  int position;
  string extract_data = details;
  //loop extracts each data element seperated by a ":" and stores it in an array.
  for (int i = 0; i < 10; i++) {
    position = extract_data.find(":");
    data = extract_data.substr(0, position);
    extracted[i] = data;
    extract_data = extract_data.substr(position + 1);

  }
  //convert extracted data to type integer
  seats = std::stoi(extracted[4].substr(0, extracted[4].find(" ")));

  //creates new car objects and appends it to vector
  vehicles.push_back(new Van(extracted[0], extracted[1], extracted[2], extracted[3], seats, extracted[5], extracted[6], extracted[7], extracted[8], extracted[9]));
}

//function overwrites file with vector object data.
void append_to_file(string vehicles_details) {
  ofstream vehicle_file("vehicles.dat", ios::app);
  vehicle_file << vehicles_details << "\n";
  vehicle_file.close();
  arr.clear();
}

// user data input and validation
int input_vehicle_details(std::string choice) {
  string make;
  string model;
  string regno;
  string colour;
  string price;
  string isavailable;
  string dateavailable;
  bool flag;
  bool isNum = false;
  regex integer_expr("(\\+)?[[:digit:]]+");
  regex string_expr("[a-zA-Z]+");

  do {
    cout << "\n Please enter  the " << choice << "make" << endl;
    cin >> make;
  } while (make.length() > 10);
  arr.push_back(make);

  do {
    cout << "\n Please enter  the " << choice << "model" << endl;
    cin >> model;
  } while (model.length() > 10);
  arr.push_back(model);

  do {

    cout << "\n Please enter  the " << choice << "'s" << "Registration number" << endl;
    cin >> regno;
    flag = duplicate_regno(regno);
    cout << endl << flag;
  } while ((regno.length() != 7) || flag == true);
  arr.push_back(regno);

  do {
    cout << " \n Please enter  the " << choice << "'s  " << "colour" << endl;
    cin >> colour;
  } while (!regex_match(colour, string_expr));
  arr.push_back(colour);

  do {
    cout << " \n Please enter  the " << choice << "'s  " << "price in £" << endl;
    isNum = false;
    cin >> price;
    if (regex_match(price, integer_expr)) {
      isNum = true;
    }

  } while (isNum == false);
  arr.push_back(price);
   //regex used to validate data format 
  regex date("(^(((0[1-9]|1[0-9]|2[0-8])[\\/](0[1-9]|1[012]))|((29|30|31)[\\/](0[13578]|1[02]))|((29|30)[\\/](0[4,6,9]|11)))[\\/](19|[2-9][0-9])\\d\\d$)|(^29[\\/]02[\\/](19|[2-9][0-9])(00|04|08|12|16|20|24|28|32|36|40|44|48|52|56|60|64|68|72|76|80|84|88|92|96)$)");
  bool date_format = false;
  bool available = false;
  do{
    cout << " \n Please enter  the  " << "avaibility (Yes/No)" << endl;
    cin >> isavailable;
    std::transform(isavailable.begin(), isavailable.end(), isavailable.begin(), ::toupper);
    if (isavailable.compare("YES") == 0 || isavailable.compare("NO") == 0) {
      available = true;
      if (isavailable.compare("YES") == 0) {
        dateavailable = "N/A";
        arr.push_back("Yes");
        arr.push_back(dateavailable);
      } 
      
      else {
        arr.push_back("No");
        //DATE VALIDATION
        do {
          cout << " \n Please enter  the  " << "avaibility Date ex 17/09/2012" << endl;
          cin >> dateavailable;

          if (regex_match(dateavailable, date)) {
           
            date_format = true;
            arr.push_back(dateavailable);
          } else {
            cout << "\n NOT valid format!\n";
          }

        }
        while (date_format == false);
      }
    }
  } while (available == false);

  return 0;

}


//takes all details of vehicle Car and appends it to file and vector
void addCar() {
  string engineSize;
  string noseat;
  string nodoor;
  regex integer_expr("(\\+)?[[:digit:]]+");
  regex seat_regx("[1-6]");
  regex decimal_expr("(\\+)?[[:digit:]]+(.*)");
  bool engine_flag = false;
  string vehicle_details;
  stringstream ss;

  input_vehicle_details("car");
  do {
    cout << "Input the Engine size in L ";
    cin >> engineSize;
    if (regex_match(engineSize, decimal_expr)) {
      engine_flag = true;
    }
  } while (engine_flag == false);
  arr.push_back(engineSize);

  do {
    cout << "Enter the number of seats ";
    cin >> noseat;
  } while (regex_match(noseat, seat_regx) == false);
  arr.push_back(noseat);
  do {
    cout << "Enter the number of doors ";
    cin >> nodoor;
  } while (regex_match(nodoor, seat_regx) == false);
  arr.push_back(nodoor);

  for (long unsigned int i = 0; i < arr.size(); i++) {
    cout << "\n" << arr[i] << endl;
  }

  //creates new car object and appends it to vector
  vehicles.push_back(new Car(arr[0], arr[1], "£" + arr[4], arr[7] + "L", stoi(arr[8]), stoi(arr[9]), arr[2], arr[3], arr[5], arr[6]));
  ss << "car:" << arr[0] << ":" << arr[1] << ":" << "£" << arr[4] << ":" << arr[7] << "L" << ":" << arr[8] << " seats" << ":" << arr[9] << " door" << ":" << arr[2] << ":" << arr[3] << ":" << arr[5] << ":" << arr[6];
  vehicle_details = ss.str();
  cout << vehicle_details;
  append_to_file(vehicle_details);

}



//takes all details of vehicle Van and appends it to file and vector
void addVan() {
  stringstream ss;
  string vehicle_details;
  string noseat;
  string luggageSpace;
  regex integer_expr("(\\+)?[[:digit:]]+");
  regex decimal_expr("(\\+)?[[:digit:]]+(.*)");
  string engineSize;
  regex seat_regx("[1-9]+");
  input_vehicle_details("van");
  do {
    cout << "Input the Engine size in L ";
    cin >> engineSize;
  } while (regex_match(engineSize, decimal_expr) == false);
  arr.push_back(engineSize);
  do {
    cout << "Enter the number of seats ";
    cin >> noseat;
  } while (regex_match(noseat, seat_regx) == false);
  arr.push_back(noseat);

  do {
    cout << "Enter the luggage space in cubic meters ";
    cin >> luggageSpace;
  } while (regex_match(luggageSpace, decimal_expr) == false);
  arr.push_back(luggageSpace);
  for (long unsigned int i = 0; i < arr.size(); i++) {
    cout << "\n" << arr[i] << endl;
  }
  vehicles.push_back(new Van(arr[0], arr[1], "£" + arr[4], arr[7] + "L", stoi(arr[8]), arr[9] + " cubic meters luggage space", arr[2], arr[3], arr[5], arr[6]));
  ss << "van:" << arr[0] << ":" << arr[1] << ":" << "£" << arr[4] << ":" << arr[7] << "L" << ":" << arr[8] << " seats" << ":" << arr[9] << " cubic meters luggage space" << ":" << arr[2] << ":" << arr[3] << ":" << arr[5] << ":" << arr[6];
  vehicle_details = ss.str();
  cout << vehicle_details;
  append_to_file(vehicle_details);

}


//takes all details of vehicle Bike and appends it to file and vector
void addBike() {
  string vehicles_details;
  std::stringstream ss;
  string engineSize;
  string passengerseat;
  string luggage;
  bool luggage_flag = false;
  bool passengerseat_flag = false;
  regex integer_expr("(\\+)?[[:digit:]]+");

  input_vehicle_details("bike");
  do {
    cout << "Input the Engine size in cc ";
    cin >> engineSize;
  } while (regex_match(engineSize, integer_expr) == false);
  arr.push_back(engineSize);

  do {
    cout << " \n Does the bike include a passenger seat? (Yes/No)" << endl;
    cin >> passengerseat;
    std::transform(passengerseat.begin(), passengerseat.end(), passengerseat.begin(), ::toupper);
    if (passengerseat.compare("YES") == 0 || passengerseat.compare("NO") == 0) {
      passengerseat_flag = true;
    }
  } while (passengerseat_flag == false);

  if (passengerseat.compare("YES")) {
    arr.push_back("passenger seat");
  } else {
    arr.push_back("no passenger");

  }

  do {
    cout << " \n Does the bike has luggage? (Yes/No)" << endl;
    cin >> luggage;
    std::transform(luggage.begin(), luggage.end(), luggage.begin(), ::toupper);
    if (luggage.compare("YES") == 0 || luggage.compare("NO") == 0) {
      luggage_flag = true;
      if (luggage.compare("YES") == 0) {
        arr.push_back("Has luggage");
      } else {
        arr.push_back("No luggage");
      }
    }
  } while (luggage_flag == false);
  for (long unsigned int i = 0; i < arr.size(); i++) {
    cout << "\n" << arr[i] << endl;
  }
  ss << "bike:" << arr[0] << ":" << arr[1] << ":" << "£" << arr[4] << ":" << arr[7] << "cc" << ":" << arr[8] << ":" << arr[9] << ":" << arr[2] << ":" << arr[3] << ":" << arr[5] << ":" << arr[6] << "\n";
  vehicles.push_back(new Motorcycle(arr[0], arr[1], "£" + arr[4], arr[7] + "cc", arr[8], arr[9], arr[2], arr[3], arr[5], arr[6]));
  vehicles_details = ss.str();
  cout << vehicles_details;
  append_to_file(vehicles_details);
  //write to file
}




//function called when user chooses to add a vehicle
void AddVehicle() {
  int choice = 0;
  string vehicleChoice;
  regex choice_regx("[0-3]");
  cout << "------------------------------------------\n";
  cout << "Please choose your vehicle type" << endl;
  cout << "1. Van" << endl;
  cout << "2. Car" << endl;
  cout << "3. Bike" << endl;
  cout << "------------------------------------------\n";
  cout << "Please enter a number between 1 and 3 to choose an option OR type 0 to return to Main menu: ";
  do {
    cin >> vehicleChoice;
    if (regex_match(vehicleChoice, choice_regx) == false) {
      cout << "Please enter a number between 1 and 3 to choose an option OR type 0 to return to Main menu: ";
    }
  } while (regex_match(vehicleChoice, choice_regx) == false);
  choice = stoi(vehicleChoice);

  switch (choice) {
  case 1:

    addVan();
    break;
  case 2:
   
    addCar();
    break;
  case 3:
    addBike();
    break;

  default:
    break;
  }

}


//updates the text file by overwriting all data in vector in file
void update_file() {
  string className;
  ofstream vehicle_file(FileName);
  ///traverse through vector and check class of each object
  for (long unsigned int i = 0; i < vehicles.size(); i++) {
    className = vehicles[i] -> GetClassName();
    vehicle_file << className << ":" << vehicles[i] -> GetAllDetails() << "\n";

  }
  vehicle_file.close();
}





//take registration number as user input and searches for a match in vector.if found,object is deleted from vector and file.
void RemoveVehicle() {
  bool regFlag = false;
  string exit_flag;
  do {
    string regNo;
    cout << "\n----------------------------------------------\n";
    cout << "Please input the vehicle's Registration number OR  type -1 to return to Main Menu: ";
    cin >> regNo;
    
    exit_flag = regNo;
    std::transform(regNo.begin(), regNo.end(), regNo.begin(), ::toupper);
    if (regNo.length() != 7) {
      cout << "Registration number must  7 character long and contain numbers and Letters.\n ";
    } else {
      for (long unsigned int j = 0; j < vehicles.size(); j++) {
        if (vehicles[j] -> GetRegNo().compare(regNo) == 0) {
          vehicles.erase(vehicles.begin() + j);
          update_file();
          cout << "Sucessfully deleted from file\n";
          regFlag = true;
        }
      }
    }
  }
  while (regFlag == false && exit_flag != "-1");
}

void DisplayAllVehicles() {
  for (long unsigned int j = 0; j < vehicles.size(); j++) {
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "|" << std::left << std::setw(15) << vehicles[j] -> GetMake() << std::setw(16) << "|   " + vehicles[j] -> GetModel() << std::right << std::setw(15) << std::left << std::setw(15) << "|   " + vehicles[j] -> GetRegNo() << std::left << std::setw(10) << "| " + vehicles[j] -> GetPrice() << std::left << std::setw(10) << "|  " + vehicles[j] -> GetColour() << std::left << std::setw(15) << "|  " + vehicles[j] -> GetDateAvailable() << std::left << std::setw(8) << "|  " + vehicles[j] -> GetIsAvailable() << std::left << setw(3) << "|" << endl;
  }
}

// takes registration number as input and search through vector if a match is found.
void FindVehicle() {
  bool regFlag = false;
  string exit_flag;
  do {
    string regNo;

     cout << "\n--------------------------------------------------------------------------------\n";
    cout << "Please input the vehicle's Registration number OR  type -1 to return to Main Menu: ";
    cin >> regNo;
    exit_flag = regNo;
    if (regNo.length() != 7) {
      cout << "\n Registration number must  7 character long and contain numbers and Letters.\n ";
    } else {
      for (long unsigned int j = 0; j < vehicles.size(); j++) {
        if (vehicles[j] -> GetRegNo().compare(regNo) == 0) {
          cout <<"-------------------------------------------------------------\n";
          vehicles[j] -> DisplayAllDetails();
          regFlag = true;
        }
      }
    }
  }
  while (regFlag == false && exit_flag != "-1");
}

//checks if file exists
bool is_file_exist(const char * fileName) {
  std::ifstream infile(fileName);
  return infile.good();
}








int main() {

  int pos;
  regex choice_regx("[0-4]|(-1)");
  string choice;
  string myText;
  char filename[100];



  //take file name as input until a valid filename is entered
  do {
    cout << "Input the file name:";
    cin >> filename;
    if (is_file_exist(filename) == false) {
      cout << "File not Found! Please enter a valid file name and format\n";
    }

  }
  while (is_file_exist(filename) == false);
  FileName = filename;


//loading all data from file 
  ifstream infile;
  infile.open(filename);
  while (getline(infile, myText)) {
    pos = myText.find(":");
    string sub = myText.substr(0, pos);

    if (sub.compare("Motorcycle") == 0)

      extract_Bike(myText.substr(pos + 1));
    else if (sub.compare("Van") == 0)

      extract_Van(myText.substr(pos + 1));
    else if (sub.compare("Car") == 0)

    {
      extract_Car(myText.substr(pos + 1));
    }

  }

  cout << vehicles.size() << endl;
  infile.close();
  int i = 0;
  



   //Main menu 
  
  do {
     cout << "-----------------------------------------------------------------------------------------------------------------------\n";
     cout <<  "##     ## ######## ##     ## ####  ######  ##       ########    ########  ######## ##    ## ########    ###    ##\n";      
     cout << "##     ## ##       ##     ##  ##  ##    ## ##       ##          ##     ## ##       ###   ##    ##      ## ##   ##\n";      
     cout << "##     ## ##       ##     ##  ##  ##       ##       ##          ##     ## ##       ####  ##    ##     ##   ##  ##\n";      
     cout << "##     ## ######   #########  ##  ##       ##       ######      ########  ######   ## ## ##    ##    ##     ## ##\n";      
     cout << " ##   ##  ##       ##     ##  ##  ##       ##       ##          ##   ##   ##       ##  ####    ##    ######### ##\n";  
     cout << "  ## ##   ##       ##     ##  ##  ##    ## ##       ##          ##    ##  ##       ##   ###    ##    ##     ## ##\n";     
      cout << "   ###    ######## ##     ## ####  ######  ######## ########    ##     ## ######## ##    ##    ##    ##     ## ########\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    cout << "---------------------------------------------Please choose an option---------------------------------------------------\n";
    cout << "1.ADD A VEHICLE\n";
    cout << "2.REMOVE A VEHICLE\n";
    cout << "3.DISPLAY ALL VEHICLES\n";
    cout << "4.FIND VEHICLE\n";
       cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    do {
      cout << "Please enter a number between 1 and 4 to choose an option OR type -1 to quit:  ";
      cin >> choice;
    } while (regex_match(choice, choice_regx) == false);

    i = stoi(choice);
    cout << i;
    switch (i) {
    case 1:

      AddVehicle();
      break;
    case 2:
      RemoveVehicle();
      break;
    case 3:

      DisplayAllVehicles();
      break;
    case 4:

      FindVehicle();
      break;
    default:
      break;
    }
  } while (i != -1);

  return 0;
}