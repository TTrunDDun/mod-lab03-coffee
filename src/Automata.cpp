// Copyright 2022 UNN-IASR
#include "automata.h"
#include <iostream>


automata::automata() {
    cash = 0;
    state = OFF;
}

void automata::on() {
    state = wait;
    std::cout << "The Coffe Machin is working." << std::endl;
}

void automata::off() {
    state = OFF;
    std::cout << "Automata is turned off." << std::endl;
}

void automata::coin(int coins) {
    if (state == wait || state == accept) {
        std::cout << "Please,put the money." << std::endl;
        cash += coins;
        state = accept;
        std::cout << "The balance: " << cash << std::endl;
    }
}
void automata::etmenu() {
    std::cout << "Choose a coffee"<< std::endl << "Menu:" << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << "(- " << menu[i] << ": price " << prices[i] << ")" << std::endl;
    }
}

void automata::getstate() {
    std::cout << "Current state: " << state << std::endl;
}

void automata::choice() {
    std::string drink;
    std::cout << "Enter your choice: ";
    std::cin >> drink;
    list.push_front(drink);
}

void automata::check() {
    int total = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        for (int i = 0; i < 7; i++) {
            if (*it == menu[i]) {
                total += prices[i];
            }
        }
    }
    if (cash >= total) {
        state = accept;
        std::cout << "Payment accepted. Please wait for your drink." << std::endl;
    }
    else {
        std::cout << "Not enough money. Please insert more." << std::endl;
    }
}

void automata::cancel() {
    cash = 0;
    list.clear();
    state = wait;
    std::cout << "Order canceled. Please make a new selection." << std::endl;
}

void automata::cook() {
    std::cout << "Cooking your coffee..." << std::endl;
}

void automata::finish() {
    cash = 0;
    list.clear();
    state = wait;
    std::cout << "Thank you. Have a nice day!" << std::endl;
}
