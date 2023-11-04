#include "time.h"

/**
 * ISO time constructor using time string
 *
 * @param timeStr Time string in HHMM format
 */
Time::Time(string timeStr) {
  try {
    setHour(stoi(timeStr.substr(0, 2)));
    setMinute(stoi(timeStr.substr(2, 2)));
  } catch (...) {
    throw "Time parsing failed for: " + timeStr;
  }
}

/**
 * ISO time constructor with hour and minute
 *
 * @param hh hour
 * @param mm minute
 */
Time::Time(int hh, int mm) {
  setHour(hh);
  setMinute(mm);
};

/**
 * Set validated value to hour
 *
 * @param hour
 *
 */
void Time::setHour(int hh) {
  if (hh >= 0 && hh <= 23) {
    hour = hh;
  } else {
    throw "Invalid hour: " + to_string(hh);
  }
}

/**
 * Set validated value to minute
 *
 * @param minute
 *
 */
void Time::setMinute(int mm) {
  if (mm >= 0 && mm <= 59) {
    minute = mm;
  } else {
    throw "Invalid hour: " + to_string(mm);
  }
}

/**
 * Get ISO time in HHMM format
 *
 * @return Time in
 */
string Time::getTime() {
  return padTimePart(hour) + padTimePart(minute);
};

/**
 * Util to leading zero to time part if necessary
 *
 * @param tt Time part
 * @return Padded time part
 */
string Time::padTimePart(int tt) {
  return (tt < 10 ? "0" : "") + to_string(tt);
}

/**
 * Checks if time has passed the given time
 *
 * @param compTimeStr Time string to compare in HHMM format
 * @return If time has passed
 */
bool Time::isTimePassed(string compTimeStr) {
  Time compTime(compTimeStr);

  if (hour > compTime.hour) {
    return true;
  } else if (hour == compTime.hour && minute > compTime.minute) {
    return true;
  }
  return false;
};
