#include <boost/math/distributions/normal.hpp>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <iostream>

double periodicDailyRtn(double currentPrice, double prevPrice) {
    return log(currentPrice/prevPrice);
}

std::vector<double> periodDailyReturns (std::vector<double> series) {
    int length = series.size();
    std::vector<double> periodicReturns(length);
    for (int i = 1; i < length; i++) {
        double periodicReturn = periodicDailyRtn(series[i], series[i-1]);
        periodicReturns.push_back(periodicReturn);
    }

    return periodicReturns;
}

double mean(std::vector<double> series) {
    double sum = 0;
    double length = series.size();
    for (int i = 0; i < length; i++) {
        sum += series[i];
    }
    return sum/length;
}

double variance(std::vector<double> series) {
    double meanVal = mean(series);
    double length = series.size();
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += pow(series[i] - meanVal, 2);
    }
    return sum / (length-1);
}

double drift(std::vector<double> series) {
    // Calculates drift of a price series
    std::vector<double> periodicReturns = periodDailyReturns(series);
    double meanReturn = mean(periodicReturns);
    double var = variance(periodicReturns);
    return meanReturn - (var/2);
}

double randomVariable(std::vector<double> series) {
    std::vector<double> periodicReturns = periodDailyReturns(series);
    double var = variance(periodicReturns);
    std::srand(std::time(nullptr));
    double p = std::rand() / (RAND_MAX + 1.); // Generate a number between 0 and 1 with 5s.f. of precision
    boost::math::normal_distribution<double> dist(0.0, 1.0);
    double z = boost::math::quantile(dist, p);
    return var * z;
}