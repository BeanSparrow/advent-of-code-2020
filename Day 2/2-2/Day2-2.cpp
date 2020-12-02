#include <iostream>
#include <fstream>

using namespace std;

void readInputToArray()
{
    //Creates an input file stream
    fstream in("input.in", fstream::in);

    std::string password; //variable to hold input

    //Parser Variables
    int lowest{0};
    int highest{0};
    int countPasswords{0};
    int countLetters{0};
    char letter{};
    char delimiter{};

    //Parser Loop
    while (in >> lowest >> delimiter >> highest >> letter >> delimiter >> password)
    {
        countLetters = std::count(std::begin(password), std::end(password), letter);

        //Password Policy
        if (((password[lowest - 1] == letter) || (password[highest - 1] == letter)) && (password[lowest - 1] != password[highest - 1]))
        {
            countPasswords++;
        }
    }

    std::cout << countPasswords;
    //Close the File Stream
    in.close();
}
int main()
{
    readInputToArray();
    return 0;
}