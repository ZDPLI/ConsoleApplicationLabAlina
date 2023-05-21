#include "pch.h"

using namespace System;
using namespace System::Collections::Generic;

ref class Client
{
public:
    String^ name;
    String^ email;
    int orderNumber;
    String^ paymentMethod;

    Client(String^ name, String^ email, int orderNumber, String^ paymentMethod)
    {
        this->name = name;
        this->email = email;
        this->orderNumber = orderNumber;
        this->paymentMethod = paymentMethod;
    }
};

ref class Order
{
public:
    int orderNumber;
    int numTickets;
    double totalCost;

    Order(int orderNumber, int numTickets, double totalCost)
    {
        this->orderNumber = orderNumber;
        this->numTickets = numTickets;
        this->totalCost = totalCost;
    }
};

ref class PaymentMethod
{
public:
    String^ name;
    String^ description;

    PaymentMethod(String^ name, String^ description)
    {
        this->name = name;
        this->description = description;
    }
};

ref class TicketSales
{
private:
    List<Client^>^ clients;

public:
    TicketSales()
    {
        clients = gcnew List<Client^>();
        clients->Add(gcnew Client("Ivan Gorkov", "vano117@example.com", 1, "Mir Card"));
        clients->Add(gcnew Client("Evgeniy Polsky", "jekagt26@example.com", 2, "Sberpay"));
        clients->Add(gcnew Client("Timur Ghadzhiev", "dag05gt@example.com", 3, "Mir Card"));
        clients->Add(gcnew Client("Alisa Prankovich", "alice.verner@example.com", 4, "Sberpay"));
        clients->Add(gcnew Client("Alexey Karnavalny", "lexa_prazdnik@example.com", 5, "SBP"));
    }

    List<Client^>^ GetClientsByOrderNumber(int orderNumber)
    {
        List<Client^>^ result = gcnew List<Client^>();
        for each (Client ^ client in clients)
        {
            if (client->orderNumber == orderNumber)
            {
                result->Add(client);
            }
        }
        return result;
    }

    List<Client^>^ GetClientsByPaymentMethod(String^ paymentMethod)
    {
        List<Client^>^ result = gcnew List<Client^>();
        for each (Client ^ client in clients)
        {
            if (client->paymentMethod == paymentMethod)
            {
                result->Add(client);
            }
        }
        return result;
    }
};
using namespace System;

int main(array<System::String^>^ args)
{
    TicketSales^ ticketSales = gcnew TicketSales();

    // Test 1: Get clients by order number
    Console::WriteLine("Test 1: Get clients by order number");
    int orderNumber = 3;
    List<Client^>^ clients = ticketSales->GetClientsByOrderNumber(orderNumber);
    if (clients->Count == 1 && clients[0]->name == "Ivan Gorkov")
    {
        Console::WriteLine("Test passed");
    }
    else
    {
        Console::WriteLine("Test failed");
    }

    // Test 2: Get clients by payment method
    Console::WriteLine("Test 2: Get clients by payment method");
    String^ paymentMethod = "Mir Card";
    clients = ticketSales->GetClientsByPaymentMethod(paymentMethod);
    if (clients->Count == 2 && clients[0]->name == "Ivan Gorkov" && clients[1]->name == "Timur Ghadzhiev")
    {
        Console::WriteLine("Test passed");
    }
    else
    {
        Console::WriteLine("Test failed");
    }

    Console::ReadLine();

    return 0;
}