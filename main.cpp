#include <logger.hpp>

int main(int argc, char *argv[]) {
  Logger::Logger Log;
  const char *message{"First Log"};
  Log.log(message);
  Log.log(message, Logger::Level::Message);
  Log.log(message, Logger::Level::Error);
  Log.log(message, Logger::Level::Warning);
  return 0;
}
