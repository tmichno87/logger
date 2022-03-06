namespace SimpleLogger{
    #include <memory>

        class SimpleLogger{
            public:
                static std::unique_ptr<SimpleLogger> GetSimpleLogger();
                virtual ~SimpleLogger() = default;

            private:
                SimpleLogger() = default;

                static std::unique_ptr<SimpleLogger> instance = nullptr;
        };
}