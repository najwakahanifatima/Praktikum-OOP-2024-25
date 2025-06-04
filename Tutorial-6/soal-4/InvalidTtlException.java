public class InvalidTtlException extends RuntimeException {
    public InvalidTtlException() {
        super("TTL must be positive");
    }
}