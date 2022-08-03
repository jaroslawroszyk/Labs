#include "GuessNumber.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
int fo;
namespace Task3
{

    auto Guess::guessNumber() -> void
    {
        int num = 0;
        long long int guess = 0;
        int tries = 0;
        srand(time(0));
        num = rand() % 1000 + 1;

        do
        {
            std::cout << "Enter a guess between 1 and 1000 : ";
            std::cin >> guess;
            tries++;

            if (guess > num)
                std::cout << "Too high!\n";
            else if (guess < num)
                std::cout << "Too low!\n";
            else
                std::cout << "Correct! " << tries << " guesses!\n";
        }
        while (guess != num);
    }

    auto power(int k, int n) -> int
    {
        int result = 1;
        int pow = k;
        while (n > 0)
        {
            if (n % 2 == 1)
                result *= pow;
            pow *= pow;
            n /= 2;
        }
        return result;
    }


} //namepsace Task3