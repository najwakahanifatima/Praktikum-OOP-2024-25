public class MoneyInWallet implements MoneyTransaction{
    private int amount;

    /*
     * Inisialisasi amount = 0
     */
    public MoneyInWallet() {
        this.amount = 0;
    }

    /*
     * Inisialisasi amount sesuai masukan
     */
    public MoneyInWallet(int amount) {
        this.amount = amount;
    }

    /*
     * Mengembalikan nilai amount
     */
    public int getAmount() {
        return this.amount;
    }

    /*
     * Menambahkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInWallet
     */
    public MoneyTransaction add(MoneyTransaction money) {
        return new MoneyInWallet(this.amount + money.getAmount());
    }

    /*
     * Mengurangkan amount dengan amount dari masukan
     * Kembalikan hasilnya pada objek baru MoneyInWallet
     * Jika amount dari masukan lebih besar dari amount, maka objek yang dikembalikan memiliki amount = 0
     */
    public MoneyTransaction subtract(MoneyTransaction money) {
        if (this.amount < money.getAmount()){
            return new MoneyInWallet(0);
        }
        return new MoneyInWallet(this.amount - money.getAmount());
    }

    /*
     * Menyimpan uang di dompet dapat membuang uang menjadi lapuk
     * Amount akan menjadi 90% dari sebelumnya
     * Jika hasil bukan integer, bulatkan hasil ke bawah
     */
    public void decay() {
        this.amount *= 0.9;
    }
}