#include "argList.hpp"
#include <iostream>
//using namespace std;
using namespace pawlib;

void showHeader(std::string header)
{
    std::cout<< "\n*******************";
    std::cout<< "************************************************" <<std::endl;
    std::cout<< "** " << header <<std::endl;
    std::cout<< "*******************";
    std::cout<< "************************************************\n" <<std::endl;
}
int main()
{
    // Create argList. Use built in functions to add Arg
    showHeader("Create ArgList with size = 3. Use built-in functions to add int");
    ArgList newList(3);
    newList.setIntValue(32);
    newList.addCurrentArgToPos(0);
    std::cout<< newList[0].getIntValue() << std::endl;

    // Directly set position 1
    showHeader("Manually add a char. Get pos 1");
    newList[1].type = CHAR_TYPE;
    newList[1].char_val = 'S';
    std::cout<< newList[1].getCharValue() << std::endl;

    // Create Arg and set to position 2
    showHeader("Add an existing Args. Get pos 2");
    Args newArg;
    newArg.type = STRING_TYPE;
    newArg.string_val = new std::string("Batman");
    newList[2] = newArg;
    std::cout<< (newList[2].getStringValue()) <<std::endl;

    // Delete newList[1], reducing allowed length by 1
    // Then unsuccessfully try to access newList[2]
    showHeader("Delete pos 1. Get new pos 1. Try to access out of range");
    newList.deleteArg(1);
    std::cout<< (newList[1].getStringValue()) <<std::endl;
    newList[2].type = NO_TYPE;  // Throws error

    // Increase size by one and insert a new Arg
    showHeader("Increase size to 3. Insert a new Args. Get pos 2");
    newList.increaseArraySize();
    Args newFloat;
    newFloat.type = FLOAT_TYPE;
    newFloat.float_val = 3.2;
    newList.addToPos(newFloat, 2);
    std::cout<< newList[2].getFloatValue() <<std::endl;

    // Reset the list to have a size 5
    showHeader("Reset array with size = 5. Prove it's empty, insert Args");
    std::cout<< "RESET ArgList" <<std::endl;
    newList.resetList(5);
    std::cout<< newList[0].getIntValue()<<std::endl; // Returns EMPTY ARG error and -1
    newList.setBoolValue(true);
    newList.addCurrentArgToPos(0);
    newList.setShortValue(23);
    newList.addCurrentArgToPos(1);
    newList.setDoubleValue(3.23);
    newList.addCurrentArgToPos(3); // newList[2] is empty
    newList.setLongValue(3232323);
    newList.addCurrentArgToPos(4);
    newList.displayList();

    // Check if full, increase length, add argument
    showHeader("Increase size, add string");
    if (newList.isFull())
        std::cout<< "The ArgList is full"<<std::endl;
    else
        std::cout<< "The ArgList is not yet full"<<std::endl;
    newList.increaseArraySize();
    newList.setStringValue("Fall Out Boy");
    newList.addCurrentArgToPos(5);
    newList.displayList();

    // Remove the Empty Arg
    showHeader("Delete the Empty argument");
    newList.deleteArg(2);
    newList.displayList();

    // Try to add to Position 5
    showHeader("Try to access out of bounds");
    newList.setBoolValue(false);
    newList.addCurrentArgToPos(5);

    // Increase to max, fill ArgList
    showHeader("Increase to max size, refill ArgList");
    newList.increaseArraySize();
    for(int i = 0; i < newList.getSize(); i++)
    {
        if (i % 2 == 0)
            newList.setBoolValue(true);
        else
            newList.setBoolValue(false);
        newList.addCurrentArgToPos(i);
    }
    newList.displayList();

    // Try to increase list size
    showHeader("Try to increase size past max size");
    newList.increaseArraySize();

    // Create a list defaulted to size 6
    showHeader("Create new ArgList defaulted to size 6");
    ArgList newList2;
    if (newList2.isEmpty())
        std::cout << "ArgList is Empty" <<std::endl;
    else
        newList2.displayList();
}
