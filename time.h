#include <string>

using namespace std;

class Time {
 private:
  int hour;    // Hour
  int minute;  // Minute

  void setHour(int hh);
  void setMinute(int mm);

  string padTimePart(int tt);

  // Private default constructor
  Time();

 public:
  Time(string timeStr);
  Time(int hh, int mm);

  string getTime();

  bool isTimePassed(string compTime);
};
