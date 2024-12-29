#include <iostream>
#include <vector>


std::vector<std::string> banana = {"10","hello", "Sarish", "Maden"};

int main() {
    std::string apple;
    for (int i = 0; i < banana.size(); i++) {
        if (i == banana.size() - 1) {
            apple += "or " + banana[i];
            break;
        }
        apple += banana[i] + ", ";
    }
    std::cout << apple << std::endl;
}

// Loop through and put commas between, until the last one where you put a comma and an or.