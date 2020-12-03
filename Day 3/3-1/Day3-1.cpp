#include <iostream>
#include <fstream>

using namespace std;

void readInputToArray()
{
    //Creates an input file stream
    fstream in("input.in", fstream::in);

    std::string tobogganMapRow; //variable to hold input

    //Counters
    int treesHit{0};
    int xPos{28};
    char tree = '#';
    string myToboggan = "@";

    //Parser Loop
    while (in >> tobogganMapRow)
    {
        //std::cout << tobogganMapRow << "\n";
        xPos += 3;
        int xPosModulus = xPos % 31;

        if (tobogganMapRow[xPosModulus] == tree)
        {
            treesHit++;
        }
        tobogganMapRow.replace(xPosModulus, 1, myToboggan);
        std::cout << tobogganMapRow << "\n";
    }

    //Close the File Stream
    in.close();

    std::cout << treesHit;
}
int main()
{
    readInputToArray();
    return 0;
}