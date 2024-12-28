#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <stdlib.h>

void MainMenu() {
    std::cout << "Welcome to the Casino!\n\n"
    << "We're currently just opening up so there is only one game available:\nBlack Jack!"
    << "\n\nEnter to continue\n";
    std::cin.get();
}

int aceSwitch = 0; //Will track if aces have been changed to 1

int FindAceValue() {
    if (aceSwitch == 0) {
        aceSwitch = 1;
        return 1;
    }
    return 11; //Somewhat redundant line (because you will bust anyway), but need it for return
};

struct card {
    std::string cardName;
    std::string cardType;
    int cardValue;

    bool operator==(const card& other) const { //Makes cards comparable (I don't think this is ever used)
        return (cardName == other.cardName && cardValue == other.cardValue);
    }
};

std::vector<card> cards = { //List of all the cards in a deck (no jokers)
{"King of Spades", "King",10},
{"King of Diamonds", "King",10},
{"King of Clubs", "King",10},
{"King of Hearts", "King",10},
{"Queen of Spades", "Queen",10},
{"Queen of Clubs", "Queen",10},
{"Queen of Diamonds", "Queen",10},
{"Queen of Hearts", "Queen",10},
{"Jack of Spades", "Jack",10},
{"Jack of Diamonds", "Jack",10},
{"Jack of Hearts", "Jack",10},
{"Jack of Clubs", "Jack",10},
{"Ten of Diamonds", "Ten",10},
{"Ten of Hearts", "Ten",10},
{"Ten of Clubs", "Ten",10},
{"Ten of Spades", "Ten",10},
{"Nine of Diamonds", "Nine",9},
{"Nine of Hearts", "Nine",9},
{"Nine of Clubs", "Nine",9},
{"Nine of Spades", "Nine",9},
{"Eight of Diamonds", "Eight",8},
{"Eight of Hearts", "Eight",8},
{"Eight of Clubs", "Eight",8},
{"Eight of Spades", "Eight",8},
{"Seven of Diamonds", "Seven",7},
{"Seven of Hearts", "Seven",7},
{"Seven of Clubs", "Seven",7},
{"Seven of Spades", "Seven",7},
{"Six of Diamonds", "Six",6},
{"Six of Hearts", "Six",6},
{"Six of Clubs", "Six",6},
{"Six of Spades", "Six",6},
{"Five of Diamonds", "Five",5},
{"Five of Hearts", "Five",5},
{"Five of Clubs", "Five",5},
{"Five of Spades", "Five",5},
{"Four of Diamonds", "Four",4},
{"Four of Hearts", "Four",4},
{"Four of Clubs", "Four",4},
{"Four of Spades", "Four",4},
{"Three of Diamonds", "Three",3},
{"Three of Hearts", "Three",3},
{"Three of Clubs", "Three",3},
{"Three of Spades", "Three",3},
{"Two of Diamonds", "Two",2},
{"Two of Hearts", "Two",2},
{"Two of Clubs", "Two",2},
{"Two of Spades", "Two",2},
{"Ace of Diamonds", "Ace", FindAceValue()},
{"Ace of Hearts", "Ace", FindAceValue()},
{"Ace of Clubs", "Ace", FindAceValue()},
{"Ace of Spades", "Ace", FindAceValue()},
};

card GetCard(std::vector<card> &currentDeck) { //& is there to make this a reference
    card currentCard = currentDeck[rand() % currentDeck.size()];
    currentDeck.erase(find(currentDeck.begin(), currentDeck.end(), currentCard));
    return currentCard;
}

void PrintHand(const std::vector<card> &hand) {
    for (const card& i : hand) {
        std::cout << "| " << i.cardName << " |"; //want to intersperse cards with commas
    }
    std::cout << std::endl;
}

void DrawCard(std::vector<card> &currentDeck, std::vector<card> &hand) { //See comment on GetCard() function
    hand.push_back(GetCard(currentDeck));
}

void FirstDraw(std::vector<card> &currentDeck, std::vector<card> &hand, std::vector<card> &dealerHand) {
    // Draw
}

void PlaceBets(int &money) {
    std::cin.clear();
    std::cin.ignore(256, '\n');
    int bet = 0;
    std::cout << "Money: " << money << std::endl << std::endl
    << "Input your bet:" << std::endl;
    std::cin >> bet;
    while (std::cin.fail()) {
        std::cout << "Money: " << money << std::endl << std::endl
        << "Please input a valid integer to bet:" << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> bet;
    }
    money -= bet;
    // Take in bet and remove it from money
}

void PlayHand(std::vector<card> &deck, std::vector<card> &hand) {
    // Player chooses how to play hand until they bust, draw, or surrender
    // Hit, Stand, Split, Surrender, Double Down

    std::vector<std::string> actions = {"h", "s", "sp", "dd", "surrender"};
    std::string action;
    std::cin.clear();
    std::cin.ignore(256, '\n');

    std::cout << "Input your action: [h]it, [s]tand, [sp]lit, [dd]ouble draw, or [su]rrender" << std::endl;
    std::cin >> action;
    while (find(actions.begin(), actions.end(), action) == actions.end()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Please input a valid action: [h]it, [s]tand, [sp]lit, [dd]ouble draw, or [su]rrender"
        << std::endl;
        std::cin >> action;
    }

    if (action == "h") {
        DrawCard(deck, hand);
        std::cout << "You drew the " << hand.back().cardName << std::endl;
    }

}

void EndTurn(const std::vector<card> &hand, std::vector<card> &dealerHand) {
    // Based on hands does things
}

void MainGame(int money = 500) { //series of functions repeating that represents each turn

    int turnCounter = 0;
    std::vector<card> deck = {};
    while (money > 0) {
        if (turnCounter % 2 == 0) {
            deck = cards;
        }
        int handValue = 0;
        std::vector<card> hand = {};
        std::vector<card> dealerHand = {};
        PlaceBets(money);
        FirstDraw(deck, hand, dealerHand);
        PlayHand(deck, hand);
        EndTurn(hand, dealerHand);

        turnCounter++;
        //second deal function
    }
}

int main() {

    MainMenu();
    MainGame();

}

/**
 * Black Jack is played in a series of turns
 * These turns consist of the following actions in the following sequence
 * The player places a bet
 * The player is dealt two cards
 * The dealer is dealt one face up and one face down card.
 * The player can stand, hit, double down, split, and surrender
 * When the player is done the dealer shows their second card and hits until their hand is 17 or more
 * Then, the win conditions are checked and the money distributed.
**/