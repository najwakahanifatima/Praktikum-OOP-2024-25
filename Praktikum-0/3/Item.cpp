#include "Item.hpp"
#include <iostream>

int Item::totalItems = 0;
int Item::totalRevenue = 0;

Item::Item() : serialNum(totalItems + 1) {
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
    totalItems++;
}

Item::Item(int stock, int price) : serialNum(totalItems + 1){
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    totalItems++;
}

Item::Item(const Item& item) : serialNum(totalItems+1){
    this->stock = item.stock;
    this->price = item.price;
    this->sold = item.sold;
    totalItems++;
}

Item::~Item(){
}

void Item::addStock(int addedStock){
    this->stock += addedStock;
}

void Item::sell(int soldStock){
    if (this->stock <= soldStock){
        this->sold += this->stock;
        totalRevenue += this->price * this->stock;
        this->stock = 0;
    } else {
        this->sold += soldStock;
        this->stock -= soldStock;
        totalRevenue += this->price * soldStock;
    }
}

void Item::setPrice(int newPrice){
    this->price = newPrice;
}

int Item::getSerialNum() const {
    return this->serialNum;
}

int Item::getSold() const {
    return this->sold;
}

int Item::getPrice() const {
    return this->price;
}