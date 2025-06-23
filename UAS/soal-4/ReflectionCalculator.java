import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Scanner;

public class ReflectionCalculator {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        // Input case
        int tc = sc.nextInt();

        // Input 2 buah angka (a dan b)
        int a = sc.nextInt(), b = sc.nextInt();
        sc.close();

        // Reflection
        Class<?> cls = Calculator.class;

        switch (tc) {
            case 1:
                // a + b
                Method m1 = cls.getMethod("add", int.class, int.class);
                m1.invoke(cls.getConstructor().newInstance(), a, b);
                break;
            case 2:
                // a - b
                Method m2 = cls.getMethod("subtract", int.class, int.class);
                m2.invoke(cls.getConstructor().newInstance(), a, b);
                break;
            case 3:
                // a * b
                Method m3 = cls.getMethod("multiply", int.class, int.class);
                m3.invoke(cls.getConstructor().newInstance(), a, b);
                break;
            case 4:
                // a / b dengan precision 2 (default)
                Method m4 = cls.getMethod("divide", int.class, int.class);
                m4.invoke(cls.getConstructor().newInstance(), a, b);
                break;
            case 5:
                // a / b dengan precision 3
                Calculator cal = new Calculator();
                Field f = cls.getDeclaredField("precision");
                f.setAccessible(true);
                f.set(cal, 3);
                Method m5 = cls.getMethod("divide", int.class, int.class);
                m5.invoke(cal, a, b);
                break;
            default:
                break;
        }
    }
}
