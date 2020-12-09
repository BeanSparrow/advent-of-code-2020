#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void inputLineRead()
{
    std::vector<char> answeredYes;
    string line;

    //Counter
    int totalSumYes{0};

    //Input Stream
    ifstream myFile("input.in");

    while (!myFile.eof())
    {
        getline(myFile, line);

        //If line is newline
        if (line.empty())
        {
            //Increase Counter
            totalSumYes += answeredYes.size();

            //Reset Vector
            answeredYes.clear();
        }
        else
        {
            for(int i = 0; i < line.length(); i++){
                    //If question char already exists in answeredYes vector do nothing
                    if (find(answeredYes.begin(), answeredYes.end(), line[i]) == answeredYes.end())
                    {
                        answeredYes.push_back(line[i]);
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