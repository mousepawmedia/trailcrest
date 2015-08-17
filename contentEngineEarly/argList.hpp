/**
* The class ArgList is an array of seemingly heterogeneous types. In reality
* each element is an Args struct. Each Args struct contains a char to indicate
* type and a union value that can be one of 8 different types at any given time.
* Args also contains "get" functions for each possible type. The user is allowed
* to manually set the types and values of any of the elements in an ArgList, but
* this increases the likelihood of errors. It is instead recommended that the
* user use the "set" functions combined with the "addCurrentArgToPos" to add
* and modify elements of ArgList. This ensures matching types.
**/

#ifndef ARGLIST_HPP
#define ARGLIST_HPP

#include <iostream>

// Define type constants
const char NO_TYPE     = 0;
const char BOOL_TYPE   = 1;
const char CHAR_TYPE   = 2;
const char SHORT_TYPE  = 3;
const char INT_TYPE    = 4;
const char LONG_TYPE   = 5;
const char FLOAT_TYPE  = 6;
const char DOUBLE_TYPE = 7;
const char STRING_TYPE = 8;
const char ERROR_TYPE  = 9;
// Declare the largest ArgList can be
const int MAX_SIZE = 6;

/// There are two active variables at any given time in Args.
/// 'type' represents the type of the Args.
/// The second variable is whichever member of the union is currently active
struct Args
{
    char type;
    union
    {
        bool bool_val;
        char char_val;
        short short_val;
        int int_val;
        long long_val;
        float float_val;
        double double_val;
        std::string* string_val;
    };
    // Need getter functions to appropriately call
    bool getBoolValue();
    char getCharValue();
    short getShortValue();
    int getIntValue();
    long getLongValue();
    float getFloatValue();
    double getDoubleValue();
    std::string getStringValue();
    void displayTypeError();
};

namespace pawlib
{
    class ArgList
    {
        public:
            /**
             * Constructor
             * \param init_size Desired size of ArgList. Default is MAX_SIZE.
             */
            ArgList(int init_size = 6);

            /**
             * Adds an Args argument to ArgList. Copies it to tempObject.
             * \param newItem An Args argument.
             * \param pos The position in the ArgList where newItem is added.
             */
            void addToPos(Args newItem, int pos);

            /** Add tempObject to ArgList
             * \param pos The position in the ArgList where tempObject is added.
             */
            void addCurrentArgToPos(int pos);
            bool isEmpty();
            bool isFull();
            int getSize();
            void resetList(int newSize);
            void deleteArg(int pos);

            /**
             * All setters will set the tempObject's value and type as so...
             * Set tempObject's type to bool and its value to the argument.
             * \param newBool A boolean that will become tempObject's value.
             */
            void setBoolValue(bool newBool);
            void setCharValue(char newChar);
            void setShortValue(short newShort);
            void setIntValue(int newInt);
            void setLongValue(long newLong);
            void setFloatValue(float newFloat);
            void setDoubleValue(double newDouble);
            void setStringValue(std::string newString);
            void increaseArraySize(); // Increases size by 1
            void displayList();

            /// Overload brackets
            Args operator [](int pos) const;
            Args& operator [](int pos);

        private:
            /// tempObject is set by the user and can be added to masterList
            Args tempObject;
            /// Indexes 0 to (length -1) in masterList are the visible ArgList
            /// Indexes length to (MAX_SIZE -1) are Error_TYPE Args
            /// Index MAX_SIZE is a constant ERROR_TYPE used for OutofBounds errors
            Args masterList[MAX_SIZE + 1];
            int length;

    };
}
#endif //ArgList
