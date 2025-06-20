import java.util.*;

public class Person implements Runnable {
    private volatile int sum = 0;
    public int checker = 0;
    public String name;
    public Person() {}
    public Person(String n) {
        this.name = n;
    }

    public synchronized void add(int num) {
        sum += num;
    }

    @Override
    public synchronized void run() {
        if (checker > 100) {System.out.println("lewat");}
        checker++;
    }

    public int getSum() {return sum; }

    public static void main(String args[]) throws Exception {
        // Field f = Class.forName("Person").getField("name");
        // Object obj = Person.class.getDeclaredConstructor().newInstance();
        // f.set(obj, "Nama saya");
        // Person p = (Person) obj;
        // System.out.println(p.name);

        List<Thread> workers = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < 100; i++) {
            queue.add(i);
        }
        Person p = new Person("namaaa");
        for (int i = 0; i < 5; i++) {
            Thread worker = new Thread (() -> {
                while (!queue.isEmpty()) {
                    Integer number = 0;
                    synchronized (queue) {
                        if (queue.isEmpty()) break;
                        number = queue.poll();
                    }
                    p.add(number);
                    System.out.println(Thread.currentThread().getName() + " is adding " + number + ", current sum: " + p.getSum());
                }
                }
            );
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
        System.out.println("sum: " + p.getSum());
    }
}