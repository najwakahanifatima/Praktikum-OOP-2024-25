import java.lang.reflect.*;

public class MahasiswaDecoder {
    Mahasiswa mhs;

    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.mhs = mahasiswa;
    }

    public void addMatkul(String name) throws Exception {
        Class<?> kelazz = Mahasiswa.class;
        Method m = kelazz.getDeclaredMethod("addMatkul", String.class);
        m.setAccessible(true);
        m.invoke(mhs, name);
    }

    public int getNIM() throws Exception {
        Class<?>  kelazz = Mahasiswa.class;
        Field f = kelazz.getDeclaredField("NIM");
        f.setAccessible(true);
        return (Integer) f.get(mhs);
    }

    public double getIPK() throws Exception {
        Class<?>  kelazz = Mahasiswa.class;
        Field f = kelazz.getDeclaredField("IPK");
        f.setAccessible(true);
        return (Double) f.get(mhs);
    }

    // public static void main(String arg[]) {
    //     Mahasiswa ini = new Mahasiswa(123, 3.9);
    //     MahasiswaDecoder decoder = new MahasiswaDecoder(ini);
    //     try {
    //         System.out.println("Changing mhs");
    //         decoder.addMatkul("Sistem Operasi");
    //         System.out.println("Berhasil Add matkul");
    //         System.out.println("IPK: " + decoder.getIPK() + " NIM: " + decoder.getNIM());
    //     } catch (Exception e) {
    //         System.out.println(e.getMessage());
    //     }
    // }

}