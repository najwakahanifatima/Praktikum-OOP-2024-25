import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Implementasi dari interface SistemMasukSekolahList menggunakan LinkedList
 * PETUNJUK:
 * - Gunakan LinkedList sebagai struktur data utama
 * - Manfaatkan fitur Java Collections
 */
public class SistemMasukSekolahListImpl implements SistemMasukSekolahList {
    
    // Atribut: gunakan LinkedList<Student> untuk menyimpan data siswa
    private LinkedList<Student> students;
    
    /**
     * Constructor: inisialisasi LinkedList students
     */
    public SistemMasukSekolahListImpl() {
        this.students = new LinkedList<>();
    }
    
    @Override
    public void addStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa ke dalam list
        students.add(student);
    }
    
    @Override
    public void addFirstStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di awal list
        students.addFirst(student);
    }
    
    @Override
    public void addLastStudent(Student student) {
        // TODO: Implementasikan method ini
        // Menambahkan siswa di akhir list
        students.addLast(student);
    }
    
    @Override
    public Student getFirstStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa pertama di list
        return students.getFirst();
    }
    
    @Override
    public Student getLastStudent() {
        // TODO: Implementasikan method ini
        // Mengambil siswa terakhir di list
        return students.getLast();
    }
    
    @Override
    public Student removeFirstStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa pertama di list
        return students.removeFirst();
    }
    
    @Override
    public Student removeLastStudent() {
        // TODO: Implementasikan method ini
        // Menghapus dan mengembalikan siswa terakhir di list
        return students.removeLast();
    }
    
    @Override
    public int removeStudentsByGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Menghapus siswa dengan GPA < minGpa
        // Return jumlah siswa yang dihapus

        int num = 0;
        for (int i = 0; i < students.size(); i++) {
            Student stud = students.get(i);
            if (stud.getGpa() < minGpa) {
                num++;
                students.remove(i);
            }
        }
        
        return num;
    }
    
    @Override
    public List<Student> getStudentsWithHighGpa(double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan GPA >= minGpa
        List<Student> studs = new LinkedList<>();
        for (int i = 0; i < students.size(); i++) {
            Student stud = students.get(i);
            if (stud.getGpa() >= minGpa) {
                studs.add(stud);
            }
        }
        return studs;
    }
    
    @Override
    public List<Student> getStudentsByAge(int age) {
        // TODO: Implementasikan method ini
        // Mencari siswa dengan umur tertentu
        List<Student> studs = new LinkedList<>();
        for (int i = 0; i < students.size(); i++) {
            Student stud = students.get(i);
            if (stud.getAge() == age) {
                studs.add(stud);
            }
        }
        return studs;
    }
    
    @Override
    public List<String> getYoungHighAchieverNames(int maxAge, double minGpa) {
        // TODO: Implementasikan method ini
        // Mencari nama siswa muda (umur < maxAge) dan berprestasi (GPA >= minGpa)
        List<String> studs = new LinkedList<>();
        for (int i = 0; i < students.size(); i++) {
            Student stud = students.get(i);
            if (stud.getGpa() >= minGpa && stud.getAge() < maxAge) {
                studs.add(stud.getName());
            }
        }
        return studs;
    }
    
    @Override
    public List<Student> getAllStudents() {
        // TODO: Implementasikan method ini
        // Mengembalikan seluruh siswa dalam list
        return students;
    }
}
