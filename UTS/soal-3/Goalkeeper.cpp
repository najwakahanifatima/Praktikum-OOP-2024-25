#include "Goalkeeper.hpp"
#include <iostream>

// Default constructor
// set atribut Footballer dengan nilai default,
// set cleanSheets, saves, totalShotsOnGoal ke 0, playPosition ke "goalkeeper"
Goalkeeper::Goalkeeper(){
    cleanSheets = 0;
    saves = 0;
    totalShotsOnGoal = 0;
    playPosition = "goalkeeper";
}

// User-defined constructor
// parameter: string name, int birthYear, int cleanSheets, int saves, int totalShotsOnGoal
// set atribut dengan nilai parameter, playPosition tetap "goalkeeper"
// nationality, height, dan weight gunakan nilai default superclass
Goalkeeper::Goalkeeper(string _name, int _birthYear, int _cleanSheets, int _saves, int _totalShotsOnGoal){
    name = _name;
    birthYear = _birthYear;
    playPosition = "goalkeeper";
    cleanSheets = _cleanSheets;
    saves = _saves;
    totalShotsOnGoal = _totalShotsOnGoal;
}

// Getter dan Setter untuk cleanSheets
void Goalkeeper::setCleanSheets(int _cleanSheets){
    cleanSheets = _cleanSheets;
}
int Goalkeeper::getCleanSheets(){
    return cleanSheets;
}

// Getter dan Setter untuk saves
void Goalkeeper::setSaves(int _saves){
    saves = _saves;
}
int Goalkeeper::getSaves(){
    return saves;
}

// Getter dan Setter untuk totalShotsOnGoal
void Goalkeeper::setTotalShotsOnGoal(int _totalShotsOnGoal){
    totalShotsOnGoal = _totalShotsOnGoal;
}
int Goalkeeper::getTotalShotsOnGoal(){
    return totalShotsOnGoal;
}

// Method tambahan: savePercentage
// rumus: (saves / totalShotsOnGoal) * 100
// return dalam bentuk float
float Goalkeeper::savePercentage(){
    if (totalShotsOnGoal == 0) {return 0.0f;}
    return (static_cast<float>(saves) / totalShotsOnGoal) * 100;
}

// Override transferRate:
// rumus: (700.000 * cleanSheets) + (50.000 * saves)
// hasil berupa int
int Goalkeeper::transferRate(){
    return (700000 * cleanSheets) + (50000 * saves);
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan goalkeeper (cleanSheets, saves, savePercentage)
// Format:
// Clean Sheets: <cleanSheets>
// Saves: <saves>
// Save Percentage: <savePercentage>%
void Goalkeeper::displayInfo(){
    Footballer::displayInfo();
    cout << "Clean Sheets: " << cleanSheets << endl;
    cout << "Saves: " << saves << endl;
    cout << "Save Percentage: " << savePercentage() << "%" << endl;
}