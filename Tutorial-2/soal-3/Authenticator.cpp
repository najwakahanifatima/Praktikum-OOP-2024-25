#include "Authenticator.hpp"
#include "User.hpp"
#include "AdminUser.hpp"
#include <iostream>

using namespace std;

Authenticator::Authenticator(){
    userCount = 0;
    currentUser = nullptr;
    secretResource = "Ini adalah data rahasia!";
    for (int i = 0; i < MAX_USERS; i++){
        users[i] = nullptr;
    }
}

void Authenticator::registerUser(const string &username, const string &password, bool isAdmin){
    if (userCount == MAX_USERS){
        cout << "Gagal: Kapasitas user penuh!" << endl;
    } else {
        int i = 0; bool found = false;
        while (i < userCount && !found){
            if (users[i] != nullptr && users[i]->getUsername() == username){
                found = true;
                cout << "Gagal: Username sudah digunakan!" << endl;
            }
            i++;
        }
        if (!found){
            if (isAdmin){
                users[userCount] = new AdminUser(username, password);
            } else {
                users[userCount] = new User(username, password);
            }
            userCount++;
            cout << "Sukses: User " << username << " berhasil terdaftar!" << endl;
        }
    }
}

void Authenticator::login(const string &username, const string &password){
    bool found = false; int n = 0;
    while (!found && n < userCount){
        if (users[n]->getUsername() == username && users[n] != nullptr){
            if (users[n]->checkPassword(password)){
                found = true;
                currentUser = users[n];
                cout << "Sukses: Login berhasil! Selamat datang, " << username << "." << endl;
            }
        }
        n++;
    }
    if (!found){
        cout << "Gagal: Username atau password salah!" << endl;
    }
}

void Authenticator::logout(){
    if (currentUser == nullptr){
        cout << "Gagal: Tidak ada user yang sedang login!" << endl;
    } else {
        cout << "Sukses: User " << currentUser->getUsername() << " telah logout." << endl;
        currentUser = nullptr;
    }
}

void Authenticator::accessResource() const{
    if (currentUser == nullptr){
        cout << "Akses ditolak! Silakan login terlebih dahulu." << endl;
    } else {
        cout << "Resource: "  << secretResource << endl;
    }
}

void Authenticator::setResource(const string &newResource){
    if (currentUser == nullptr){
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." << endl;
    } else if (!currentUser->isAdmin()){
        cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << endl;
    } else {
        secretResource = newResource;
        cout << "Sukses: Resource telah diperbarui oleh " << currentUser->getUsername() << "." << endl;
    }
}

Authenticator::~Authenticator(){
    for (int i = 0; i < userCount; i++){
        delete users[i];
    }
}

// int main(){
//     Authenticator auth;
//     auth.registerUser("najwa", "123", false);
//     auth.registerUser("kahani", "321", true);
//     cout << "oke" <<  endl;
//     auth.login("najwa", "321");
    
//     auth.login("najwa", "123");
//     auth.accessResource();
//     auth.logout();

//     auth.login("kahani", "321");
//     auth.setResource("hahaha");
//     auth.accessResource();
    

//     return 0;
// }