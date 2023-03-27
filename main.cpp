#include <iostream>
#include <vector>
#include <cstdlib>



void calculate(std::vector<std::vector<unsigned long long>>&, int);
void write(std::vector<std::vector<unsigned long long>>&);



int main(int argc, char *argv[])
{
    std::vector<std::vector<unsigned long long>> triangle;

    if (argc == 2)
    {
        int n = atoi(argv[1]);

        if (n == 0)
        {
            std::cout << "Invalid value" << std::endl;
        }
        else
        {
            calculate(triangle, n);
            write(triangle);
        }
    }
    else
    {
        std::cout << "Invalid Argument count" << std::endl;
    }

    return 0;
}



void calculate(std::vector<std::vector<unsigned long long>> &triangle, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            std::vector<unsigned long long> newLine;
            newLine.push_back(1);
            triangle.push_back(newLine);
        }
        else
        {
            std::vector<unsigned long long> newLine;

            for (int i2 = 0; i2 < i + 1; i2++)
            {
                if (i2 == 0 || i2 == i)
                {
                    newLine.push_back(1);
                }
                else
                {
                    newLine.push_back(triangle[i - 1][i2 - 1] + triangle[i - 1][i2]);
                }
            }

            triangle.push_back(newLine);
        }
    }
}



void write(std::vector<std::vector<unsigned long long>> &triangle)
{
    for (size_t i = 0; i < triangle.size(); i++)
    {
        for (size_t i2 = 0; i2 < triangle[i].size(); i2++)
        {
            std::cout << triangle[i][i2] << " ";
        }

        std::cout << std::endl;
    }
}