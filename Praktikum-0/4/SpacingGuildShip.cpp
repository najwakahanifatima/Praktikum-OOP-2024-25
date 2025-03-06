#include "SpacingGuildShip.hpp"
#include <iostream>

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : guildNavigatorCount(3), maxPassengerCap(50), serialNum(producedShips+1) {
    passengerCount = 0;
    spiceStock = 50;
    operatingGuildNavigator = this->guildNavigatorCount;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : guildNavigatorCount(guildNavigatorCount), maxPassengerCap(maxPassengerCap), serialNum(producedShips+1){
    passengerCount = 0;
    this->spiceStock = spiceStock;
    operatingGuildNavigator = guildNavigatorCount;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& s) : serialNum(producedShips+1), maxPassengerCap(s.maxPassengerCap), guildNavigatorCount(s.guildNavigatorCount){
    this->passengerCount = s.passengerCount;
    this->spiceStock = s.spiceStock;
    this->operatingGuildNavigator = s.operatingGuildNavigator;
    producedShips++;
}

SpacingGuildShip::~SpacingGuildShip(){}

int SpacingGuildShip::getShipSerialNum() const {
    return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const {
    return this->passengerCount;
}

void SpacingGuildShip::travel(float distance){
    if (operatingGuildNavigator == 0){} else {
        this->totalGuildTravel += (distance / ((E*E) * operatingGuildNavigator ));
        this->operatingGuildNavigator -= 1;
    }
}

void SpacingGuildShip::boarding(int addedPassengers){
    if (this->passengerCount + addedPassengers <= this->maxPassengerCap){
        this->passengerCount += addedPassengers;
    } else {
        this->passengerCount = this->maxPassengerCap;
    }
}

void SpacingGuildShip::dropOff(int droppedPassangers){
    if (this->passengerCount - droppedPassangers <= 0){
        this->passengerCount = 0;
    } else {
        this->passengerCount -= droppedPassangers;
    }
}

void SpacingGuildShip::refreshNavigator(int n){
    (n <= this->guildNavigatorCount) ? n = n : n = this->guildNavigatorCount;
    if (n * GUILD_NAVIGATOR_SPICE_DOSE >= spiceStock){
        int maks_n = spiceStock / guildNavigatorCount;
        this->spiceStock -= (maks_n * GUILD_NAVIGATOR_SPICE_DOSE);
        this->operatingGuildNavigator += maks_n;
    } else {
        this->spiceStock -= (n * GUILD_NAVIGATOR_SPICE_DOSE);
        this->operatingGuildNavigator += n;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice){
    this->spiceStock += addedSpice;
}