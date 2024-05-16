// Copyright 2022 UNN-IASR

#include "Automata.h"
#include <iostream>


Automata::Automata() {
    cash = 0;
    state = OFF;
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
    for (size_t i = 0; i < 7; i++) {
        std::cout << "(- " << menu[i];
        std::cout << ": price " << prices[i] << ")" << std::endl;
    }
}

void Automata::getstate() {
    std::cout << "Current state: " << state << std::endl;
}

void Automata::choice(std::string drink) {
    std::cout << "Enter your choice: ";
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
        std::cout << "Payment accepted. Please waitk." << std::endl;
    } else {
        std::cout << "Please insert more.";
        state = WAIT;
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
    if (state = ACCEPT) {
        std::cout << "Cooking your coffee..." << std::endl;
    } else {
        state = WAIT;
    }
}

void Automata::finish() {
    cash = 0;
    list.clear();
    state = WAIT;
    std::cout << "Thank you. Have a nice day!" << std::endl;
}
