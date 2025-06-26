#include "Pet.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "PetShelter.hpp"
#include <iostream>
#include <string>
#include <sstream>

template <typename T>
PetShelter<T>::PetShelter(std::string shelterName){
    this->shelterName = shelterName;
    dogCapacity = 8;
    catCapacity = 12;
    currentCats = 0;
    currentDogs = 0;
    petCount = 0;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        pets[i] = nullptr;
    }
}
/* Default constructor:
    * - Creates a shelter with the given name.
    * - Default capacity: 8 dogs, 12 cats.
    * - No pets in the shelter initially.
    */

template <typename T>
PetShelter<T>::PetShelter(std::string shelterName, int dogCapacity, int catCapacity){
    if (dogCapacity + catCapacity > MAX_SHELTER_CAPACITY){
        std::cout << "The total capacity you construct is " << dogCapacity + catCapacity << ", meanwhile the shelter capacity is 20" << std::endl;
    }
    this->shelterName = shelterName;
    this->dogCapacity = dogCapacity;
    this->catCapacity = catCapacity;
    currentCats = 0;
    currentDogs = 0;
    petCount = 0;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        pets[i] = nullptr;
    }
}
/* Constructor with specified capacities:
    * - Creates a shelter with custom capacities for dogs and cats.
    * - If total capacity exceeds MAX_SHELTER_CAPACITY, prints:
    *   "The total capacity you construct is <total>, meanwhile the shelter capacity is 20"
    */

template <typename T>
PetShelter<T>::~PetShelter() {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        delete pets[i];
        pets[i] = nullptr;
    }
}
/* Destructor:
    * - Cleans up all dynamically allocated pets.
    * - Sets pet pointers to nullptr after deletion.
    */

template <typename T>
std::string PetShelter<T>::getShelterName() const {
    return shelterName;
}
/* Returns the name of the shelter.
    * Output: Shelter name as a string.
    */

template <typename T>
void PetShelter<T>::addPet(const std::string &petName, int age, bool isDog, const std::string &extraInfo){
    if (petCount == MAX_SHELTER_CAPACITY) {
        std::cout << "Error: Shelter is at full capacity!" << std::endl;
    } else if (isDog && currentDogs == dogCapacity) {
        std::cout << "Error: No space for more dogs!" << std::endl;
    } else if (!isDog && currentCats == catCapacity) {
        std::cout << "Error: No space for more cats!" << std::endl;
    } else {
        int index = -1;
        for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
            if (pets[i] == nullptr){
                index = i;
                break;
            }
        }
        if (isDog) {
            Pet* d = new Dog(petName, age, extraInfo);
            pets[index] = d;
            petCount++;
            currentDogs++;
            
            std::string id = "D" + std::to_string(currentDogs);
            d->setId(id);

            std::cout << "Success: " << petName << " has been added as a Dog! Pet ID: " << id << std::endl;
        } else {
            Pet* c = new Cat(petName, age, extraInfo);
            pets[index] = c;
            petCount++;
            currentCats++;
            
            std::string id = "C" + std::to_string(currentCats);
            c->setId(id);

            std::cout << "Success: " << petName << " has been added as a Cat! Pet ID: " << id << std::endl;
        }
    }
}
/* Adds a pet to the shelter.
* Input:
* - petName: Name of the pet.
* - age: Age of the pet in years.
* - isDog: If true, adds a dog; if false, adds a cat.
* - extraInfo: For dogs, this is the breed; for cats, this is the color.
*
* Process:
* - If shelter is full, prints "Error: Shelter is at full capacity!".
* - If dog capacity is full, prints "Error: No space for more dogs!".
* - If cat capacity is full, prints "Error: No space for more cats!".
*
* - If addition is successful, system will create a **unique pet ID** based on pet type:
*   - If dog, ID will be "D" followed by the dog's sequential number. Ex: "D1", "D2", etc.
*   - If cat, ID will be "C" followed by the cat's sequential number. Ex: "C1", "C2", etc.
*
* - If addition is successful, prints:
*   "Success: <petName> has been added as a <Dog/Cat>! Pet ID: <petID>"
*/

