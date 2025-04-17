#include "Playback.hpp"
#include <iostream>
using namespace std;

// queue<Song> playbackQueue;

/*
    * Menambahkan satu lagu ke akhir queue pemutaran.
    * Tidak perlu mengecek apakah lagu sudah ada di queue (boleh ada duplikat)
    */
void Playback::addToQueue(const Song &song){
    playbackQueue.push(song);
}

/*
    * Menambahkan semua lagu dari playlist yang diberikan ke akhir queue pemutaran,
    * dengan mempertahankan urutan mereka dari playlist.
    * Tidak perlu mengecek apakah lagu sudah ada di queue (boleh ada duplikat)
    */
void Playback::addToQueue(const Playlist &playlist){
    for (auto song : playlist.getSongs()){
        playbackQueue.push(song);
    }
}

/*
    * Memutar lagu berikutnya: Mencetak dengan format "Memutar: <lagu> <endl>" dan menghapusnya dari queue.
    * Jika queue kosong, mencetak pesan "Antrian kosong"
    */
void Playback::next(){
    if (playbackQueue.empty()){
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Memutar: " << playbackQueue.front() << endl;
        playbackQueue.pop();
    }
}

/*
    * Memutar semua lagu dari queue pemutaran.
    * Mencetak dengan format "Memutar: <lagu> <endl>" untuk setiap lagu di queue.
    * Jika queue kosong, mencetak pesan "Antrian kosong"
    */
void Playback::playAll(){
    if (playbackQueue.empty()){
        cout << "Antrian kosong" << endl;
    } else {
        while (!playbackQueue.empty()){
            cout << "Memutar: " << playbackQueue.front() << endl;
            playbackQueue.pop();
        }
    }
}

/*
    * Melewati lagu berikutnya: Menghapus lagu dari depan queue tanpa mencetak detail.
    * Jika queue kosong, mencetak pesan "Antrian kosong"
    */
void Playback::skip(){
    if (playbackQueue.empty()){
        cout << "Antrian kosong" << endl;
    } else {
        playbackQueue.pop();
    }
}

/*
    * Menghapus semua lagu dari queue pemutaran.
    */
void Playback::clearQueue(){
    while (!playbackQueue.empty()){
        playbackQueue.pop();
    }
}

/*
    * Memeriksa apakah queue pemutaran kosong.
    */
bool Playback::isEmpty() const {
    return playbackQueue.empty();
}

/*p.pla
    * Mengembalikan jumlah lagu yang ada dalam queue.
    */
size_t Playback::queueSize() const{
    return playbackQueue.size();
}

// int main(){
//     Song s1("t1", "a1");
//     Song s2("t2", "a2");
//     Song s3("t3", "a3");
//     Song s4("t4", "a4");
//     Song s5("t5", "a5");

//     Playlist p1("playlist1");
//     p1.addSong(s1);
//     p1.addSong(s2);
//     p1.addSong(s3);

//     cout << p1 << endl;

//     Playlist p2("playlist2");
//     p2.addSong(s2); 
//     p2.addSong(s3);
//     p2.addSong(s4);
//     p2.addSong(s5);

//     p2.removeSong(s2);
//     p2.removeSongByIndex(10);

//     cout << p2 << endl;

//     Playback p;
//     p.addToQueue(s1);
//     p.next();
//     cout << endl;

//     p.addToQueue(p1);
//     p.addToQueue(p2);
//     p.skip();

//     p.playAll();

//     // p.clearQueue();
//     // p.playAll();


//     return 0;
// }