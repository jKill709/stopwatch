#include <iostream>

#include "Stopwatch/Stopwatch.h"


int main()
{
    Stopwatch sw;


    std::cout 
        << "Starting timer...\n";


    sw.start();


    for(volatile int i=0;i<100000000;i++)
    {
        // simulate work
    }


    sw.stop();



    std::cout 
        << "Elapsed: "
        << sw.toString(true)
        << "\n";


    RunRecorder recorder("Test");


    recorder.start();


    for(volatile int i=0;i<50000000;i++)
    {

    }


    recorder.stop();

    recorder.reset();



    std::cout
        << "Average: "
        << recorder.Average().count()
        << " ms\n";


    return 0;
}