

/**
 * Kelas MultithreadProgram adalah kelas yang digunakan untuk mencari angka yang sesuai dengan kondisi yang diberikan.
 * Kelas ini menggunakan multithreading untuk melakukan pencarian angka secara paralel.
 * Setelah angka yang sesuai ditemukan, kelas ini akan mencetak angka tersebut ke layar.
 * 
 * Modifikasi kelas ini agar dapat berjalan dengan benar sesuai dengan materi Multithreading.
 * Anda boleh menambahkan atribut dan method lain jika perlu
 * Anda juga boleh memodifikasi method ini jika diperlukan, tetapi jangan mengubah nama method, parameter, dan return value-nya.
 */
import java.util.*;

public class MultithreadProgram {
    private GiftChecker checker;
    private static final int MAX_THREADS = 8;
    private static final int MAX_NUMBER = 240;
    private volatile boolean found = false;
    public volatile int foundNumber = -1; 


    public MultithreadProgram(GiftChecker checker) {
        this.checker = checker;
    }

    public void setFoundNumber(int number) {
        if (!found && number != -1) {
            found = true;
            this.foundNumber = number;
        }
    }

    public void findCorrectNumber() {
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < MAX_NUMBER; i++) {
            queue.add(i);
        }

        List<Thread> workers = new ArrayList<>();

        for (int i = 0; i < MAX_THREADS; i++) {
            Thread worker = new Thread(() -> {
                while(!found) {
                    Integer number;
                    synchronized (queue) {
                        if (queue.isEmpty()) break;
                        number = queue.poll();
                    }

                    if(number != null && !found) {
                        Computer comp = new Computer(checker, number, this);
                        comp.run();
                    }
                }
            });
            workers.add(worker);
            worker.start();
        }

        for (Thread t : workers) {
            try {
                t.join();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        
        System.out.println("Found number: " + foundNumber);
    }
}