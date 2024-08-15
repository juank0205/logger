#pragma once
#define COLOR_BUFFER_SIZE 5
#define LEVEL_BUFFER_SIZE 7

namespace Logger {
enum class Level { Error, Warning, Message };

class Logger {

public:
  void log(const char *message);
  void log(const char *message, Level logLevel);

private:
  char color[COLOR_BUFFER_SIZE];
  char levelMessage[LEVEL_BUFFER_SIZE];
  void formattedTime(char *buffer);
  void setColor(Level logLevel);
  void setLevelMessage(Level logLevel);
};
} // namespace Logger
