#ifndef STRIKER_HPP
#define STRIKER_HPP

#include "Footballer.hpp"

class Striker : public Footballer
{
protected:
  // atribut tambahan goalScore (jumlah gol yang dicetak striker)
  // dan shotsOnTarget (jumlah tendangan tepat sasaran)
  int goalScore;
  int shotsOnTarget;

public:
  // Default constructor
  // set atribut Footballer dengan nilai default,
  // set goalScore dan shotsOnTarget ke 0, dan playPosition ke "striker"
  Striker();

  // User-defined constructor
  // parameter: string name, int birthYear, int goalScore, int shotsOnTarget
  // set atribut dengan nilai parameter, playPosition tetap "striker"
  // nationality, height, dan weight gunakan nilai default superclass
  Striker(string _name, int _birthYear, int _goalScore, int _shotsOnTarget);

  // Getter dan Setter untuk goalScore
  void setGoalScore(int _goalScore);
  int getGoalScore();

  // Getter dan Setter untuk shotsOnTarget
  void setShotsOnTarget(int _shotsOnTarget);
  int getShotsOnTarget();

  // Method tambahan: menghitung conversion rate dalam persen
  // conversionRate() = (goalScore / shotsOnTarget) * 100
  // return dalam bentuk float
  // Hint: Gunakan static_cast<float> untuk mengonversi int ke float
  float conversionRate();

  // Override transferRate:
  // rumus: 1.000.000 * goalScore + 10.000 * conversionRate()
  // hasil berupa int
  int transferRate();

  // Override displayInfo():
  // Cetak info Footballer + atribut tambahan striker (goalScore, conversionRate)
  // Format:
  // Goals: <goalScore>
  // Conversion Rate: <conversionRate>%
  void displayInfo();

  // Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
  // Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
  // ...
};

#endif
