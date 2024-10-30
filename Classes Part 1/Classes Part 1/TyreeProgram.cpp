/* 
Cameron Tyree
CIS 1202
March 24 2024
*/

#include "Publication.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

void getPublicationInfo(Publication&);

int main() {
    Publication pub;
    getPublicationInfo(pub);

    cout << "The title is: " << pub.getTitle() << endl;

    pub.checkOut();
    cout << pub.getStock() << " in stock" << endl;

    pub.checkIn();
    cout << pub.getStock() << " in stock" << endl;

    cout << "\n\nPress enter to exit...";
    cin.get();
    return 0;
}

void getPublicationInfo(Publication& pub) {
    string title, publisher;
    double price;
    int year, stock, typeInput;
    PublicationType type;
    string input;

    cout << "Title: ";
    getline(cin, title);
    cout << "Publisher: ";
    getline(cin, publisher);
    while (true) {
        
        cout << "Price: ";
        getline(cin, input);

        istringstream iss(input);
        if (iss >> price) {
            char remainingChar;
            if (iss >> remainingChar) {
                cout << "Wrong input - Please enter a number: " << endl;
            }
            else {
                break;
            }
        }
        else {
            cout << "Wrong input - Please enter a number: " << endl;
        }
    }
    while (true) {

        cout << "Year: ";
        getline(cin, input);

        istringstream iss(input);
        if (iss >> year) {
            char remainingChar;
            if (iss >> remainingChar) {
                cout << "Wrong input - Please enter a number: " << endl;
            }
            else {
                break;
            }
        }
        else {
            cout << "Wrong input - Please enter a number: " << endl;
        }
    }

    cout << "1. Book / 2. Magazine / 3. Newspaper / 4. Audio / 5. Video\nType: ";
    while ((!(cin >> typeInput)) || cin.fail() || typeInput<1 || typeInput>5) {
        cout << "Incorrect input\nPlease enter in the correct range: ";
        cin.ignore();
        cin.sync();
        cin.clear();
    }
    while (true) {

        cout << "Stock: ";
        getline(cin, input);

        istringstream iss(input);
        if (iss >> stock) {
            char remainingChar;
            if (iss >> remainingChar) {
                cout << "Wrong input - Please enter a number: " << endl;
            }
            else {
                break;
            }
        }
        else {
            cout << "Wrong input - Please enter a number: " << endl;
        }
    }
    type = static_cast<PublicationType>(typeInput);

    pub.storePublication(title, publisher, price, year, type, stock);
}