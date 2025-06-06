import java.util.*;

public class WorkerV2 implements Runnable {

    private List<Task> tasks;

    public WorkerV2(){
        tasks = new ArrayList<>();
    };

    public void addTask(Task newTask){
        tasks.add(newTask);
    }

    @Override
    public void run() {
        try {
            //TODO: Fill with the operation that will process the tasks. Hint: the operation is exactly
            // the same with the operation that exist on Worker.java with a little improvement;)
            for (Task t : tasks) {
                Thread.sleep(t.getTime());
                synchronized (t) {
                    t.setStatus("done");
                    t.notify();
                }
            }
        } catch (InterruptedException e) {
            //TODO: Fill with the same error message on the Worker.java
             System.out.println("Worker Error!");
        }
    }
    
}