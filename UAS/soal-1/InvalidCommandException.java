/**
 * Exception yang dilempar ketika command tidak valid.
 * Menambahkan prefix "InvalidCommandException: " pada pesan error.
 */
public class InvalidCommandException extends Exception {
    public InvalidCommandException(String msg) {
        super("InvalidCommandException: " + msg);
    }
}