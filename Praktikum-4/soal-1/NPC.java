public class NPC extends Unit implements Interactable {
    private String dialogue;

    public NPC() {
        super("NPC1", 100);
        this.dialogue = "Hello there!";
    }

    public NPC(String name, int health, String dialogue) {
        super(name, health);
        this.dialogue = dialogue;
    }

    public String getDialogue() {
        return this.dialogue;
    }
    
    public void setDialogue(String d) {
        this.dialogue = d;
    }

    public void interact() {
        System.out.println(dialogue);
    }

    public String toString() {
        return (this.name + " [Health: " + this.health + ", Dialogue: " + this.dialogue + "]");
    }
}