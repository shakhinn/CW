#include "ObjectPublisher.h"
void ObjectPublisher::registerLogger(logger *log) {
    loggers.push_back(log);
}
void ObjectPublisher::removeLogger(logger *log) {
    loggers.remove(log);
}
void ObjectPublisher::notifyLogger(Object* obj) {
    object = obj;
    if(object!= nullptr) {
        for (auto log : loggers) {
            (*log).update();
        }
    }
}
