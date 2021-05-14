// Copyright (c) 2021 Layla Michel All rights reserved.
//
// Created by: Layla Michel
// Created on: May 14, 2021
// This program asks the user to input a number between 0 and 9,
// generates a random number and displays a message depending
// on if the guess is the same as the random number or not
// it also display an error message if the input is not an integer

#include <iostream>
#include <random>
#include <string>

int main() {
    // declare variables
    int userGuessAsInt, correct_guess;
    std::string userGuessAsString;

    // get the user guess
    std::cout << "Guess what number I am thinking of between 0 and 9: ";
    std::cin >> userGuessAsString;

    // generate random number
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    correct_guess = idist(rgen);

    try {
        userGuessAsInt = std::stoi(userGuessAsString);

        // check if guess is correct and display message
        // depending on if it's right or wrong
        if (userGuessAsInt == correct_guess) {
            std::cout << "You guessed correctly!\n";
        } else {
            std::cout << "You guessed wrong. The correct answer was: "
            << correct_guess << "\n";
        }
    }  // check if input is an int
    catch (std::invalid_argument) {
        std::cout << userGuessAsString << " is not a valid number.\n";
    }

    // always displays
    std::cout << "Thanks for playing!";
}
