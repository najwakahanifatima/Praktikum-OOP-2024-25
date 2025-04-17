#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Gradebook.hpp"

// map<string, double> studentGrades;

/*
    * Menambah atau mengupdate nilai mahasiswa.
    * Jika mahasiswa sudah ada, nilainya akan diupdate.
    * Jika mahasiswa belum ada, akan ditambahkan dengan nilai yang diberikan.
    */
void Gradebook::addOrUpdateStudent(const string &studentName, double grade){
    if (studentExists(studentName)){
        studentGrades[studentName] += grade;
    } else {
        studentGrades.insert({studentName, grade});
    }
}

/*
    * Menghapus mahasiswa dari gradebook.
    * Mengembalikan true jika mahasiswa ditemukan dan berhasil dihapus,
    * false jika tidak ditemukan.
    */
bool Gradebook::removeStudent(const string &studentName){
    if (studentExists(studentName)){
        studentGrades.erase(studentName);
        return true;
    }
    return false;
}

/*
    * Mengambil nilai dari mahasiswa tertentu.
    * Mengembalikan true jika mahasiswa ditemukan dan nilainya disimpan
    * di parameter 'grade', false jika mahasiswa tidak ditemukan.
    */
bool Gradebook::getGrade(const string &studentName, double &grade) const {
    if (studentExists(studentName)){
        grade = studentGrades.at(studentName);
        return true;
    }
    return false;
}

/*
    * Memeriksa apakah mahasiswa ada dalam gradebook.
    * Mengembalikan true jika mahasiswa ada, false jika tidak.
    */
bool Gradebook::studentExists(const string &studentName) const {
    return studentGrades.count(studentName);
}

/*
    * Mencetak semua nama mahasiswa dan nilai mereka
    * Jika gradebook kosong, akan mencetak pesan "Gradebook kosong\n"
    * Format:
    * 1. <nama_mahasiswa>: <nilai>
    * 2. <nama_mahasiswa>: <nilai>
    * ...
    */
void Gradebook::printGrades() const {
    int i = 0;
    for (auto student : studentGrades){
        cout << ++i << ". " << student.first << ": " << student.second << endl;
    }
}

/*
    * Mencetak semua nama mahasiswa dan nilai mereka, terurut berdasarkan nilai terbesar ke terkecil.
    * Hint: gunakan vector<pair<string, double>> untuk menyimpan semua data mahasiswa untuk memudahkan pengurutan. Gunakan fungsi bantuan untuk komparasi pada std::sort.
    * Format:
    * 1. <nama_mahasiswa>: <nilai>
    * 2. <nama_mahasiswa>: <nilai>
    * ...
    */
bool cmp(const pair<string, double>& a, const pair<string, double>& b){
    return a.second > b.second;
}
void Gradebook::printGradesRank() const {
    vector<pair<string,double>> temp;
    for (auto& stud : studentGrades){
        temp.push_back(stud);
    }
    sort(temp.begin(), temp.end(), cmp);
    int i = 0;
    for (auto stud : temp){
        cout << ++i << ". " << stud.first << ": " << stud.second << endl;
    }
}

/*
    * Mengembalikan daftar nama mahasiswa yang nilainya di atas threshold tertentu.
    * Mengembalikan vector berisi nama mahasiswa dengan nilai lebih besar dari threshold,
    * terurut berdasarkan abjad.
    */
vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const {
    vector<string> result;
    for (auto stud : studentGrades){
        if (stud.second > threshold){
            result.push_back(stud.first);
        }
    }
    return result;
}

/*
    * Menghitung rata-rata nilai semua mahasiswa dalam gradebook.
    * Mengembalikan rata-rata nilai, atau 0.0 jika gradebook kosong.
    */
double Gradebook::getAverageGrade() const {
    if (studentGrades.empty()){
        return 0.0;
    } else {
        double sum;
        for (auto stud : studentGrades){
            sum += stud.second;
        }
        return sum / studentGrades.size();
    }
}

/*
    * Mengembalikan jumlah mahasiswa yang ada dalam gradebook.
    */
size_t Gradebook::getNumberOfStudents() const {
    return studentGrades.size();
}

// int main() {
//     Gradebook g;
//     g.addOrUpdateStudent("najwa", 96);
//     g.addOrUpdateStudent("kahani", 97);
//     g.addOrUpdateStudent("fatima", 95);
//     g.printGrades();
//     cout << endl;

//     g.addOrUpdateStudent("najwa", 100);
//     g.printGradesRank();
//     cout << endl;

//     cout << "rata-rata: " << g.getAverageGrade() << endl;
//     cout << endl;

//     vector<string> temp = g.getStudentsWithGradeAbove(96);
//     for (auto el : temp){
//         cout << el << ",";
//     }

//     return 0;
// }