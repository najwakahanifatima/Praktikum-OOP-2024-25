/**
 * SmartDoorLock - Kelas yang merepresentasikan kunci pintu pintar rumah
 * Kelas ini mewarisi SecurityDevice dan mengimplementasikan EnergyMonitored
 * untuk membuat perangkat keamanan dengan fitur pemantauan energi
 */
public class SmartDoorLock extends SecurityDevice implements EnergyMonitored {
    private int batteryLevel;      // Level baterai (0-100)
    private boolean doorOpen;      // Status pintu (terbuka/tertutup)
    private static final int MAX_BATTERY = 100;
    
    /**
     * Konstruktor untuk membuat SmartDoorLock baru
     * @param name Nama perangkat yang akan ditampilkan
     * @param password Password untuk mengunci/membuka perangkat
     * Set batteryLevel ke 100% dan doorOpen ke false
     */
    public SmartDoorLock(String name, String password) {
        // TODO: Implementasi
        super(name, password);
        this.batteryLevel = MAX_BATTERY;
        this.doorOpen = false;
    }
    
    /**
     * Mengembalikan jumlah energi yang dikonsumsi (dalam watt)
     * Format keluaran: nilai desimal (misal: 2.5 atau 0.5)
     * Mengkonsumsi lebih banyak energi ketika aktif
     */
    @Override
    public double getEnergyConsumption() {
        // TODO: Implementasi
        if (isActive()) {
            return 2.5;
        } else {
            return 0.5;
        }
    }
    
    /**
     * Mengembalikan peringkat efisiensi energi berdasarkan level baterai
     * Format keluaran: nilai integer 1-5, dengan 5 adalah yang paling efisien
     * Semakin tinggi baterai, semakin efisien perangkat
     */
    @Override
    public int getEnergyEfficiencyRating() {
        // TODO: Implementasi
        if (this.batteryLevel <= 20) {
            return 1;
        } else if (this.batteryLevel <= 40) {
            return 2;
        } else if (this.batteryLevel <= 60) {
            return 3;
        } else if (this.batteryLevel <= 80) {
            return 4;
        } else {
            return 5;
        }
    }
    
    /**
     * Menampilkan status lengkap dari perangkat
     * Format keluaran: multi-baris yang menampilkan nama, status aktif, 
     * status kunci, posisi pintu, level baterai, dan rating efisiensi energi
     */
    @Override
    public void reportStatus() {
        System.out.println("Smart Door Lock Status:");
        System.out.println("- Name: " + deviceName);
        System.out.println("- Active: " + (isActive() ? "Yes" : "No"));
        System.out.println("- Locked: " + (isLocked() ? "Yes" : "No"));
        System.out.println("- Door Position: " + (doorOpen ? "Open" : "Closed"));
        System.out.println("- Battery Level: " + batteryLevel + "%");
        System.out.println("- Energy Rating: " + getEnergyEfficiencyRating() + "/5");
    }
    
    /**
     * Membuka pintu dengan autentikasi password
     * Format keluaran: 
     * - "Door is already open" jika pintu sudah terbuka
     * - "Cannot open door: Device is not active" jika perangkat tidak aktif
     * - Pesan dari metode unlock() jika perangkat terkunci
     * - Jika masih terkunci, return
     * - Jika pintu berhasil terbuka, pakai baterai 10
     * - "Door opened" jika berhasil membuka pintu
     * 
     * Logika: Memeriksa status pintu -status aktif - status kunci - membuka pintu
     * @param password Password untuk autentikasi jika pintu terkunci
     */
    public void openDoor(String password) {
        // TODO: Implementasi
        if (isDoorOpen()) {
            System.out.println("Door is already open");
            return;
        }
        if (!isActive()) {
            System.out.println("Cannot open door: Device is not active");
            return;
        }
        if (isLocked()) {
            unlock(password);
            if (isLocked()) {
                return;
            }
        }

        this.doorOpen = true;
        useBattery(10);
        // System.out.println("Door opened");
    }
    
    /**
     * Menutup pintu dan mengunci secara otomatis
        * Format keluaran:
     * - "Door is already closed" jika pintu sudah tertutup
     * - "Door closed" jika berhasil menutup pintu
     * - Pesan dari metode lock() jika mengunci otomatis
     * - Jika pintu berhasil ditutup, pakai baterai 5
     * - "Door closed" jika berhasil menutup pintu
     * 
     * Logika: Memeriksa status pintu - menutup pintu - mengunci otomatis jika aktif
     */
    public void closeDoor() {
        // the order might be wrong
        if (!isDoorOpen()) {
            System.out.println("Door is already closed");
            return;
        }
        System.out.println("Door closed");
        this.doorOpen = false;
        if (isActive()) {
            lock();
        }
        useBattery(5);
    }
    
    /**
     * Memeriksa apakah pintu sedang terbuka
     * @return true jika pintu terbuka, false jika tertutup
     */
    public boolean isDoorOpen() {
        return doorOpen;
    }
    
    /**
     * Mengisi baterai perangkat dengan jumlah tertentu
     * Format keluaran: "Battery charged to X%" dengan X adalah level baterai baru
     * @param amount Jumlah pengisian baterai (dalam persen)
     */
    public void chargeBattery(int amount) {
        // TODO: Implementasi
        this.batteryLevel += amount;
        if (this.batteryLevel >= MAX_BATTERY) {
            this.batteryLevel = MAX_BATTERY;
        }
        System.out.println("Battery charged to " + this.batteryLevel + "%");
    }
    
    /**
     * Metode helper untuk menggunakan baterai dan memeriksa level
     * Format keluaran: 
     * - "Warning: Battery depleted, device turned off" jika baterai habis
     * - "Warning: Low battery (X%)" jika baterai di bawah 20%
     * @param amount Jumlah baterai yang digunakan (dalam persen)
     */
    private void useBattery(int amount) {
        this.batteryLevel -= amount;
        if (this.batteryLevel <= 0) {
            this.batteryLevel = 0;
            System.out.println("Warning: Battery depleted, device turned off");
            return;
        }
        if (this.batteryLevel < 20) {
            System.out.println("Warning: Low battery (" + this.batteryLevel + "%)");
        }

    }
    
    /**
     * Override metode turnOn untuk mempertimbangkan level baterai
     * Format keluaran:
     * - Pesan dari superclass jika baterai cukup
     * - "Cannot turn on: Battery depleted" jika baterai habis
     * - Jika perangkat aktif, pakai baterai 5
     */
    @Override
    public void turnOn() {
        // TODO: Implementasi
        if (this.batteryLevel > 0) {
            super.turnOn();
            useBattery(5);
        } else {
             System.out.println("Cannot turn on: Battery depleted");
             return;
        }
    }
    
    /**
     * Override metode unlock untuk mempertimbangkan level baterai
     * Format keluaran:
     * - Pesan dari superclass jika baterai cukup
     * - "Cannot unlock: Battery depleted" jika baterai habis
     * - Jika perangkat tidak terkunci, pakai baterai 8
     * @param password Password untuk autentikasi
     */
    @Override
    public void unlock(String password) {
        // TODO: Implementasi
        if (this.batteryLevel > 0) {
            super.unlock(password);
        } else {
             System.out.println("Cannot unlock: Battery depleted");
             return;
        }
        if (!isLocked()) {
            useBattery(8);
        }
    }
}