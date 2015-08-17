#include "argList.hpp"
#include <iostream>

namespace pawlib
{
    ArgList::ArgList(int init_size /*= 6 */):length(init_size)
    {
        for(int i = 0; i <= MAX_SIZE; i++)
        {
            // Initialize everything in length as NO_TYPE
            if (i < length)
                masterList[i].type = NO_TYPE;
            // All else is set to ERROR_TYPE
            else
                masterList[i].type = ERROR_TYPE;
        }
        tempObject.type = NO_TYPE;
    }

    void ArgList::addToPos(Args newItem, int pos)
    {
        if ((pos < length) && (pos >= 0))
        {
            //Copy input to tempObject for reference
            tempObject.type = newItem.type;
            switch(tempObject.type)
            {
                case NO_TYPE:
                    std::cerr<< "Cannot add Arg with no type" <<std::endl;
                    break;
                case BOOL_TYPE:
                    tempObject.bool_val = newItem.bool_val;
                    break;
                case CHAR_TYPE:
                    tempObject.char_val = newItem.char_val;
                    break;
                case SHORT_TYPE:
                    tempObject.short_val = newItem.short_val;
                    break;
                case INT_TYPE:
                    tempObject.int_val = newItem.int_val;
                    break;
                case LONG_TYPE:
                    tempObject.long_val = newItem.long_val;
                    break;
                case FLOAT_TYPE:
                    tempObject.float_val = newItem.float_val;
                    break;
                case DOUBLE_TYPE:
                    tempObject.double_val = newItem.double_val;
                    break;
                case STRING_TYPE:
                    tempObject.string_val = newItem.string_val;
                    break;
                case ERROR_TYPE:
                    std::cerr<< "Cannot insert an ERROR_TYPE"<<std::endl;

            }
            masterList[pos] = newItem; // Add to list
        }
        else
            std::cerr << "ArgListIndexOutOfBounds ERROR" <<std::endl;
    }

    void ArgList::addCurrentArgToPos(int pos)
    {
        if ((pos < length) && (pos >= 0))
            masterList[pos] = tempObject;
        else
            std::cerr << "ArgListIndexOutOfBounds ERROR" <<std::endl;
    }

    bool ArgList::isEmpty()
    {
        return (length == 0);
    }

    bool ArgList::isFull()
    {
        return(length == MAX_SIZE);
    }

    int ArgList::getSize()
    {
        return length;
    }

    void ArgList::resetList(int newSize)
    {
        for(int i = 0; i <= MAX_SIZE; i++)
        {
            if (i < newSize)
                masterList[i].type = NO_TYPE;
            else
                masterList[i].type = ERROR_TYPE;
        }
        length = newSize;
    }

    void ArgList::deleteArg(int pos)
    {
        if (!isEmpty())
        {
            // If at end of ArgList, decrease length, make old value ERROR_TYPE
            if (pos == length - 1)
            {
                length--;
                masterList[length].type = ERROR_TYPE;
            }
            else if ((pos < 0) || (pos >= length))
                std::cerr << "ArgListIndexOutOfBounds ERROR" <<std::endl;
            else
            {
                // Shift all elements to the right
                for(int i = pos; i < (length -1); i++)
                    masterList[i] = masterList[i + 1];
                length--;
                // Make old final value ERROR_TYPE
                masterList[length].type = ERROR_TYPE;
            }
        }
    }

    void ArgList::setBoolValue(bool newBool)
    {
        tempObject.type = BOOL_TYPE;
        tempObject.bool_val = newBool;
    }

    void ArgList::setCharValue(char newChar)
    {
        tempObject.type = CHAR_TYPE;
        tempObject.char_val = newChar;
    }

    void ArgList::setShortValue(short newShort)
    {
        tempObject.type = SHORT_TYPE;
        tempObject.short_val = newShort;
    }

    void ArgList::setIntValue(int newInt)
    {
        tempObject.type = INT_TYPE;
        tempObject.int_val = newInt;
    }

    void ArgList::setLongValue(long newLong)
    {
        tempObject.type = LONG_TYPE;
        tempObject.long_val = newLong;
    }

    void ArgList::setFloatValue(float newFloat)
    {
        tempObject.type = FLOAT_TYPE;
        tempObject.float_val = newFloat;
    }

    void ArgList::setDoubleValue(double newDouble)
    {
        tempObject.type = DOUBLE_TYPE;
        tempObject.double_val = newDouble;
    }

    void ArgList::setStringValue(std::string newString)
    {
        tempObject.type = STRING_TYPE;
        // Not sure why this line doesn't work
        // tempObject.string_val = &newString
        tempObject.string_val = new std::string(newString);
    }
    void ArgList::increaseArraySize()
    {
        if(!isFull())
        {
            // Initialize new last element
            masterList[length].type = NO_TYPE;
            length++;
        }
        else
            std::cerr<<"ArgList IS FULL"<<std::endl;
    }

