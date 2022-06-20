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
#include <ctype.h>
#include <unistd.h>

using namespace std;
using namespace std::chrono;
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

uint8_t hammingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2;
    uint8_t setBits = 0;
    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }
    return setBits;
}

void calculateBer(const char* test1_file1, const char* test1_file2)
{
    ifstream f1 (test1_file1,std::ios::binary );
    ifstream f2 (test1_file2,std::ios::binary );
    ofstream log;
    clock_t start,stop;
    double timeLicz;
log.open("log.txt", ios_base::app);
    time_t czas;
    struct tm * ptr;
    time( & czas );
    ptr = localtime( & czas );
    char * data = asctime( ptr );
    log<<data<<"uruchomienie funkcji liczacej ERROR "<<endl;
    float resultst1 = 0;
   float resultst2 = 0;
  float  resultsber = 0;
   float resultserr = 0;
   float resultstot = 0;



 time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
     log<<endl;
log<<data<<"Otwarcie pierwszego pliku "<<endl;

    time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
     log<<endl;
     log<<data<<"Otwarcie drugiego pliku "<<endl;

    char a{};
    char b{};

start = clock();

    while (!f1.eof())
    {
        f1 >> a; //read 1 char from file 1
        f2 >> b; //read 1 char from file 2

        if (f1.eof()) {break;} // till the end of the 1st file

            resultserr += hammingDistance(a, b); //add to the .err the number of different bits

            resultstot += 8; //add to the .tot the number of compared bits

    }
stop = clock();

time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
     log<<endl;

    resultsber = resultserr / resultstot; // calculate ber
log<<data<<" Wynik BER: "<<resultsber<<endl;
cout<<"Wynik BER : "<<resultsber<<endl;
log<<data<<"Iosc porownanych bitow : "<<resultstot<<endl;
cout<<"Iosc porownanych bitow : "<<resultstot<<endl;
log<<data<<"Iosc blednych bitow : "<<resultserr<<endl;
cout<<"Iosc blednych bitow : "<<resultserr<<endl;


timeLicz =(double)(stop-start)/ CLOCKS_PER_SEC;
log<<data<<" Czas wymagany na polieczenie bledu : "<<timeLicz<<endl;
cout<<" Czas wymagany na polieczenie bledu : "<<timeLicz<<setprecision(9)<<endl;
cout<<endl;
}


int main()
{
ofstream log;
log.open("log.txt", ios_base::app);
time_t czas;
    struct tm * ptr;
    time( & czas );
    ptr = localtime( & czas );
    char * data = asctime( ptr );

log <<data<<":  Uruchomieie programu"<<endl;

createFile1("test1_file1.bin", 100, 0x55);
    time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
     log<<endl;
     cout<<"Stworzenie pliku 1"<<endl;
    log<<data<<":  Stworzenie 1 pliku testowego"<<endl;
createFile1("test1_file2.bin", 100, 0x55);

    time( & czas );
    ptr = localtime( & czas );
    data = asctime( ptr );
    log<<endl;
    cout<<"Stworzenie pliku 2"<<endl;
    log<<data<<":  Stworzenie 2 pliku testowego"<<endl;
createFile1("test2_file1.bin", 100, 0x55);


    time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
     log<<endl;
     cout<<"Stworzenie pliku 3"<<endl;
    log<<data<<"  Stworzenie 3 pliku testowego"<<endl;
createFile1("test2_file2.bin", 100, 0x5F);


    time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
     log<<endl;
     cout<<"Stworzenie pliku 4"<<endl;
    log<<data<<"  Stworzenie 4 pliku testowego"<<endl;



createFile1("test3_file1.bin", 419430400, 0x55);
    time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
     log<<endl;
     cout<<"Stworzenie pliku 5"<<endl;
    log<<data<<"  Stworzenie 5 pliku testowego"<<endl;



createFile1("test3_file2.bin", 419430400, 0x50);
    time( & czas );
    ptr = localtime( & czas );
     data = asctime( ptr );
     log<<endl;
     cout<<"Stworzenie pliku 6"<<endl;
    log<<data<<"  Stworzenie 6 pliku testowego"<<endl;

calculateBer("test1_file1.bin","test1_file2.bin");
calculateBer("test2_file1.bin","test2_file2.bin");
calculateBer("test3_file1.bin","test3_file2.bin");

}


