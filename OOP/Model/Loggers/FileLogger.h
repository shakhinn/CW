//
// Created by shakhinn on 31.10.2020.
//

#ifndef OOP_FILELOGGER_H
#define OOP_FILELOGGER_H
#include "logger.h"
#include "../Player.h"
#include "Publisher.h"

class FileLogger: public logger {
private:
    std::ofstream* fileStream = nullptr;
    std::ofstream* fileStream2 = nullptr;
public:
    explicit FileLogger(Player* player, std::string filename);

    explicit FileLogger(Publisher* publisher, std::string filename);

    void update() override;

    void unsubscribe() override;

    ~FileLogger() override;

};


#endif //OOP_FILELOGGER_H
