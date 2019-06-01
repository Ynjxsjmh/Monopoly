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

    public Block clone() {
        try {
            Block block = (Block) super.clone();
        } catch (CloneNotSupprotedException e) {
            e.printStackTree();
        }
        return block;
    }
}