template <typename T>
T* PetShelter<T>::findPet(const std::string &petID) const {
    int i = 0;
    while (i < MAX_SHELTER_CAPACITY){
        if (pets[i] != nullptr && pets[i]->getId() == petID){
            pets[i]->displayInfo();
            return dynamic_cast<T*>(pets[i]);
        }
        i++;
    }
    std::cout << "Pet ID is invalid!" << std::endl;
    return nullptr;
}
/* Checks if a pet with the given ID exists in the shelter.
    * Input:
    * - petID: ID of the pet to check.
    *
    * Output:
    * - If found, prints pet details using the displayInfo() method.
    * - If not found, prints "Pet ID is invalid!".
    * Note: Uses dynamic_cast to safely convert from Pet* to T* when returning.
    */

template <typename T>
void PetShelter<T>::listAllPets() const {
    if (petCount == 0) {
        std::cout << "No pets in the shelter yet!" << std::endl;
    } else {
        int num = 1;
        for (int i = 0; i < MAX_SHELTER_CAPACITY ; i++) {
            if(pets[i] != nullptr){
                std::cout << num << ". ";
                pets[i]->displayInfo();
                num++;
            }
        }
    }
}
/* Displays a list of all pets in the shelter.
    * Output:
    * - If no pets in the shelter, prints "No pets in the shelter yet!".
    * - If pets exist, prints in the format:
    *   "<number>. <pet.displayInfo()>"
    *
    * - Numbering in output starts from 1.
    */

template <typename T>
int PetShelter<T>::calculateCost() const {
    int cost = 0;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] != nullptr){
            if (dynamic_cast<Dog*>(pets[i])) {
                cost += 75;
            } else if (dynamic_cast<Cat*>(pets[i])) {
                cost += 60;
            }
        }
    }
    return cost;
}
/* Calculates total cost of maintaining all pets in the shelter.
    * - Dogs cost 75 per day.
    * - Cats cost 60 per day.
    * 
    * Output: Total daily maintenance cost as an integer.
    * Note: Uses dynamic_cast to determine the type of pet (Dog or Cat) 
    * to apply the correct maintenance cost.
    * Example:
    *   if (dynamic_cast<Dog*>(pets[i])) { cost += 75; }
    *   else if (dynamic_cast<Cat*>(pets[i])) { cost += 60; }
    */

template <typename T>
void PetShelter<T>::removePet(const std::string &petID){
    std::string name;
    int i;
    for (i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] != nullptr && pets[i]->getId() == petID){
            name = pets[i]->getName();
            break;
        }
    }       

    if (i == MAX_SHELTER_CAPACITY){
        std::cout << "Pet ID is invalid!" << std::endl;
        return;
    }

    if (dynamic_cast<Dog*>(pets[i])){
        currentDogs--;
    } else if (dynamic_cast<Cat*>(pets[i])){
        currentCats--;
    }       

    delete pets[i];
    pets[i] = nullptr;
    
    petCount--;

    std::cout << name << " has been removed from the shelter." << std::endl;
}
/* Removes a pet with the given ID from the shelter.
    * Input:
    * - petID: ID of the pet to remove.
    *
    * Output:
    * - If found and removed, prints "<petName> has been removed from the shelter."
    * - If not found, prints "Pet ID is invalid!"
    * Note: Uses dynamic_cast to determine pet type when updating counters:
    *   if (dynamic_cast<Dog*>(pets[i])) { currentDogs--; }
    *   else if (dynamic_cast<Cat*>(pets[i])) { currentCats--; }
    */

template class PetShelter<Pet>;

// int main() {
//     PetShelter<Pet> p("psyes");
//     p.addPet("dog1", 4, true, "infod1");
//     p.addPet("dog2", 2, true, "infod2");
//     p.addPet("dog3", 4, true, "infod3");

//     p.addPet("cat1", 3, false, "infoc1");
//     p.addPet("cat2", 3, false, "infoc2");
//     p.addPet("cat3", 3, false, "infoc3");

//     p.listAllPets();

//     std::cout << '\n';

//     p.removePet("D1");
//     p.listAllPets();

//     std::cout << '\n';

//     p.removePet("C3");
//     p.listAllPets();

//     std::cout << '\n';

//     p.removePet("C1");
//     p.listAllPets();

//     std::cout << '\n';

//     p.addPet("cat4", 6, false, "infoc4");
//     p.addPet("cat5", 6, false, "infoc5");
//     p.addPet("dog4", 6, true, "infod4");
//     p.listAllPets();

//     std::cout << '\n';
//     p.removePet("C2");
//     p.removePet("C2");

//     std::cout << '\n';
//     p.findPet("D4");
//     p.findPet("C1");

//     std::cout << '\n';
//     std::cout << p.calculateCost() << std::endl;

//     return 0;
// } 