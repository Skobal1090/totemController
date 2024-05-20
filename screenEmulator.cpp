#include <iostream>
#include <windows.h>
#include <unistd.h>
using namespace std;

void printToScreen(){
    int i = 0;
    int seconds = 0;
    while(true){
        //Invokes system "CLS" command to wipe screen 
        system("CLS");
        cout << seconds <<flush;
        //usleep takes microseconds as an argument, we chose a refresh rate of 5hz
        usleep(200000);
        if (i % 5 == 0) seconds++;
        i++;
    }
}

int main() {
    printToScreen();
    return 0;
}