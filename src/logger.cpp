#include <cstring>
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

void Logger::setColor(Level logLevel) {
  switch (logLevel) {
  case Level::Warning:
    strcpy(color, "33");
    break;
  case Level::Error:
    strcpy(color, "31");
    break;
  case Level::Message:
    strcpy(color, "37");
    break;
  }
}

void Logger::setLevelMessage(Level logLevel) {
  switch (logLevel) {
  case Level::Warning:
    strcpy(levelMessage, "WARNING");
    break;
  case Level::Error:
    strcpy(levelMessage, " ERROR ");
    break;
  case Level::Message:
    strcpy(levelMessage, "       ");
    break;
  }
}

void Logger::log(const char *message) {
  char timeBuffer[TIME_BUFFER_SIZE];
  formattedTime(timeBuffer);
  std::print("[{0}]: {1}\n", timeBuffer, message);
}

void Logger::log(const char *message, Level logLevel) {
  char timeBuffer[TIME_BUFFER_SIZE];
  formattedTime(timeBuffer);
  setColor(logLevel);
  setLevelMessage(logLevel);
  std::print("[{0}] \033[{1}m{2}\033[0m: {3}\n", timeBuffer, color,
             levelMessage, message);
}
} // namespace Logger
