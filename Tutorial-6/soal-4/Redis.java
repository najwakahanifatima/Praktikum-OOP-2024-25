


public class Redis<K, V> {
    private K key;
    private V val;
    private long ttl;

    public Redis(K k, V v, long ttl) {
        this.key = k;
        this.val = v;
        this.ttl = ttl;
        if (ttl <= 0) {
            throw new InvalidTtlException();
        }
    }

    public K getKey() { return this.key; }
    public void setKey(K newK) { this.key = newK; }
    
    public V getVal(long elapsedSeconds) {
        if (ttl-elapsedSeconds <= 0) { throw new TtlExpiredException(key.toString()); }
        return this.val;
    }

    public void setVal(V newV) { this.val = newV; }

    public long getRemainingTtl(long elapsedSeconds) {
        if (ttl - elapsedSeconds <= 0) {
            return 0;
        }
        return ttl - elapsedSeconds;
    }

    public void  refresh(long newTtl) {
        if (newTtl <= 0) {throw new InvalidTtlException();}
        this.ttl = newTtl;
    }

    public boolean isEqual(Redis<?,?> c) {
        return (c.getKey().equals(this.key) && c.getVal(0).equals(this.val));
    }

    public int nearEQ(Redis<?, ?> c) {
        if (c.getKey().equals(this.key) && c.getVal(0).equals(this.val)) {
            return 3;
        } else if (c.getKey().equals(this.key)) {
            return 1;
        } else if (c.getVal(0).equals(this.val)) {
            return 2;
        } else {
            return 0;
        }
    }
}