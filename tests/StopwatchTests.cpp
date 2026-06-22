#include <gtest/gtest.h>

#include <thread>
#include <chrono>

#include "Stopwatch/Stopwatch.h"



using namespace std::chrono_literals;



//
// Stopwatch Tests
//

TEST(StopwatchTests, StartsAtZero)
{
    jTools::Stopwatch sw;

    EXPECT_EQ(
        sw.toDuration().count(),
        0
    );
}



TEST(StopwatchTests, MeasuresElapsedTime)
{
    jTools::Stopwatch sw;


    sw.start();


    std::this_thread::sleep_for(
        50ms
    );


    sw.stop();



    auto elapsed = sw.toDuration().count();



    EXPECT_GE(
        elapsed,
        40
    );


    EXPECT_LT(
        elapsed,
        200
    );
}



TEST(StopwatchTests, PauseAndResumeWorks)
{
    jTools::Stopwatch sw;


    sw.start();

    std::this_thread::sleep_for(
        30ms
    );

    sw.stop();


    auto first =
        sw.toDuration();



    sw.start();


    std::this_thread::sleep_for(
        30ms
    );


    sw.stop();



    auto second =
        sw.toDuration();



    EXPECT_GT(
        second.count(),
        first.count()
    );
}



TEST(StopwatchTests, ResetClearsTimer)
{
    jTools::Stopwatch sw;


    sw.start();

    std::this_thread::sleep_for(
        20ms
    );

    sw.stop();


    sw.reset();



    EXPECT_EQ(
        sw.toDuration().count(),
        0
    );
}



TEST(StopwatchTests, VerboseFormatting)
{
    jTools::Stopwatch sw;


    auto result =
        sw.toString(true);



    EXPECT_EQ(
        result,
        "00:00:00.000"
    );
}



TEST(StopwatchTests, MultipleTimersAreIndependent)
{
    jTools::Stopwatch a;
    jTools::Stopwatch b;


    a.start();

    std::this_thread::sleep_for(
        20ms
    );

    a.stop();



    EXPECT_EQ(
        b.toDuration().count(),
        0
    );
}




//
// RunRecorder Tests
//


TEST(RunRecorderTests, StartsEmpty)
{
    jTools::RunRecorder recorder("test");


    EXPECT_EQ(
        recorder.getRuns().size(),
        0
    );
}



TEST(RunRecorderTests, RecordsSingleRun)
{
    jTools::RunRecorder recorder("test");


    recorder.start();


    std::this_thread::sleep_for(
        20ms
    );


    recorder.stop();


    recorder.reset();



    EXPECT_EQ(
        recorder.getRuns().size(),
        1
    );
}



TEST(RunRecorderTests, SumMatchesRuns)
{
    jTools::RunRecorder recorder("test");


    recorder.start();

    std::this_thread::sleep_for(
        20ms
    );

    recorder.stop();

    recorder.reset();



    recorder.start();

    std::this_thread::sleep_for(
        20ms
    );

    recorder.stop();

    recorder.reset();



    auto total =
        recorder.Sum().count();



    EXPECT_GE(
        total,
        30
    );
}



TEST(RunRecorderTests, AverageIsCorrect)
{
    jTools::RunRecorder recorder("test");


    recorder.start();
    std::this_thread::sleep_for(20ms);
    recorder.stop();

    recorder.reset();



    recorder.start();
    std::this_thread::sleep_for(20ms);
    recorder.stop();

    recorder.reset();



    auto average =
        recorder.Average().count();



    EXPECT_GE(
        average,
        10
    );
}



TEST(RunRecorderTests, EmptyAverageReturnsZero)
{
    jTools::RunRecorder recorder("test");


    EXPECT_EQ(
        recorder.Average().count(),
        0
    );
}



//
// Operator Tests
//


TEST(OperatorTests, StopwatchAddition)
{
    jTools::Stopwatch a;
    jTools::Stopwatch b;


    a.start();
    std::this_thread::sleep_for(20ms);
    a.stop();



    b.start();
    std::this_thread::sleep_for(20ms);
    b.stop();



    auto c =
        a + b;



    EXPECT_GT(
        c.toDuration().count(),
        30
    );
}



TEST(OperatorTests, StopwatchSubtractionCannotGoNegative)
{
    jTools::Stopwatch a;
    jTools::Stopwatch b;



    b.start();
    std::this_thread::sleep_for(20ms);
    b.stop();



    auto result =
        a - b;



    EXPECT_EQ(
        result.toDuration().count(),
        0
    );
}