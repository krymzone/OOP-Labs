#include<iostream>
using namespace std;

// Enum for EventType
enum EventType
{
    CONCERT,
    SPORTS,
    THEATER
};

class Ticket
{
private:
    string serialNumber;  // Serial number (constant, cannot change once set)
    double price;               // Price of the ticket
    bool sold;                  // Sold status
    static int totalEventsCount; // Static variable to track the total number of events

public:
    //Default constructor 
    Ticket() :serialNumber(""), price(0.0), sold(false) {}

    // Constructor with parameters
    Ticket(const string& serial, double ticketPrice, bool isSold)
        : serialNumber(serial), price(ticketPrice), sold(isSold)
    {
        totalEventsCount++; // Increment the total events count whenever a ticket is created
    }

    // Getter for serialNumber
    string getSerialNumber() const
    {
        return serialNumber;
    }

    // Getter for price
    double getPrice() const
    {
        return price;
    }

    // Setter for price
    void setPrice(double newPrice)
    {
        if (newPrice >= 0) // Ensure price is non-negative
            price = newPrice;
        else
            cout << "Price cannot be negative!" << endl;
    }

    // Getter for sold status
    bool isSold() const
    {
        return sold;
    }

    // Setter for sold status
    void setSold(bool isSold)
    {
        sold = isSold;
    }

    // Static method to get total events count
    static int getTotalEventsCount()
    {
        return totalEventsCount;
    }

    // Method to display ticket details
    void display() const
    {
        cout << "Ticket Details:" << endl;
        cout << "Serial Number: " << serialNumber << endl;
        cout << "Price: $" << price << endl;
        cout << "Sold: " << (sold ? "Yes" : "No") << endl;
        cout << "Total Events: " << totalEventsCount << endl;
    }
};



// Class for Event
class Event
{
private:
    string name;          // Event name
    string location;      // Event location
    EventType type;       // Event type
    int soldTickets;      // Number of sold tickets
    Ticket* tickets;      // Dynamic array of Ticket objects

public:
    // Default constructor
    Event() : name("Unknown"), location("Unknown"), type(CONCERT), soldTickets(0), tickets(nullptr) {}

    // Constructor with parameters
    Event(const string& eventName, const string& eventLocation, EventType eventType, int ticketCount, Ticket* tickets)
        : name(eventName), location(eventLocation), type(eventType), soldTickets(ticketCount)
    {
        tickets = new Ticket[ticketCount]; // Dynamically allocate tickets
        for (int i = 0; i < ticketCount; i++)
        {
            // pay attention to shallow copy - Ticket class
            this->tickets[i] = tickets[i];
        }
    }

    // Copy constructor
    Event(const Event& other)
        : name(other.name), location(other.location), type(other.type), soldTickets(other.soldTickets)
    {
        // Deep copy tickets
        tickets = new Ticket[other.soldTickets]; 
        for (int i = 0; i < other.soldTickets; i++)
        {
            tickets[i] = other.tickets[i];
        }
    }

    // Assignment operator
    Event& operator=(const Event& other)
    {
        if (this == &other)
            return *this; // Handle self-assignment

        // Clean up existing tickets
        delete[] tickets;

        // Copy data
        name = other.name;
        location = other.location;
        type = other.type;
        soldTickets = other.soldTickets;

        // Deep copy tickets
        tickets = new Ticket[soldTickets];
        for (int i = 0; i < soldTickets; i++)
        {
            tickets[i] = other.tickets[i];
        }

        return *this;
    }

    // Logical NOT operator (!)
    bool operator!() const
    {
        return soldTickets == 0; // True if no tickets sold
    }

    // Addition operator (+): Adds tickets
    Event& operator+(const Ticket& ticket)
    {
        Event* temp = new Event(*this);

        temp->soldTickets++;
        Ticket* tickets = new Ticket[temp->soldTickets];
        for (int i = 0; i < this->soldTickets; i++)
        {
            temp->tickets[i] = this->tickets[i];
        }
        temp->tickets[this->soldTickets] = ticket;
        return *temp; 
    }

    // Pre-increment operator (++)
    Event& operator++()
    {
        ++soldTickets;
        Ticket* temp = this->tickets;
        this->tickets = new Ticket[soldTickets];
        for (int i = 0; i < soldTickets - 1; i++)
        {
            this->tickets[i] = temp[i];
        }
        this->tickets[soldTickets - 1] = *(new Ticket());
        delete[] temp;
        return *this;
    }

    // Post-increment operator (++)
    Event operator++(int)
    {
        Event temp = *this;
        ++(*this);
        return temp;
    }

    // Subscript operator ([])
    Ticket& operator[](int index)
    {
        if (index < 0 || index >= soldTickets)
            throw out_of_range("Index out of range");
        return tickets[index];
    }

    // Cast to int: Returns the number of sold tickets
    operator int() const
    {
        return soldTickets;
    }

    // Function call operator ()
    void operator()(const string& newName)
    {
        name = newName;
    }

    // Compound assignment operator (+=): Add tickets
    Event& operator+=(int additionalTickets)
    {
        soldTickets += additionalTickets;
        return *this;
    }

    // Overloaded new operator
    void* operator new(size_t size)
    {
        cout << "Custom new operator called" << endl;
        return ::operator new(size);
    }

    // Overloaded -> operator
    Event* operator->()
    {
        return this;
    }

    // Destructor
    ~Event()
    {
        delete[] tickets; // Free allocated memory
    }

    // Display event details
    void display() const
    {
        cout << "Event Name: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Type: " << (type == CONCERT ? "Concert" : type == SPORTS ? "Sports" : "Theater") << endl;
        cout << "Sold Tickets: " << soldTickets << endl;
    }
};

int main()
{
    
    return 0;
}
