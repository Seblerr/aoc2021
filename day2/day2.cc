#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line;
    ifstream myfile("input.txt");
    auto x = 0;
    auto y1 = 0;
    auto y2 = 0;

    if (myfile.is_open())
    {
        auto aim = 0;
        while (getline(myfile, line))
        {
            auto direction = line.substr(0, line.find(" "));
            auto amount = atoi(line.substr(line.find(" ")).c_str());
            if (direction == "forward")
            {
                x += amount;
                y2 += amount * aim;
            }
            else if (direction == "down")
            {
                y1 += amount;
                aim += amount;
            }
            else
            {
                y1 -= amount;
                aim -= amount;
            }
        }
    }
    myfile.close();

    printf("Part 1: x:%d, y:%d, product:%d\n", x, y1, x * y1);
    printf("Part 2: x:%d, y:%d, product:%d\n", x, y2, x * y2);

    return 0;
}
