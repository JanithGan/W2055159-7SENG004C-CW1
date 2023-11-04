#include "time.h"

using namespace std;

class Attraction {
 private:
  // Private default constructor
  Attraction();

 protected:
  string name;             // Attraction name
  double admittancePrice;  // Admittance price
  Time* openingTime;       // Opening time
  Time* closingTime;       // Closing time

  /**
   * Attraction constructor (protected)
   *
   * @param nm Attraction name
   * @param ot Opening time
   * @param ct Closing time
   */
  Attraction(string nm, string ot, string ct) {
    name = nm;
    openingTime = new Time(ot);
    closingTime = new Time(ct);
  }

 public:
  /**
   * Get name of the attraction
   *
   * @return Attraction name
   */
  string getName() {
    return name;
  };

  /**
   * Get admittance price of the attraction
   *
   * @return Admittance price
   */
  double getAdmittancePrice() {
    return admittancePrice;
  };

  /**
   * Get opening time of the attraction
   *
   * @return Opening time
   */
  string getOpeningTime() {
    return openingTime->getTime();
  };

  /**
   * Get closing time of the attraction
   *
   * @return Closing time
   */
  string getClosingTime() {
    return closingTime->getTime();
  }

  /**
   * Checks if the attraction is open after the given time
   *
   * @param timeStr Time string given in HHMM format
   * @return If the attraction is open
   */
  bool isOpenAfter(string timeStr) {
    return closingTime->isTimePassed(timeStr);
  }
};

class Park : public Attraction {
 public:
  /**
   * Park constructor
   *
   * @param nm Park name
   * @param ot Opening time
   * @param ct Closing time
   */
  Park(string nm, string ot, string ct) : Attraction(nm, ot, ct) {
    admittancePrice = 0;
  };
};

class Museum : public Attraction {
 public:
  /**
   * Museum constructor
   *
   * @param nm Museum name
   * @param ap Admittance price (Zero if free)
   * @param ot Opening time
   * @param ct Closing time
   */
  Museum(string nm, double ap, string ot, string ct) : Attraction(nm, ot, ct) {
    admittancePrice = ap;
  };

  /**
   * Museum with free admittance constructor
   *
   * @param nm Museum name
   * @param ot Opening time
   * @param ct Closing time
   */
  Museum(string nm, string ot, string ct) : Attraction(nm, ot, ct) {
    admittancePrice = 0;
  };
};

class Theatre : public Attraction {
 public:
  /**
   * Theatre constructor
   *
   * @param nm Theatre name
   * @param ap Admittance price
   * @param ot Opening time
   * @param ct Closing time
   */
  Theatre(string nm, double ap, string ot, string ct) : Attraction(nm, ot, ct) {
    admittancePrice = ap;
  };
};
