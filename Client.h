/*
 * Client.h
 *
 * Class Description: Client type.
 * Class Invariant: Each Client has a unique time.
 *                  Has a type and a lenght.
 */

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Client {
private:
    string type;
    int time;
    int length;
public:
	// Default Constructor
	Client();

	// Parametrized Constructor
	Client(string aType, int aTime,  int aLength);
    
    //Getters
    string getType() const;
    int getTime() const;
    int getLength() const;
    
	//Setters
    void setType(const string aType);
	void setTime(const int aTime);
	void setLength(const int aLength);
    
    // Overloaded Operators
    // Description: Comparison operator. Compares "this" Client object with "rhs" Client object.
    //              Returns true if both Client objects have the same time.
    bool operator==(const Client & rhs);
    
    // Description: Greater than operator. Compares "this" Client object with "rhs" Client object.
    //              Returns true if the time of "this" Client object is > the time of "rhs" Client object.
    bool operator>(const Client & rhs);
};
