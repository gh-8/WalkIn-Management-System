/*
 * EmptyDataCollectionException.cpp
 *
 * Class Description: Defines the exception that is thrown when the
 *                    data collection ADT class is empty.
 */


#include "EmptyDataCollectionException.h"

EmptyDataCollectionException::EmptyDataCollectionException(const string& message):
logic_error("Empty Data Collection ADT Class Exception: " + message)
{
}  // end constructor

// End of implementation file.
