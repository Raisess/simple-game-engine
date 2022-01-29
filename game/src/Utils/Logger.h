#pragma once

#include <iostream>

namespace Utils {

class Logger {
  public:
    static void log(std::string group, std::string message) {
      std::cout << "[" << group << "] " << message << std::endl;
    }

    static void error(std::string group, std::string message, std::string error) {
      message.append(error);
      Logger::log(group, message);
    }
};

}
