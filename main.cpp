#include <iostream>
#include <vector>

int handValue = 0;

int FindAceValue() {
    int value = 11;
    value = (handValue > 21) ? value = 1 : value = 11;
    return value;
};

struct Card {
    std::string cardName;
    std::string cardType;
    int cardValue;
};

std::vector<Card> cards = {
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
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.