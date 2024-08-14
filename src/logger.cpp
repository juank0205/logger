#include <ctime>
#include <logger.hpp>
#include <print>
#define TIME_BUFFER_SIZE 9

namespace Logger {
void Logger::formattedTime(char *buffer) {
  std::time_t actualTime = std::time(nullptr);
  struct tm *time_info;
  time(&actualTime);
  time_info = localtime(&actualTime);

  std::strftime(buffer, TIME_BUFFER_SIZE, "%H:%M:%S", time_info);
}

void Logger::log(const char *message) {
  char timeBuffer[TIME_BUFFER_SIZE];
  formattedTime(timeBuffer);
  std::print("[{0}]: {1}\n", timeBuffer, message);
}

void Logger::log(const char *message, Level logLevel){

}
} // namespace Logger
