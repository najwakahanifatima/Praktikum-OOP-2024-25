#include "Playlist.hpp"
#include <iostream>
#include <stdexcept>

    // string name;
    // vector<Song> songs;

Playlist::Playlist(string playlistName){
    name = playlistName;
}

// Getters
const string &Playlist::getName() const{
    return this->name;
}

const vector<Song> &Playlist::getSongs() const{
    return this->songs;
}

/*
    * Menambahkan salinan lagu yang diberikan ke akhir playlist apabila lagu tersebut belum ada di playlist.
    * Menggunakan Song::operator== untuk perbandingan.
    */
void Playlist::addSong(const Song &song){
    bool found = false;
    for (auto csong : songs){
        if (csong == song) {
            found = true;
            break;
        }
    }
    if (!found){
        songs.push_back(song);
    }
}

/*
    * Menghapus kemunculan pertama dari lagu yang ditentukan dari playlist.
    * Mengembalikan true jika lagu berhasil dihapus, false jika tidak.
    * Menggunakan Song::operator== untuk perbandingan.
    */
bool Playlist::removeSong(const Song &songToRemove){
    bool found = false;
    for (auto it = songs.begin(); it != songs.end(); ++it){
        if (*it == songToRemove) {
            songs.erase(it);
            return true;
        }
    }
    return false;
}

/*
    * Menghapus lagu pada indeks yang ditentukan.
    * Melempar out_of_range jika indeks tidak valid.
    */
void Playlist::removeSongByIndex(size_t index){
    try {
        if (index < 0 || index >= songs.size()){
            throw out_of_range("Index out of range");
        }
        songs.erase(songs.begin() + index);
    } catch (out_of_range& e) {
        cout << e.what() << endl;
        return;
    }
}

/*
    * Mengembalikan jumlah lagu dalam playlist.
    */
size_t Playlist::numberOfSongs() const{
    return songs.size();
}

/*
    * Friend function untuk mencetak isi playlist.
    * Format:
    * Playlist: <nama_playlist> (<jumlah_lagu> lagu)
    * 1. <lagu1>
    * 2. <lagu2>
    * ...
    * <jumlah_lagu>. <laguN> <endl>
    */
ostream &operator<<(ostream &os, const Playlist &pl){
    os << "Playlist: " << pl.getName() << " (" << pl.numberOfSongs() << " lagu)" << endl;
    for (int i = 0; i < pl.numberOfSongs(); i++){
        os << i+1 << ". ";
        os << pl.getSongs().at(i) << endl;
    }
    return os;
}