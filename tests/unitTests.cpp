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
    std::string expectedVal = "[DEBUG] Test DEBUG\n";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 

    // act
    streamWriter->write("[DEBUG] Test DEBUG");

    // assert
    auto val = ss.str();
    ASSERT_EQ(val, expectedVal);
}

TEST(StreamLoggerWriterTests, loggingInfoOk)
{ 
    // arrange
    std::string expectedVal = "[INFO] Test INFO\n";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 

    // act
    streamWriter->write("[INFO] Test INFO");

    // assert
    ASSERT_EQ(ss.str(), expectedVal);
}

TEST(StreamLoggerWriterTests, loggingWarningOk)
{ 
    // arrange
    std::string expectedVal = "[WARNING] Test WARNING\n";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 

    // act
    streamWriter->write("[WARNING] Test WARNING");

    // assert
    ASSERT_EQ(ss.str(), expectedVal);
}

TEST(StreamLoggerWriterTests, loggingErrorOk)
{ 
    // arrange
    std::string expectedVal = "[ERROR] Test ERROR\n";
    std::stringstream ss;
    auto streamWriter = std::make_shared<SimpleLogger::StreamLoggerWriter>(ss); 

    // act
    streamWriter->write("[ERROR] Test ERROR");

    // assert
    ASSERT_EQ(ss.str(), expectedVal);
}

//############### SimpleLoggerTests #####################
TEST(SimpleLoggerTests, createConsleNotThrowingExceptions)
{ 
    try {
        auto streamWriter = std::make_unique<SimpleLogger::StreamLoggerWriter>(std::cout); 
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(SimpleLogger::DEBUG, std::move(streamWriter));
    }
    catch(...) {
        FAIL() << "Expected not to throw exception";
    }
}

TEST(SimpleLoggerTests, createStreamNotThrowingExceptions)
{ 
    try {
        std::stringstream ss;
        auto streamWriter = std::make_unique<SimpleLogger::StreamLoggerWriter>(ss); 
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(SimpleLogger::DEBUG, std::move(streamWriter));
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
    auto streamWriter = std::make_unique<SimpleLogger::StreamLoggerWriter>(ss); 
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(SimpleLogger::DEBUG, std::move(streamWriter));

    // act
    logger->writeLog(SimpleLogger::DEBUG, "Test DEBUG");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,18);

    // assert
    ASSERT_EQ(logInfo, expectedVal);
}

TEST(SimpleLoggerTests, loggingInfoOk)
{ 
    // arrange
    std::string expectedVal = "[INFO] Test INFO";
    std::stringstream ss;
    auto streamWriter = std::make_unique<SimpleLogger::StreamLoggerWriter>(ss);
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(SimpleLogger::DEBUG, std::move(streamWriter)); 

    // act
    logger->writeLog(SimpleLogger::INFO, "Test INFO");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,16);

    // assert
    ASSERT_EQ(logInfo, expectedVal);
}

TEST(SimpleLoggerTests, loggingWarningOk)
{ 
    // arrange
    std::string expectedVal = "[WARNING] Test WARNING";
    std::stringstream ss;
    auto streamWriter = std::make_unique<SimpleLogger::StreamLoggerWriter>(ss); 
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(SimpleLogger::DEBUG, std::move(streamWriter));

    // act
    logger->writeLog(SimpleLogger::WARNING, "Test WARNING");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,22);

    // assert
    ASSERT_EQ(logInfo, expectedVal);
}

TEST(SimpleLoggerTests, loggingErrorOk)
{ 
    // arrange
    std::string expectedVal = "[ERROR] Test ERROR";
    std::stringstream ss;
    auto streamWriter = std::make_unique<SimpleLogger::StreamLoggerWriter>(ss); 
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(SimpleLogger::DEBUG, std::move(streamWriter));

    // act
    logger->writeLog(SimpleLogger::ERROR, "Test ERROR");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo = ss.str().substr (38,18);

    // assert
    ASSERT_EQ(logInfo, expectedVal);
}

TEST(SimpleLoggerTests, lambdaWorksOk)
{ 
    // arrange
    std::string expectedVal = "TEST - custom log write";
    std::stringstream ss;
    std::string result = "";
    auto streamWriter = std::make_unique<SimpleLogger::StreamLoggerWriter>(ss); 
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(SimpleLogger::DEBUG, std::move(streamWriter));
    auto logWriteLambda = [&result](SimpleLogger::LogLevel level, std::string message){
        result = "TEST - "+message;
    };

    // act
    logger->writeLog(SimpleLogger::DEBUG, "custom log write", logWriteLambda);

    // assert
    EXPECT_TRUE(result.compare(expectedVal) == 0);
}

TEST(SimpleLoggerTests, multipleWritersOk)
{ 
    // arrange
    std::string expectedVal = "[ERROR] Test ERROR";
    std::stringstream ss1;
    std::stringstream ss2;
    std::stringstream ss3;
    auto streamWriter1 = std::make_unique<SimpleLogger::StreamLoggerWriter>(ss1); 
    auto streamWriter2 = std::make_unique<SimpleLogger::StreamLoggerWriter>(ss2); 
    auto streamWriter3 = std::make_unique<SimpleLogger::StreamLoggerWriter>(ss3); 
    auto logger = std::make_unique<SimpleLogger::SimpleLogger>(SimpleLogger::DEBUG, std::move(streamWriter1), std::move(streamWriter2), std::move(streamWriter3));

    // act
    logger->writeLog(SimpleLogger::ERROR, "Test ERROR");
    // should return something like that:
    // TIME: #THREAD_ID [DEBUG] Test DEBUG
    // we should check only the last part:
    auto logInfo1 = ss1.str().substr (38,18);
    auto logInfo2 = ss2.str().substr (38,18);
    auto logInfo3 = ss3.str().substr (38,18);

    // assert
    ASSERT_EQ(logInfo1, expectedVal);
    ASSERT_EQ(logInfo2, expectedVal);
    ASSERT_EQ(logInfo3, expectedVal);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}