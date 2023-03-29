//
//Author: Fenn Edmonds
//Purpose: To implement the ADD function using c++ code
//Date: 2/22/2023
//

//These are the libraries needed to implement this code
#include <iostream>
#include <string>
#include <fstream>
#include <math.h> 

using namespace std;

//Prototype for the readfile function
int readFile(string);

int main(int argc, char* argv[]) //argc/argv are included when running this program, which is the executable name and the text file
{

    //This checks if executable and file were both input correctly, and if they aren't, ends the program
    if (argc != 2){
      
        cout << "File was not found" << endl;

        return 0;
    }

    else{

    //This is a variable holding the textfile
    string numberList = "test.txt";

    //Call the function that will read, calculate, and output the content of the textfile 
    int hex = readFile(numberList);

    }

    return 0;
}

//Implementation of the readfile function
int readFile(string readList)
{
    //Use the ifstream library to make a variable
    ifstream inputFile;

    //These variables hold the input from the textfile, being the operation and numbers respectivly
    string opToDo;
    uint32_t firstNum, secondNum, newNum;

    //This opens the file for reading
    inputFile.open(readList);

    //Check if the inputfile is able to be open for reading, and end the program if it cannot
    if(!inputFile)
    {
        cout << "File was not found" << endl;
        return -1;
    }
    
    //Use the insertion operator as well as the hex converter to store the lines of the textfile into variables
    //It should go as long as the input file has content to read
    do
    {
        //Check if the operation preformed is addition
        if(opToDo == "ADD" || opToDo == "ADDS")
        {
            //Add the two hex numbers together
            newNum = firstNum + secondNum;

            //Output all variables using cout, and make sure to convert all numbers to hex
            cout << opToDo << " 0x" << hex << firstNum << " 0x" << hex << secondNum << ": <0x" << newNum << ">" << endl;
        }

        if(opToDo == "SUB" || opToDo == "SUBS")
        {
            newNum = firstNum - secondNum;

            cout << opToDo << " 0x" << hex << firstNum << " 0x" << hex << secondNum << ": <0x" << newNum << ">" << endl;

        }

        if(opToDo == "AND" || opToDo == "ANDS")
        {
            newNum = firstNum & secondNum;

            cout << opToDo << " 0x" << hex << firstNum << " 0x" << hex << secondNum << ": <0x" << newNum << ">" << endl;
        }

        if(opToDo == "ORR" || opToDo == "ORRS")
        {
            newNum = firstNum | secondNum;

            cout << opToDo << " 0x" << hex << firstNum << " 0x" << hex << secondNum << ": <0x" << newNum << ">" << endl;
        }

        if(opToDo == "XOR" || opToDo == "XORS")
        {
            newNum = firstNum ^ secondNum;

            cout << opToDo << " 0x" << hex << firstNum << " 0x" << hex << secondNum << ": <0x" << newNum << ">" << endl;
        }

        if(opToDo == "ASR" || opToDo == "ASRS")
        {
            newNum = firstNum / pow(2, secondNum);

            cout << opToDo << " 0x" << hex << firstNum << " " << hex << secondNum << ": <0x" << newNum << ">" << endl;

        }

        if(opToDo == "LSR" || opToDo == "LSRS")
        {
            newNum = firstNum / pow(2, secondNum);

            cout << opToDo << " 0x" << hex << firstNum << " " << hex << secondNum << ": <0x" << newNum << ">" << endl;
        }

        if(opToDo == "LSL" || opToDo == "LSLS")
        {
            newNum = firstNum * pow(2, secondNum);

            cout << opToDo << " 0x" << hex << firstNum << " " << hex << secondNum << ": <0x" << newNum << ">" << endl;
        }

        //Check for overflow
        if(secondNum > UINT32_MAX - firstNum)
        {
            cout << "Overflow: <yes>" << endl;
        }
        else
        {
            cout << "Overflow: <no>" << endl;
        }
    }while(inputFile >> opToDo >> hex >> firstNum >> secondNum);

    do
    {
        if(opToDo == "NOT" || opToDo == "NOTS")
        {
            newNum = ~firstNum;

            cout << opToDo << " 0x" << hex << firstNum << hex << ": <0x" << newNum << ">" << endl;
        }

    }while (inputFile >> opToDo >> hex >> firstNum);
    
    return 1;
}