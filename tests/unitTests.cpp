#include <gtest/gtest.h>
#include "../StreamLoggerWriter.hpp"
#include "../SimpleLogger.hpp"

#include <sstream> 

//############### StreamLoggerWriterTests #####################

TEST(StreamLoggerWriterTests, createConsleNotThrowingExceptions)
{ 
    try {
        auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(std::cout); 
    }
    catch(...) {
        FAIL() << "Expected not to throw exception";
    }
}

TEST(StreamLoggerWriterTests, createStreamNotThrowingExceptions)
{ 
    try {
        std::stringstream ss;
        auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 
    }
    catch(...) {
        FAIL() << "Expected not to throw exception";
    }
}

TEST(StreamLoggerWriterTests, loggingDebugOk)
{ 
    // arrange
    std::string expectedVal = "[DEBUG] Test DEBUG";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 

    // act
    streamWriter->write(SimpleLogger::DEBUG, "Test DEBUG");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,18);

    // assert
    EXPECT_TRUE(logInfo.compare(expectedVal) == 0);
}

TEST(StreamLoggerWriterTests, loggingInfoOk)
{ 
    // arrange
    std::string expectedVal = "[INFO] Test INFO";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 

    // act
    streamWriter->write(SimpleLogger::INFO, "Test INFO");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,16);

    // assert
    EXPECT_TRUE(logInfo.compare(expectedVal) == 0);
}

TEST(StreamLoggerWriterTests, loggingWarningOk)
{ 
    // arrange
    std::string expectedVal = "[WARNING] Test WARNING";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 

    // act
    streamWriter->write(SimpleLogger::WARNING, "Test WARNING");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,22);

    // assert
    EXPECT_TRUE(logInfo.compare(expectedVal) == 0);
}

TEST(StreamLoggerWriterTests, loggingErrorOk)
{ 
    // arrange
    std::string expectedVal = "[ERROR] Test ERROR";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 

    // act
    streamWriter->write(SimpleLogger::ERROR, "Test ERROR");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,18);

    // assert
    EXPECT_TRUE(logInfo.compare(expectedVal) == 0);
}

//############### SimpleLoggerTests #####################
TEST(SimpleLoggerTests, createConsleNotThrowingExceptions)
{ 
    try {
        auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(std::cout); 
        auto logger = std::make_unique<SimpleLogger::SimpleLogger>(streamWriter);
    }
    catch(...) {
        FAIL() << "Expected not to throw exception";
    }
}

TEST(SimpleLoggerTests, createStreamNotThrowingExceptions)
{ 
    try {
        std::stringstream ss;
        auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 
        auto logger = std::make_unique<SimpleLogger::SimpleLogger>(streamWriter);
    }
    catch(...) {
        FAIL() << "Expected not to throw exception";
    }
}

TEST(SimpleLoggerTests, loggingDebugOk)
{ 
    // arrange
    std::string expectedVal = "[DEBUG] Test DEBUG";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(streamWriter);

    // act
    logger->writeLog(SimpleLogger::DEBUG, "Test DEBUG");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,18);

    // assert
    EXPECT_TRUE(logInfo.compare(expectedVal) == 0);
}

TEST(SimpleLoggerTests, loggingInfoOk)
{ 
    // arrange
    std::string expectedVal = "[INFO] Test INFO";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss);
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(streamWriter); 

    // act
    logger->writeLog(SimpleLogger::INFO, "Test INFO");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,16);

    // assert
    EXPECT_TRUE(logInfo.compare(expectedVal) == 0);
}

TEST(SimpleLoggerTests, loggingWarningOk)
{ 
    // arrange
    std::string expectedVal = "[WARNING] Test WARNING";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(streamWriter);

    // act
    logger->writeLog(SimpleLogger::WARNING, "Test WARNING");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,22);

    // assert
    EXPECT_TRUE(logInfo.compare(expectedVal) == 0);
}

TEST(SimpleLoggerTests, loggingErrorOk)
{ 
    // arrange
    std::string expectedVal = "[ERROR] Test ERROR";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(streamWriter);

    // act
    logger->writeLog(SimpleLogger::ERROR, "Test ERROR");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,18);

    // assert
    EXPECT_TRUE(logInfo.compare(expectedVal) == 0);
}

TEST(SimpleLoggerTests, lambdaWorksOk)
{ 
    // arrange
    std::string expectedVal = "TEST - custom log write";
    std::stringstream ss;
    std::string result = "";
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(streamWriter);
    auto logWriteLambda = [&result](SimpleLogger::LogLevel level, std::string message){
        result = "TEST - "+message;
    };

    // act
    logger->writeLog(SimpleLogger::DEBUG, "custom log write", logWriteLambda);

    // assert
    EXPECT_TRUE(result.compare(expectedVal) == 0);
}



int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}