#pragma once

namespace Logger {
enum class Level { Error, Warning, Message };

class Logger {
public:
  void log(const char *message);
  void log(const char *message, Level logLevel);

private:
  void formattedTime(char *buffer);
  void setColor(Level logLevel);
};
} // namespace Logger
