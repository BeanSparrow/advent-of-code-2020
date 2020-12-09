#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void inputLineRead()
{

    string line;

    string answerChecker1;
    string answerChecker2;

    //Counter
    int totalSumYes{0};
    int vectorCounter = 0;

    //Input Stream
    ifstream myFile("input.in");

    while (!myFile.eof())
    {
        getline(myFile, line);

        //If line is newline
        if (line.empty())
        {
            //Increase Counter
            totalSumYes += answerChecker2.length();

            //Reset Counter
            vectorCounter = 0;
        }
        else
        {

            if (vectorCounter == 0)
            {
                answerChecker2 = line;
                vectorCounter++;
            }
            else
            {
                answerChecker1 = answerChecker2;
                answerChecker2 = "";
                for (int i = 0; i < line.length(); i++)
                {
                    if (find(answerChecker1.begin(), answerChecker1.end(), line[i]) != answerChecker1.end())
                    {
                        answerChecker2.append(line, i, 1);
                    }
                }
            }
        }
    }
    //Report Result
    std::cout << totalSumYes;
}

int main()
{
    inputLineRead();
    return 0;
}