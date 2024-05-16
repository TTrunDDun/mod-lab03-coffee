// Copyright 2022 UNN-IASR

#include "Automata.h"
#include <iostream>


Automata::Automata() : cash(0), state(states::OFF) {
    std::string menu[7] = { "Capuchino",
        "Raf",
        "Americano",
        "Latte",
        "Flat White",
        "Espresso",
        "Dopio"};
    int prices[7] = { 120,
        150,
        80,
        140,
        150,
        50,
        100 };
}

void Automata::on() {
    state = WAIT;
    std::cout << "The Coffe Machin is working." << std::endl;
}

void Automata::off() {
    state = OFF;
    std::cout << "Automata is turned off." << std::endl;
}

void Automata::coin(int coins) {
    if (state == WAIT || state == ACCEPT) {
        std::cout << "Please,put the money." << std::endl;
        cash += coins;
        state = ACCEPT;
        std::cout << "The balance: " << cash << std::endl;
    }
}
void Automata::etmenu() {
    std::cout << "Choose a coffee"<< std::endl << "Menu:" << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << "(- " << menu[i];
        std::cout << ": price " << prices[i] << ")" << std::endl;
    }
}

void Automata::getstate() {
    std::cout << "Current state: " << state << std::endl;
}

void Automata::choice() {
    std::string drink;
    std::cout << "Enter your choice: ";
    std::cin >> drink;
    list.push_front(drink);
}

void Automata::check() {
    int total = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        for (int i = 0; i < 7; i++) {
            if (*it == menu[i]) {
                total += prices[i];
            }
        }
    }
    if (cash >= total) {
        state = ACCEPT;
        std::cout << "Payment accepted. Please wait for your drink." << std::endl;
    } else {
        std::cout << "not enough";
        std::cout << "Please insert more.";
        std::cout << std::endl;
    }
}

void Automata::cancel() {
    cash = 0;
    list.clear();
    state = WAIT;
    std::cout << "Order canceled. Please make a new selection." << std::endl;
}

void Automata::cook() {
    std::cout << "Cooking your coffee..." << std::endl;
}

void Automata::finish() {
    cash = 0;
    list.clear();
    state = WAIT;
    std::cout << "Thank you. Have a nice day!" << std::endl;
}
