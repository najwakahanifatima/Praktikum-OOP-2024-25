public class Email {
    private String email; 
    public Email(String email) {
        this.email = email;
    };
    
    public boolean validateEmail() throws Exception {
        if (email.isEmpty()) throw new InvalidEmailException("Email tidak boleh kosong");
        if (email.charAt(0) == '@') throw new InvalidEmailException("@ tidak boleh di awal email");
        int atIdx = email.indexOf('@');
        int at2Idx = email.indexOf('@', atIdx + 1);
        if (!(email.contains("@")) || at2Idx != -1) throw  new InvalidEmailException("Email harus mengandung tepat satu buah @");
        String domain = email.substring(atIdx+1);
        int lastDotIdx = domain.lastIndexOf('.');
        int firstDotIdx = domain.indexOf('.');
        if (!domain.contains(".") || lastDotIdx != firstDotIdx || lastDotIdx == domain.length()-1 || firstDotIdx == 0) throw new InvalidDomainException();
        return true;
        /**
         * Implementasi dengan aturan:
         * Aturan email
         * - Email harus mengandung tepat 1 karakter @ ditengah email
         * - Bagian sebelum @ tidak boleh kosong
         * - Bagian email setelah @ harus memiliki tepat 1 buah titik (.)
         * - Email hanya akan mengandung huruf, angka, (@), dan (.). Karakter lain tidak
         * perlu diperiksa
         * 
         * "john@example.com" => Email Valid
         * "jane.doe@gmail.com" => Email Valid
         * "" => mengembalikan pesan "Email tidak boleh kosong"
         * "example.com" => mengembalikan pesan "Email harus mengandung tepat satu buah @"
         * "@example.com" => mengembalikan pesan "@ tidak boleh di awal email"
         * "john@com" => mengembalikan pesan "Email harus memiliki domain yang valid"
         */
    }

    // public static void main(String args[]) {
    //     Email[] tc = new Email[6];
    //     tc[0] = new Email("john@example.com");
    //     tc[1] = new Email("jane.doe@gma.il.com");
    //     tc[2] = new Email("john@com");
    //     tc[3] = new Email("john@.com");
    //     tc[4] = new Email("john@com.");
    //     tc[5] = new Email("john@com");

    //     for (int i = 0; i < 6; i++) {
    //         try {
    //             if (tc[i].validateEmail()) {
    //                 System.out.println("VALID");
    //             }
    //         } catch (Exception e) {
    //             System.out.println(e.getMessage());
    //         }
    //     }
    //  }

}

class InvalidEmailException extends Exception {
    public InvalidEmailException(String message) {
        super(message);
    }
}

class InvalidDomainException extends Exception {
    @Override
    public String getMessage() {
        return "Email harus memiliki domain yang valid";
    }
}