#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void inputLineRead()
{
    string passportElements[8] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
    int elementArraySize = (*passportElements).size();

    string line;

    //Counters
    int passportElementCounter{0};
    bool countryIDCheck = false;
    int validCount{0};

    //Input Stream
    ifstream myFile("input.in");

    while (!myFile.eof())
    {
        getline(myFile, line);
        string passportElement = line.substr(0, 3);

        //If line is newline
        if (line.empty())
        {
            //Passport Requirements Check and Counter
            if ((passportElementCounter == 7 && !countryIDCheck) || (passportElementCounter == 8))
            {
                validCount++;
            }

            //Reset Counters
            passportElementCounter = 0;
            countryIDCheck = false;
        }
        else
        {
            passportElementCounter++;
            //Checks if Passport Element is "CID"
            if (passportElement == passportElements[7])
            {
                countryIDCheck = true;
            }
        }
    }

    //Report Valid Passport Count
    std::cout << validCount << endl;
}

int main()
{
    inputLineRead();
    return 0;
}