CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic 

.PHONY : all
all:output test

output:main.o vehicle.o car.o motorcycle.o van.o
	$(CXX) $(CXXFLAGS)	-o program  $^

test: test.o vehicle.o car.o motorcycle.o van.o
	$(CXX) $(CXXFLAGS)	-o test  $^

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c  $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c  $^

vehicle.o: vehicle.cpp vehicle.hpp
	$(CXX) $(CXXFLAGS) -c  $^

car.o: car.cpp car.hpp
	$(CXX)  $(CXXFLAGS) -c $^

van.o: van.cpp van.hpp
	$(CXX) $(CXXFLAGS) -c  $^

motorcycle.o: motorcycle.cpp motorcycle.hpp
	$(CXX) $(CXXFLAGS) -c  $^

.PHONY : clean
clean:
	rm *.o program test