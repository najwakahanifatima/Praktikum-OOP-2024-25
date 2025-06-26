class Goose {
    private String name;
    private int honk;

    public Goose(){
        this.name = "Horrible";
        this.honk = 1;
    }
    public Goose(String n, int h){
        this.name = n;
        this.honk = h;
    }
    public void steal(String thing){
        System.out.println(name + " steals " + thing);
    }
    public String toString(){
        String s = name + " goose says";
        for (int i = 0; i < honk; i++){
            s += " honk";
        } 
        return s;
    }
    // public static void main(String[] args) {
    //     Goose g = new Goose();
    //     Goose h = new Goose("Sung Jin-woo", 3);
    //     System.out.println(g);
    //     System.out.println(h);
    //     h.steal("dagger");
    //   }

}