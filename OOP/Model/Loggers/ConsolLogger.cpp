#include "ConsolLogger.h"

ConsolLogger::ConsolLogger(Player * player) {
    this->player_ = player;
    this->player_->registerLogger(this);
}

ConsolLogger::ConsolLogger(Publisher* publisher) {
    this->publisher_ = publisher;
    this->publisher_->registerLogger(this);
}
void ConsolLogger::update() {
    if(this->player_){
        std::cout << *(this->player_);
    }
    else if(this->publisher_ && this->publisher_->object!= nullptr){
        std::cout << *publisher_->object;
    }
}

void ConsolLogger::unsubscribe() {
    if(this->player_){
        player_->removeLogger(this);
    } else if(this->publisher_ && this->publisher_->object!= nullptr){
        publisher_->removeLogger(this);
    }
}

