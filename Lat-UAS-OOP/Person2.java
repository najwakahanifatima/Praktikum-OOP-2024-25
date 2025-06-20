public class Person2 {
    private boolean hasData;
    private int data;
    public Person2() {
        hasData = true;
        data = 1;
    }

    public synchronized void produce(int value) throws InterruptedException {
        while (hasData) {
            wait();
        }
        this.data = value;
        hasData = true;
        notify();
        System.out.println("produce val: " + value); 
    }

    public synchronized void consume() throws InterruptedException {
        while (!hasData) {
            wait();
        }
        int temp = data;
        this.data = 0;
        hasData = false;
        notify();
        System.out.println("consume val: " + temp); 
    }

    public static void main(String args[]) throws Exception {
        Person2 p = new Person2();
        Thread producer = new Thread(() -> {
            try {
                for (int i = 0; i < 5; i ++) {
                    p.produce(i);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        });

        Thread consumer = new Thread(() -> {
            try {
                for (int i = 0; i < 5; i ++) {
                    p.consume();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        });

        producer.start();
        consumer.start();
    }
}
