#ifndef STATS_H
#define STATS_H

#include <vector>

double periodicDailyRtn(double currentPrice, double prevPrice);
std::vector<double> periodDailyReturns (std::vector<double> series);
double mean(std::vector<double> series);
double variance(std::vector<double> series);
double drift(std::vector<double> series);
double randomVariable(std::vector<double> series);

#endif