#include "Publication.h"
#include <iostream>
#include <string>
using namespace std;

void Publication::storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock) {
    title = itemTitle;
    publisher = itemPublisher;
    price = itemPrice;
    year = itemYear;
    type = itemType;
    stock = itemStock;
}

void Publication::displayInfo() {
    cout << "Title: " << title << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Price: " << price << endl;
    cout << "Year: " << year << endl;
    cout << "Type: " << type << endl;
    cout << "Stock: " << stock << endl;
}

void Publication::checkOut() {
    if (stock > 0)
        stock--;
    else
        cout << "Error: Stock is zero" << endl;
}

void Publication::checkIn() {
    stock++;
}

string Publication::getTitle() {
    return title;
}

int Publication::getStock() {
    return stock;
}
