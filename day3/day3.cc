#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <vector>

using namespace std;

int main ()
{
    string line;
    ifstream myfile("input.txt");
    if (myfile.is_open())
    {
        vector<int> intCounter(5);
        while (getline(myfile, line))
        {
            bitset<5> b(line);
            for (int i=0;i<b.size();i++)
            {
                if (b.test(i))
                {
                    intCounter[i]++;
                }
            }
        }
        for (const auto &i : intCounter)
        {
            printf("setCounter: %d\n", i);
        }
    }
    myfile.close();
    return 0;
}