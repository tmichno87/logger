namespace SimpleLogger{
    unique_ptr<SimpleLogger> SimpleLogger::GetSimpleLogger(){
        if(instance == nullptr){
            instance = std::make_unique<SimpleLogger>();
        }   
        else{
            return instance;
        }
    }
}
