import java.util.HashMap;

public class EnrollmentSystem {
    private HashMap<String, Student> students; // <studentID, Student>
    private HashMap<String, Course> courses; // <courseID, Course>

    // Ctor untuk membuat objek EnrollmentSystem
    // Inisialisasi students dan courses
    public EnrollmentSystem() {
        students = new HashMap<String, Student>();
        courses = new HashMap<String, Course>();
    }

    // Method untuk menambahkan student ke dalam sistem
    public void addStudent(String studentID, String name) {
        students.put(studentID, new Student(studentID, name));
    }

    // Method untuk menambahkan course ke dalam sistem
    public void addCourse(String courseID, String courseName) {
        courses.put(courseID, new Course(courseID, courseName));
    }

    // Method untuk mendaftar student ke dalam course
    // Jika student atau course tidak ditemukan, tampilkan pesan error
    // "Student atau course tidak ditemukan!" (tanpa tanda kutip)
    public void enrollStudentInCourse(String studentID, String courseID) {
        if (students.get(studentID) == null || courses.get(courseID) == null) {
            System.out.println("Student atau course tidak ditemukan!");
            return;
        }

        Student stud = students.get(studentID);
        stud.enrollCourse(courseID);
        Course course = courses.get(courseID);
        course.addStudent(studentID);
    }

    // Method untuk menampilkan daftar course yang diambil oleh student
    // 
    // Student <studentName> terdaftar di <jumlah course> course:
    // <courseID1> <courseName1>
    // <courseID2> <courseName2>
    // ...
    //
    // Jika student tidak ditemukan, tampilkan pesan error
    // "Student tidak ditemukan!" (tanpa tanda kutip)
    public void displayCoursesForStudent(String studentID) {
        Student stud = students.get(studentID);
        if (stud == null) {
            System.out.println("Student tidak ditemukan!");
            return;
        }
        System.out.println("Student " + stud.getName() + " terdaftar di " + stud.getEnrolledCourses().size() + " course:");
        for(String c : stud.getEnrolledCourses()) {
            Course course = courses.get(c);
            System.out.println(c + " " + course.getCourseName());
        }
    }

    // Method untuk menampilkan daftar student yang terdaftar di course
    // 
    // Course <courseName> memiliki <jumlah student> student:
    // <studentID1> <studentName1>
    // <studentID2> <studentName2>
    // ...
    //
    // Jika course tidak ditemukan, tampilkan pesan error
    // "Course tidak ditemukan!" (tanpa tanda kutip)
    public void displayStudentsInCourse(String courseID) {
        Course course = courses.get(courseID);
        if (course == null) {
            System.out.println("Course tidak ditemukan!");
            return;
        }
        System.out.println("Course " + course.getCourseName() + " memiliki " + course.getEnrolledStudents().size() + " student:");
        for(String s : course.getEnrolledStudents()) {
            Student stud = students.get(s);
            System.out.println(s + " " + stud.getName());
        }
    }
}
