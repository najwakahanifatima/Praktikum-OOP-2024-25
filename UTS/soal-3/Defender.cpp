#include "Defender.hpp"
#include <iostream>

using namespace std;

// Default constructor
// set atribut Footballer dengan nilai default,
// set tackleSuccess dan interceptions ke 0, dan playPosition ke "defender"
Defender::Defender(){
    interceptions = 0;
    tackleSuccess = 0;
    playPosition = "defender";
}

// User-defined constructor
// parameter: string name, int birthYear, int tackleSuccess, int interceptions
// set atribut dengan nilai parameter, playPosition tetap "defender"
// nationality, height, dan weight gunakan nilai default superclass
Defender::Defender(string _name, int _birthYear, int _tackleSuccess, int _interceptions){
    name = _name;
    birthYear = _birthYear;
    tackleSuccess = _tackleSuccess;
    interceptions = _interceptions;
    playPosition = "defender";
}

// Getter dan Setter untuk tackleSuccess
void Defender::setTackleSuccess(int _tackleSuccess){
    tackleSuccess = _tackleSuccess;
}
int Defender::getTackleSuccess(){
    return tackleSuccess;
}

// Getter dan Setter untuk interceptions
void Defender::setInterceptions(int _interceptions){
    interceptions = _interceptions;
}
int Defender::getInterceptions(){
    return interceptions;
}

// Method tambahan: defensiveRating
// rumus: (tackleSuccess * 2) + interceptions
// return dalam bentuk int
int Defender::defensiveRating(){
    return (tackleSuccess * 2) + interceptions;
}

// Override transferRate:
// rumus: (600.000 * tackleSuccess) + (400.000 * interceptions)
// hasil berupa int
int Defender::transferRate(){
    return (600000 * tackleSuccess) + (400000 * interceptions);
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan defender (tackleSuccess, interceptions, defensiveRating)
// Format:
// Tackle Success: <tackleSuccess>
// Interceptions: <interceptions>
// Defensive Rating: <defensiveRating>
void Defender::displayInfo(){
    Footballer::displayInfo();
    cout << "Tackle Success: " << tackleSuccess << endl;
    cout << "Interceptions: " << interceptions << endl;
    cout << "Defensive Rating: " << defensiveRating() << endl;
}