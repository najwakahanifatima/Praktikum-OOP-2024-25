import java.io.*;
import java.util.*;

public class Enclosure {
    private ArrayList<Animal> animals;

    public Enclosure() {
        // Inisialisasi ArrayList animals kosong
        this.animals = new ArrayList<Animal>();
    } 

    public int getAnimalCount() {
        // Mengembalikan jumlah hewan dalam this.animals
        return animals.size();
    }

    public void addAnimal(Animal animal) {
        // menambahkan seekor hewan ke dalam this.animals
        animals.add(animal);
    }

    public Animal getAnimalAt(int i) {
        // mengembalikan hewan dalam this.animals pada index i (tidak mengubah this.animals)
        return animals.get(i);
    }

    public void removeAnimalAt(int i) {
        // menghapus hewan pada this.animals pada index i
        animals.remove(i);

    }

    public boolean isEmpty() {
        // mengembalikan boolean yang menyatakan apakah this.animals kosong atau tidak
        return animals.isEmpty();
    }

    public void describe() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong menuliskan output serupa dengan output berikut:
        // Kandang berisi 2 ekor hewan:
        // 1. po, spesies Pandamus Maximus, umur 5 tahun
        // 2. po2, spesies Pandamus Maximus, umur 5 tahun
        if (isEmpty()){
            System.out.println("Kandang ini kosong...");
        }
        else{
            System.out.println("Kandang berisi " + getAnimalCount() + " ekor hewan:");
            int number = 1;            
            for (Animal a : animals){ 
                System.out.println(number + ". " + a.getName() + ", spesies " + a.getSpecies() + ", umur " + a.getAge() + " tahun");
                number++;
            }
        }
    }

    public void feed() {
        // Menuliskan output berikut apabila this.animals kosong:
        // Kandang ini kosong...
        // Apabila tidak kosong maka akan memanggil method eat pada tiap animal dalam this.animals
        if (isEmpty()){
            System.out.println("Kandang ini kosong...");
        }
        else{
            for (Animal a : animals){
                a.eat();
            }
        }
    }

    public boolean safeForPetting() {
        // mengembalikan true apabila semua hewan dalam this.animals bersifat friendly
        for (Animal a: animals){
            if (!a.isFriendly()){
                return false;
            }
        }
        return true;
    }

//     public static void main(String[] args){
//          Enclosure enc1 = new Enclosure();
//         Panda panda1 = new Panda("po", 5);
//         Panda panda2 = new Panda("po2", 5);
//         enc1.addAnimal(panda1);
//         enc1.addAnimal(panda2);
//         enc1.describe();

//     }
}