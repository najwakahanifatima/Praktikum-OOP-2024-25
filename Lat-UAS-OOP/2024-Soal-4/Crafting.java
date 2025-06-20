import java.util.ArrayList;

// Silahkan gunakan instanceof untuk mengecek kelas dari sebuah objek

public class Crafting {
    private ArrayList<Material> materials;
    private int countStick;
    private int countIron;

    /**
     * Default constructor untuk crafting
     * Inisiasi countStick dan countIron menjadi 0
     * Inisiasi materials menjadi ArrayList baru
     */
    public Crafting() {
        countStick = 0;
        countIron = 0;
        materials = new ArrayList<>();
    }

    /**
     * Menambahkan material ke dalam list materials
     * @param m
     * Cek apakah material yang ditambahkan adalah Stick atau Iron, tambahkan countStick atau countIron
     */
    public void addMaterial(Material m) {
        materials.add(m);
        if (m instanceof Stick) countStick ++;
        if (m instanceof Iron) countIron ++;
    }

    /**
     * Menghapus stick dari list of materials sebanyak count dan memperbarui countStick. Panggil method use() dari material ketika material dihilangkan. Return void apabila countStick kurang dari count, print "Stick hanya ada x buah"
     * @param count
     */
    public void removeStick(int count) {
        if (countStick < count) {
            System.out.println("Stick hanya ada " + countStick + " buah");
            return;
        }
        for (Material m : materials) {
            if (m instanceof Stick && count != 0) {
                materials.remove(m);
                count--;
            }
            if (count == 0) break;
        }
        countStick -= count;
    }

    /**
     * Menghapus Iron dari list of materials sebanyak count dan memperbarui countIron. Panggil method use() dari material ketika material dihilangkan. Return void apabila countIron kurang dari count, print "Iron hanya ada x buah"
     * @param count
     */
    public void removeIron(int count) {
        if (countIron < count) {
            System.out.println("Iron hanya ada " + countIron + " buah");
            return;
        }
        for (Material m : materials) {
            if (m instanceof Iron && count != 0) {
                materials.remove(m);
                count--;
            }
            if (count == 0) break;
        }
        countIron -= count;
    }

    /**
     * Membuat sebuah Sword dengan jumlah stick, iron sesuai parameter. Sword akan memiliki damage sebesar argumen damage. Apabila material tidak cukup, lempar exception dengan pesan "Material tidak cukup". Remove Iron terlebih dahulu sebelum remove Stick
     * @param stick
     * @param iron
     * @param damage
     * @return
     * @throws IllegalStateException
     */
    public Sword craftSword(int stick, int iron, int damage) throws IllegalStateException {
        if (countStick < stick || countIron < iron) {
            throw new IllegalStateException("Material tidak cukup");
        }
        removeIron(iron);
        removeStick(stick);
        return new Sword(damage);
    }

    /**
     * Membuat sebuah Axe dengan jumlah stick, iron sesuai parameter. Axe akan memiliki damage sebesar argumen damage. Apabila material tidak cukup, lempar exception dengan pesan "Material tidak cukup". Remove Iron terlebih dahulu sebelum remove Stick
     * @param stick
     * @param iron
     * @param damage
     * @return
     * @throws IllegalStateException
     */
    public Axe craftAxe(int stick, int iron, int damage) throws IllegalStateException {
        if (countStick < stick || countIron < iron) {
            throw new IllegalStateException("Material tidak cukup");
        }
        removeIron(iron);
        removeStick(stick);
        return new Axe(damage);
    }

    /**
     * Membuat sebuah Hoe dengan jumlah stick, iron sesuai parameter. Hoe akan memiliki durability sebesar argumen durability. Apabila material tidak cukup, lempar exception dengan pesan "Material tidak cukup". Remove Iron terlebih dahulu sebelum remove Stick
     * @param stick
     * @param iron
     * @param durability
     * @return
     * @throws IllegalStateException
     */
    public Hoe craftHoe(int stick, int iron, int durability) throws IllegalStateException {
        if (countStick < stick || countIron < iron) {
            throw new IllegalStateException("Material tidak cukup");
        }
        removeIron(iron);
        removeStick(stick);
        return new Hoe(durability);
    }
}
