AssignmentTwoFinal: driver.o
	g++ -o AssignmentTwoFinal driver.o 
driver.o: driver.cpp 
	g++ -c driver.cpp
clean:
	rm *.o AssignmentTwoFinal