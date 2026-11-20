#include <iostream>
#include "1-56.hpp"

int main() {

    AirlineTicket ticket;
    ticket.setPassengerName("Bill Gates");
    ticket.setNumberOfMiles(12000);
    double price = ticket.calculatePriceInDollars();
    ticket.setFrequentFlyerNumber(std::nullopt);
    auto number = ticket.getFrequentFlyerNumber();

    std::cout << ticket.getPassengerName() << "\n";
    std::cout << ticket.getNumberOfMiles() << "\n";
    std::cout << price << "\n";

    if (number.has_value()) {
        std::cout << number.value() << "\n";
    } else {
        std::cout << "Passenger has no Frequent-flyer number" << "\n";
    }

    return 0;
}