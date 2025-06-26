#include "Striker.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
// set atribut Footballer dengan nilai default,
// set goalScore dan shotsOnTarget ke 0, dan playPosition ke "striker"
Striker::Striker(){
    goalScore = 0;
    shotsOnTarget = 0;
    playPosition = "striker";
}

// User-defined constructor
// parameter: string name, int birthYear, int goalScore, int shotsOnTarget
// set atribut dengan nilai parameter, playPosition tetap "striker"
// nationality, height, dan weight gunakan nilai default superclass
Striker::Striker(string _name, int _birthYear, int _goalScore, int _shotsOnTarget){
    name = _name;
    birthYear = _birthYear;
    goalScore = _goalScore;
    shotsOnTarget = _shotsOnTarget;
    playPosition = "striker";
}

// Getter dan Setter untuk goalScore
void Striker::setGoalScore(int _goalScore){
    goalScore = _goalScore;
}
int Striker::getGoalScore(){
    return goalScore;
}

// Getter dan Setter untuk shotsOnTarget
void Striker::setShotsOnTarget(int _shotsOnTarget){
    shotsOnTarget = _shotsOnTarget;
}
int Striker::getShotsOnTarget(){
    return shotsOnTarget;
}

// Method tambahan: menghitung conversion rate dalam persen
// conversionRate() = (goalScore / shotsOnTarget) * 100
// return dalam bentuk float
// Hint: Gunakan static_cast<float> untuk mengonversi int ke float
float Striker::conversionRate(){
    if (shotsOnTarget == 0){return 0.0f;}
    return (static_cast<float>(goalScore) / static_cast<float>(shotsOnTarget)) * 100;
}

// Override transferRate:
// rumus: 1.000.000 * goalScore + 10.000 * conversionRate()
// hasil berupa int
int Striker::transferRate() {
    return (1000000 * goalScore + 10000 * conversionRate());
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan striker (goalScore, conversionRate)
// Format:
// Goals: <goalScore>
// Conversion Rate: <conversionRate>%
void Striker::displayInfo(){
    Footballer::displayInfo();
    cout << "Goals: " << goalScore << endl;
    cout << "Conversion Rate: " <<  fixed << setprecision(2) <<  conversionRate() << "%" <<  endl;                                                  
}

// Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
// Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
// ...