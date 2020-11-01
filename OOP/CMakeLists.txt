cmake_minimum_required(VERSION 3.17)
project(OOP)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(OOP main.cpp Model/Field.cpp Model/Field.h Model/Cell.cpp Model/Cell.h Model/Player.cpp Model/Player.h Model/Object.cpp Model/Object.h Model/Point.h Controller/Controller.cpp Controller/Controller.h View/View.cpp View/View.h Model/Objects/CoinObject.h Model/Objects/CoinObject.cpp Model/Objects/ExitObject.h Model/Objects/ExitObject.cpp Model/Objects/EntranceObject.h Model/Objects/EntranceObject.cpp Model/Objects/BombObject.h Model/Objects/BombObject.cpp Model/Objects/TeleportObject.h Model/Objects/TeleportObject.cpp Model/Loggers/logger.cpp Model/Loggers/logger.h Model/Loggers/ConsolLogger.cpp Model/Loggers/ConsolLogger.h Model/Loggers/FileLogger.cpp Model/Loggers/FileLogger.h Model/Loggers/Publisher.cpp Model/Loggers/Publisher.h Model/Loggers/ObjectPublisher.cpp Model/Loggers/ObjectPublisher.h)

target_link_libraries(OOP sfml-graphics sfml-audio)