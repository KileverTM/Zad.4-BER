#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdint.h>
#include <vector>
#include <bitset>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <time.h>

using namespace std;
void createFile1(const std::string name, const int count, const char value)
{
    std::fstream f;
    f.open(name.c_str(), std::ios::binary | std::ios::out);
    for (int i = 0; i < count; i++)
    {
        f.write((char*)&value,1);
    }
    f.close();
}
//01010101
//01011111
int main()
{

createFile1("test1_file1.bin", 100, 0x55);
createFile1("test1_file2.bin", 100, 0x55);

createFile1("test2_file1.bin", 100, 0x55);
createFile1("test2_file2.bin", 100, 0x5F);

createFile1("test3_file1.bin", 420000000, 0x55);
createFile1("test3_file2.bin", 420000000, 0x50);




}


