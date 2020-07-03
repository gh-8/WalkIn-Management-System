/*
 * EmptyDataCollectionException.h
 *
 * Class Description: Defines the exception that is thrown when the
 *                    data collection ADT class is empty.
 */

#pragma once

#include <stdexcept>
#include <string>
#include <cstdio>

using namespace std;

class EmptyDataCollectionException : public logic_error
{
public:
    EmptyDataCollectionException(const string& message = "");
    
}; // end EmptyDataCollectionException
