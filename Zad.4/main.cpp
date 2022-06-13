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
ofstream log;
log.open("log.txt", ios_base::app);
time_t czas;
    struct tm * ptr;
    time( & czas );
    ptr = localtime( & czas );
    char * data = asctime( ptr );

log <<data<<"  Uruchomieie programu"<<endl;





createFile1("test1_file1.bin", 100, 0x55);


    time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
    log<<data<<"  Stworzenie 1 pliku testowego"<<endl;
createFile1("test1_file2.bin", 100, 0x55);

    time( & czas );
    ptr = localtime( & czas );
    data = asctime( ptr );
    log<<data<<"  Stworzenie 2 pliku testowego"<<endl;

createFile1("test2_file1.bin", 100, 0x55);


    time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
    log<<data<<"  Stworzenie 3 pliku testowego"<<endl;
createFile1("test2_file2.bin", 100, 0x5F);


    time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
    log<<data<<"  Stworzenie 4 pliku testowego"<<endl;

createFile1("test3_file1.bin", 420000000, 0x55);


    time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
    log<<data<<"  Stworzenie 5 pliku testowego"<<endl;
createFile1("test3_file2.bin", 420000000, 0x50);


    time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
    log<<data<<"  Stworzenie 6 pliku testowego"<<endl;




}


