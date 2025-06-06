import java.lang.reflect.Array;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods(){
        Class<?> clazz = Ghost.class;
        Method[] methods = clazz.getDeclaredMethods();
        ArrayList<String> list = new ArrayList<>();       
        for (Method m : methods) {
            list.add(m.getName());
        }
        return list;
    }   

    public Integer sumGhost() throws Exception{
        Class<?> clazz = Ghost.class;
        Method[] methods = clazz.getDeclaredMethods();
        Integer sum = 0;
        for (Method met : methods) {
            met.setAccessible(true);
            if (met.getReturnType().equals(Integer.class)) {
                sum += (Integer) met.invoke(clazz.newInstance());
            }
        }
        return sum;   
    }

    public String letterGhost() throws Exception{
        Class<?> clazz = Ghost.class;
        Method[] methods = clazz.getDeclaredMethods();
        String res = "";
        for (Method met : methods) {
            met.setAccessible(true);
            if (met.getReturnType().equals(String.class)) {
                String temp = (String) met.invoke(clazz.newInstance());
                res += temp;
            }
        }
        return res;
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception{
        for (Secret s : sl) {
            if (s.isThis(email)) {
                Field uniqueId = s.getClass().getDeclaredField("uniqueId");
                uniqueId.setAccessible(true);
                return (String) uniqueId.get(s);
            }
        }
        return "NaN";
    }
}