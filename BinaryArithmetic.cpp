#include <bitset>
#include <iostream>
#include <limits>
#include <random>

using bin_type = std::bitset<8>;

void clearCinBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

unsigned long long generateRandomInt(const int min, const int max) {
    static std::mt19937 mt(
        static_cast<std::mt19937::result_type>(std::time(nullptr)));
    std::uniform_int_distribution rand(min, max);
    return static_cast<unsigned long long>(rand(mt));
}

bin_type add(const bin_type& A, const bin_type& B) {
    return bin_type{A.to_ulong() + B.to_ulong()};
}

bin_type sub(const bin_type& A, const bin_type& B) {
    return bin_type{A.to_ulong() - B.to_ulong()};
}

void printQuestion(const bin_type& A, const bin_type& B, char op) {
    std::cout << A.to_string() << ' ' << op << ' ' << B.to_string() << " =\n";
}

void checkQuestion(bin_type ans) {
    bin_type user_guess;
    std::cin >> user_guess;
    clearCinBuffer();

    if (user_guess == ans) {
        std::cout << "Correct!\n";
    } else {
        std::cout << "Incorrect the correct answer is: " << ans.to_string()
                  << '\n';
    }
}

void askQuestions() {
    bin_type A{generateRandomInt(0, std::numeric_limits<uint8_t>().max())};
    bin_type B{generateRandomInt(0, std::numeric_limits<uint8_t>().max())};
    printQuestion(A, B, '+');
    checkQuestion(add(A, B));
    printQuestion(A, B, '-');
    checkQuestion(sub(A, B));
}

int getInt(std::string_view prompt) {
    int userInput{};
    while (true) {
        std::cout << prompt;
        std::cin >> userInput;
        if (std::cin.fail()) {
            std::cout << "Invalid input, please try again.\n";
            clearCinBuffer();
        } else {
            break;
        }
    }
    clearCinBuffer();
    return userInput;
}

int main() {
    int numQues{getInt("How many questions would you like?\n")};
    const int questionTypes{2};
    std::cout << "You can have " << questionTypes * numQues
              << " questions instead, Good luck!\n";
    for (int qCount = 0; qCount < numQues; ++qCount) {
        askQuestions();
    }
    return 0;
}