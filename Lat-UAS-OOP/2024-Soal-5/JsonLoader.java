import java.lang.reflect.Array;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class JsonLoader {
  public String serialize(Object obj)
      throws IllegalArgumentException, IllegalAccessException {
    if (obj == null) {
      return "null";
    }

    if (obj instanceof String) {
      return "\"" + obj.toString() + "\"";
    } else if (obj instanceof Integer || obj instanceof Long ||
               obj instanceof Float || obj instanceof Double) {
      return obj.toString();
    } else if (obj instanceof Boolean) {
      return obj.toString().toLowerCase();
    } else if (obj.getClass().isArray()) {
      return serializeArray(obj);
    } else if (obj instanceof Iterable<?>) {
      return serializeIterable((Iterable<?>)obj);
    } else if (obj instanceof Map<?, ?>) {
      return serializeMap((Map<?, ?>)obj);
    } else {
      return serializeObject(obj);
    }
  }

  private String serializeArray(Object array)
      throws ArrayIndexOutOfBoundsException, IllegalArgumentException,
             IllegalAccessException {
    List<String> arr = new ArrayList<>();
    for (int i = 0; i < Array.getLength(array); i++) {
      Object val = Array.get(array, i);
      String serialized = serialize(val);
      arr.add(serialized);
    }
    return "[" + String.join(",", arr) + "]";
  }

  private String serializeIterable(Iterable<?> collection)
      throws IllegalArgumentException, IllegalAccessException {
    List<String> arr = new ArrayList<>();
    for (Object val : collection) {
      String serialized = serialize(val);
      arr.add(serialized);
    }
    return "[" + String.join(",", arr) + "]";
  }

  private String serializeObject(Object obj)
      throws IllegalArgumentException, IllegalAccessException {
    // Implementasikan method ini dengan langkah-langkah sebagai berikut
    // iterasi untuk setiap field yang ada pada objek
    // jika field memiliki anotasi JsonField, maka: (gunakan method `field.isAnnotationPresent(JsonField.class)` untuk mengecek anotasi)
    //    cek apakah field tersebut memiliki nilai serialized=true
    //    jika tidak, maka lanjut ke field berikutnya
    //    ambil nama field dari anotasi JsonField, jika tidak ada, maka ambil nama field
    //    ambil nilai field
    //    serialize nilai field
    //    tambahkan hasil nama:nilai pada hasil serialisasi
    // jika tidak, maka:
    //    ambil nama field
    //    ambil nilai field
    //    serialize nilai field
    //    tambahkan hasil nama:nilai pada hasil serialisasi

    // NOTE: hati-hati terhadap petik ganda yang diperlukan pada nama field
    StringBuilder sb = new StringBuilder();
    sb.append('{');
    Class<?> clazz = obj.getClass();
    Field[] fields = clazz.getDeclaredFields();
    int cnt = fields.length;
    for (Field f : fields) {
      cnt--;
      f.setAccessible(true);

      if (f.isAnnotationPresent(JsonField.class)) {
        JsonField annotation =  f.getAnnotation(JsonField.class);
        if (!annotation.serialized()) continue;
        String fieldName = annotation.name().isEmpty() ? f.getName() : annotation.name();
        Object val = f.get(obj);
        sb.append('\"').append(fieldName).append('\"')
          .append(':').append(serialize(val));
      } else {
        String fieldName = f.getName();
        Object val = f.get(obj);
        sb.append('\"').append(fieldName).append('\"')
        .append(':').append(serialize(val));
      }
      if (cnt != 0) {
        sb.append(',');
      }
    }
    sb.append('}');
    return sb.toString();
    
  }

  private String serializeMap(Map<?, ?> map)
      throws IllegalArgumentException, IllegalAccessException {
    List<String> fields = new ArrayList<>();
    for (Map.Entry<?, ?> entry : map.entrySet()) {
      String key = serialize(entry.getKey());
      String value = serialize(entry.getValue());
      fields.add(key + ":" + value);
    }
    return "{" + String.join(",", fields) + "}";
  }
}