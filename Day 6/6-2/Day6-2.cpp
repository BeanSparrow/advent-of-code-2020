#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void inputLineRead()
{
    std::vector<vector<char>> answeredYes;
    string line;

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
            totalSumYes += answeredYes[vectorCounter].size();

            //Reset Vector and counter
            answeredYes.clear();
            //vectorCounter = 0;
        }
        else
        {
            for(int i = 0; i < line.length(); i++)
            {
                    if(vectorCounter == 0)
                    {
                        //answeredYes[vectorCounter].push_back(line[i]);
                        std::cout << line[i] << endl;
                    }
            //         else
            //         {
            //             if(find(answeredYes[vectorCounter].begin(), answeredYes[vectorCounter].end(), line[i]) != answeredYes[vectorCounter].end())
            //             {
            //                 answeredYes[vectorCounter + 1].push_back(line[i]);
            //             }
            //         }
            // vectorCounter++;
            }
        //std::cout << vectorCounter << endl;
        }   

    //Report Result
    //std::cout << totalSumYes;
    }
}


int main()
{
    inputLineRead();
    return 0;
}