#include "stats.h"
#include <iostream>
#include <vector>
#include <math.h>

int main(void) {
    // Get price series from user

    // Calculate drift = avg(periodic daily returns) - variance/2

    // For each following day, calculate random var = variance * norm inv(rand)

    // Calc day price = today price * e^(drift + random var)

    std::cout << "Enter series length:\n";

    int length;
    std::cin >> length;
    std::cout << "Enter prices:\n";

    std::vector<double> prices;
    double price { 0 };

    for (int i = 0; i < length; i++) {
        std::cin >> price;
        prices.push_back(price);
        price = 0;
    }

    std::cout << "Days to simulate:\n";
    int simulationDays { 0 };
    std::cin >> simulationDays;

    double priceDrift = drift(prices);
    double previousDayPrice = prices.back();
    double predictedPrice {0};
    double random {0};

    for(int i = 0; i < simulationDays; i++) {
        random = randomVariable(prices);
        predictedPrice = previousDayPrice * std::exp(priceDrift + random);
        std::cout << "Price in " << i+1 << " days: " << "£" << predictedPrice << std::endl;
        previousDayPrice = predictedPrice;
    }

    return 0;
}