    void ArgList::displayList()
    {
        std::cout<< "ArgList Contents: "<<std::endl;
        for(int i = 0; i < length; i++)
        {
            std::cout<< "\t";
            switch(masterList[i].type)
            {
                case NO_TYPE:
                    std::cout<< "EMPTY" <<std::endl;
                    break;
                case BOOL_TYPE:
                    if (masterList[i].getBoolValue() == 1)
                        std::cout<< "True" <<std::endl;
                    else
                        std::cout<< "False" <<std::endl;
                    break;
                case CHAR_TYPE:
                    std::cout<< masterList[i].getCharValue() <<std::endl;
                    break;
                case SHORT_TYPE:
                    std::cout<< masterList[i].getShortValue() <<std::endl;
                    break;
                case INT_TYPE:
                    std::cout<< masterList[i].getIntValue() <<std::endl;
                    break;
                case LONG_TYPE:
                    std::cout<< masterList[i].getLongValue() <<std::endl;
                    break;
                case FLOAT_TYPE:
                    std::cout<< masterList[i].getFloatValue() <<std::endl;
                    break;
                case DOUBLE_TYPE:
                    std::cout<< masterList[i].getDoubleValue() <<std::endl;
                    break;
                case STRING_TYPE:
                    std::cout<< masterList[i].getStringValue() <<std::endl;
                    break;
            }
        }
        std::cout<< "ArgList Size = " << length << std::endl;
    }
    Args ArgList::operator[](int pos) const
    {
        if ((pos < 0) || (pos >= length))
        {
            // Create ERROR_TYPE, display error, return ERROR_TYPE
            Args errorArg;
            errorArg.type = ERROR_TYPE;
            errorArg.displayTypeError();
            return masterList[MAX_SIZE];
        }
        else
            return masterList[pos];
    }

    Args& ArgList::operator[](int pos)
    {
        if ((pos < 0) || (pos >= length))
        {
            // Create ERROR_TYPE, display error, return ERROR_TYPE constant
            Args errorArg;
            errorArg.type = ERROR_TYPE;
            errorArg.displayTypeError();
            return masterList[MAX_SIZE];
        }
        else
            return masterList[pos];
    }
}


/***********************************************************
* Args functions
***********************************************************/

bool Args::getBoolValue()
{
    if (type == BOOL_TYPE)
        return bool_val;
    else
    {
        displayTypeError();
        return false;
    }
}

char Args::getCharValue()
{
    if (type == CHAR_TYPE)
        return char_val;
    else
    {
        displayTypeError();
        return '!';
    }
}

short Args::getShortValue()
{
    if (type == SHORT_TYPE)
        return short_val;
    else
    {
        displayTypeError();
        return -1;
    }
}
int Args::getIntValue()
{
    if (type == INT_TYPE)
        return int_val;
    else
    {
        displayTypeError();
        // Return a value that isn't useful
        return -1;
    }
}

long Args::getLongValue()
{
    if (type == LONG_TYPE)
        return long_val;
    else
    {
        displayTypeError();
        return -1;
    }
}

float Args::getFloatValue()
{
    if (type == FLOAT_TYPE)
        return float_val;
    else
    {
        displayTypeError();
        return 0.0;
    }
}

double Args::getDoubleValue()
{
    if (type == DOUBLE_TYPE)
        return double_val;
    else
    {
        displayTypeError();
        return 0.00;
    }
}

std::string Args::getStringValue()
{
    if (type == STRING_TYPE)
        return *(string_val);
    else
    {
        displayTypeError();
        return ("INVALID TYPES");
    }
}

void Args::displayTypeError()
{
    switch(type)
    {
        case NO_TYPE:
            std::cerr<< "TYPE ERROR: EMPTY ARGUMENT"<<std::endl;
            break;
        case BOOL_TYPE:
            std::cerr<< "TYPE ERROR: EXPECTED TYPE BOOL"<<std::endl;
            break;
        case CHAR_TYPE:
            std::cerr<< "TYPE ERROR: EXPECTED TYPE CHAR"<<std::endl;
            break;
        case SHORT_TYPE:
            std::cerr<< "TYPE ERROR: EXPECTED TYPE SHORT"<<std::endl;
            break;
        case INT_TYPE:
            std::cerr<< "TYPE ERROR: EXPECTED TYPE INT"<<std::endl;
            break;
        case LONG_TYPE:
            std::cerr<< "TYPE ERROR: EXPECTED TYPE LONG"<<std::endl;
            break;
        case FLOAT_TYPE:
            std::cerr<< "TYPE ERROR: EXPECTED TYPE FLOAT"<<std::endl;
            break;
        case DOUBLE_TYPE:
            std::cerr<< "TYPE ERROR: EXPECTED TYPE DOUBLE"<<std::endl;
            break;
        case STRING_TYPE:
            std::cerr<< "TYPE ERROR: EXPECTED TYPE STRING"<<std::endl;
            break;
        case ERROR_TYPE:
            std::cerr << "ArgListIndexOutOfBounds ERROR" <<std::endl;
            break;
    }
}
