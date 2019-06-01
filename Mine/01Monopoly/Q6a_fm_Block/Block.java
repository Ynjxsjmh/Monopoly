public abstract class Block implements Cloneable {
    String name;
    String function;
    String abbr;

    public String getName(){
        return name;
    }

    public String toString() {
        StringBuffer display = new StringBuffer();
        display.append(abbr)
        return display.toString();
    }
}