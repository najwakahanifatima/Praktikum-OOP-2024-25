import java.lang.reflect.*;
import java.util.*;

public class Injector {
    List<Object> dependencies;
    
    public Injector() {
        dependencies = new ArrayList<>();
    }

    public void addDependencies(Object object) {
        dependencies.add(object);
    }

    public void inject(Object object) throws Exception {
        List<Object> copyDep = new ArrayList<>(dependencies);
        Collections.reverse(copyDep);
        for (Field f : object.getClass().getDeclaredFields()) {
            f.setAccessible(true);
            for (Object o : copyDep) {
                if (f.getType().isAssignableFrom(o.getClass())) {
                    f.set(object, o);
                    break;
                }
            }
        }
    }
 }