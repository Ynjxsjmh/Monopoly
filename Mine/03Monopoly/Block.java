public abstract class Block implements Cloneable {
    protected String name;
    protected String function;
    protected String abbr;
	protected int row;
	protected int col;

    public String getName(){
        return name;
    }

	public void setPosition(int r, int c) {
		row=r;
		col=c;
	}

	public int getRow() {
		return row;
	}

	public int getCol() {
		return col;
	}

    public String toString() {
        StringBuffer display = new StringBuffer();
        display.append(abbr);
        return display.toString();
    }

    public Block clone() {
        Block block = null;
		try {
            block = (Block) super.clone();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return block;
    }
}