#include <iomanip>
#include <iostream>
#include <vector>

#include "attraction.h"

using namespace std;

int main() {
  cout << "\nATTRACTIONS IN LONDON" << endl;
  cout << "=====================" << endl
       << endl;

  // Attractions list in London
  vector<Attraction*> attractions;

  // Parks
  attractions.push_back(new Park("Regent Park", "0400", "2300"));
  attractions.push_back(new Park("James Park", "0930", "1945"));
  attractions.push_back(new Park("Green Park", "0000", "2345"));

  // Museums
  attractions.push_back(new Museum("Public Museum", "0900", "2100"));
  attractions.push_back(new Museum("Smith Museum", 20.00, "0915", "1530"));
  attractions.push_back(new Museum("British Museum", 3, "0900", "2100"));
  attractions.push_back(new Museum("History Museum", "0900", "2100"));
  attractions.push_back(new Museum("Science Museum", 15.45, "0900", "1800"));

  // Theatres
  attractions.push_back(new Theatre("St John Theatre", 10.20, "0600", "2230"));
  attractions.push_back(new Theatre("Apollo Theatre", 2.50, "0900", "1600"));
  attractions.push_back(new Theatre("Adelphi Theatre", 5, "0900", "1900"));
  attractions.push_back(new Theatre("Arts Theatre", 0.49, "0900", "1600"));

  vector<Attraction*>::iterator attrItr;

  // Open after given time
  string timeGiven = "1900";

  cout << "Attractions Open After " << timeGiven << endl;
  cout << "---------------------------" << endl;

  for (attrItr = attractions.begin(); attrItr < attractions.end(); attrItr++) {
    if ((*attrItr)->isOpenAfter(timeGiven)) {
      cout << setw(15) << left << (*attrItr)->getName() << " : Open Until ";
      cout << (*attrItr)->getClosingTime() << endl;
    }
  }

  cout << endl;

  // Cost less than
  double costGiven = 5;

  cout << "Attractions Cost Less than £" << 5 << endl;
  cout << "-----------------------------" << endl;

  for (attrItr = attractions.begin(); attrItr < attractions.end(); attrItr++) {
    if ((*attrItr)->getAdmittancePrice() == 0) {
      cout << setw(15) << left << (*attrItr)->getName() << " : Free" << endl;
    } else if ((*attrItr)->getAdmittancePrice() < costGiven) {
      cout << setw(15) << left << (*attrItr)->getName() << " : Only Costing £";
      cout << fixed << setprecision(2) << (*attrItr)->getAdmittancePrice() << endl;
    }
  }

  cout << endl;
}
