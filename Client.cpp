 /*
 * Client.cpp
 *
 * Class Description: Client type.
 * Class Invariant: Each Client has a unique time.
 *                  Has a type and a lenght.
 */
#include <string>
#include <iostream>
#include "Client.h"

using namespace std;

// Default Constructor
Client::Client()
{
    type="";
    time=0;
    length=0;
}

// Parametrized Constructor
Client::Client(string aType, int aTime,  int aLength)
{
    type=aType;
    time=aTime;
    length=aLength;
}

// Getters
//return time
int Client::getTime() const
{
    return time;
}

//return type
string Client::getType() const
{
    return type;
}

//return length
int Client::getLength() const
{
    return length;
}

// Setters
// modify type
void Client::setType(string aType)
{
    type = aType;
}
// modify time
void Client::setTime(int aTime)
{
	time = aTime;
}
// modify length
void Client::setLength(int aLength)
{
	length = aLength;
}

// Overloaded Operators
// Description: Comparison operator. Compares "this" Client object with "rhs" Client object.
//              Returns true if both Client objects have the same care card number.
bool Client::operator==(const Client & rhs){
    return (time == rhs.time);
}

// Description: Greater than operator. Compares "this" Client object with "rhs" Client object.
//              Returns true if the care card number of "this" Client object is > the care card number of "rhs" Client object.
bool Client::operator>(const Client & rhs){
    return (time > rhs.time);
}

