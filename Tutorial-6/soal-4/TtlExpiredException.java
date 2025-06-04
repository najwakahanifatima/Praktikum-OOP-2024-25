public class TtlExpiredException extends RuntimeException {
    public TtlExpiredException(String key) {
        super(key + " expired");
    }
}