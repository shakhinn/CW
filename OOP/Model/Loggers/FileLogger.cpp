#include "FileLogger.h"

FileLogger::FileLogger(Player *player, std::string  filename) {
    this->player_ = player;
    player_->registerLogger(this);
    fileStream = new std::ofstream (filename, std::ofstream::out);
    if(!fileStream){
        throw std::runtime_error("file open stream");
    }
    *fileStream << *player;
}

FileLogger::FileLogger(Publisher* publisher, std::string filename) {
    this->publisher_ = publisher;
    publisher_->registerLogger(this);
    fileStream2 = new std::ofstream (filename, std::ofstream::out | std::ostream::app);
    if(!fileStream2){
        throw std::runtime_error("file open stream");
    }
   // *fileStream2 << *(publisher->object);
}

void FileLogger::update(){
    if(player_!= nullptr){
        *fileStream << *player_;
    }if( publisher_ != nullptr){
        *fileStream2 << *(publisher_->object);
    }
}

void FileLogger::unsubscribe() {
    if(player_ != nullptr){
        player_->removeLogger(this);
    }
    if(publisher_ != nullptr){
        publisher_->removeLogger(this);
    }
}


FileLogger::~FileLogger() {
    if(fileStream != nullptr) {
        fileStream->close();
        delete fileStream;
    }
    if(fileStream2 != nullptr) {
        fileStream2->close();
        delete fileStream2;
    }
}