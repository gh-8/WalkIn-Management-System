/*
 * WIBCS.cpp - Assignment3
 *
 * Class Description: Models a walk-in bank client system.
 */

#include <iostream>
#include <sstream>
#include <string>
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"
#include "Client.h"
#include "Node.h"
#include "Queue.h"

using namespace std;

void simulate();
double processArrival(Client arrivalEvent, PriorityQueue<Client>& eventPriorityQueue, Queue<Client>& bankLine, int currentTime, bool& tellerAvailable);
double processDeparture(Client deparetureEvent, PriorityQueue<Client>& eventPriorityQueue, Queue<Client>& bankLine, int currentTime, bool& tellerAvailable);

int main()
{
    simulate();
    return 0;
}

void simulate()
{
    Queue<Client> bankLine; // generate and store a bank line
    PriorityQueue<Client> eventPriorityQueue; // generate and store an event queue
    bool tellerAvailable = true;
    
    string aLine;
    int arrivalTime = 0; // client arrival time
    int transactionTime = 0; // needed time for client's transaction
    
    Client newArrivalClient; // new client
    newArrivalClient.setType("A"); // setting type of the newly arrived client to 'Arrival'
    
    int numPeopleProcessed = 0;
    
    while(getline(cin, aLine)) // while the data file is not empty
    {
        stringstream myString(aLine);
        myString >> arrivalTime >> transactionTime;
        
        if (arrivalTime == -1)
        {
            break;
        }
        
        if (arrivalTime >= 0 && transactionTime >= 0) // new client found
        {
            newArrivalClient.setTime(arrivalTime); // new client's info stored: arrival Time, Transaction Time
            newArrivalClient.setLength(transactionTime);
            eventPriorityQueue.enqueue(newArrivalClient);
            numPeopleProcessed++; // increment counter for a number of clients
        }
    }
    
    Client newEvent; // new event under certain cdns
    int currentTime=0;//intitalize our Current time
    
    double waitTime = 0.0; //intitalize
    double AllWaitTime = 0.0; //intitalize
    
    cout << "Simulation Begins" << endl;
    
    while(!(eventPriorityQueue.isEmpty()))
    {
        try
        {
            newEvent = eventPriorityQueue.peek();
        }
        catch(EmptyDataCollectionException e)
        {
            cout << e.what();
        }
        
        currentTime = newEvent.getTime();
        
        if(newEvent.getType() == "A")
        {
            waitTime = processArrival(newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable);
            cout << "Processing an arrival event at time:    " << newEvent.getTime() << endl;
            AllWaitTime = AllWaitTime + waitTime;
        }
        else
        {
            waitTime = processDeparture(newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable);
            cout << "Processing a departure event at time:   " << newEvent.getTime() << endl;
            AllWaitTime = AllWaitTime + waitTime;
        }
    }
    
    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl;
    cout << "	Total number of people processed:  " << numPeopleProcessed << endl;
    if(numPeopleProcessed == 0)
    {
        cout << "	Average amount of time spent waiting: 0" << endl;
    }
    else
    {
        cout << "	Average amount of time spent waiting:" << AllWaitTime/numPeopleProcessed << endl;
    }
}

double processArrival(Client arrivalEvent, PriorityQueue<Client>& eventPriorityQueue, Queue<Client>& bankLine, int currentTime, bool& tellerAvailable)
{
    eventPriorityQueue.dequeue();
    
    int departureTime=0;
    Client newDepartureEvent("D", 0, 0);

    if(bankLine.isEmpty() && tellerAvailable)
    {
        departureTime = currentTime + arrivalEvent.getLength();
        newDepartureEvent.setTime(departureTime);
        eventPriorityQueue.enqueue(newDepartureEvent);
        tellerAvailable = false;
        
        return (currentTime - arrivalEvent.getTime());
    }
    else
    {
        bankLine.enqueue(arrivalEvent);
    }
    
    return 0;
}

double processDeparture(Client deparetureEvent, PriorityQueue<Client>& eventPriorityQueue, Queue<Client>& bankLine, int currentTime, bool& tellerAvailable)
{
    eventPriorityQueue.dequeue(); // deleteing an event from Priority Queue
    
    int arrivalTime=0;
    
    if(!bankLine.isEmpty())
    {
        arrivalTime = bankLine.peek().getTime();
    }
    
    Client customer;
    Client newDepartureClient("D", 0, 0);
    int departureTime=0;
    
    if(!bankLine.isEmpty()) // checking for exceptions
    {
        try
        {
            customer = bankLine.peek();
        }
        catch(EmptyDataCollectionException e)
        {
            cout << e.what();
        }
        
        bankLine.dequeue(); // delete an event from bank line
        departureTime = currentTime + customer.getLength();
        newDepartureClient.setTime(departureTime);
        eventPriorityQueue.enqueue(newDepartureClient);
        
        return (currentTime - arrivalTime);
    }
    else
    {
        tellerAvailable = true;
    }
    
    return 0;
    
}


