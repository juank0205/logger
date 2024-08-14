#include <logger.hpp>

int main(int argc, char *argv[]) {
  Logger::Logger Log;
  const char *message{"First Log"};
  Log.log(message);
  return 0;
}
