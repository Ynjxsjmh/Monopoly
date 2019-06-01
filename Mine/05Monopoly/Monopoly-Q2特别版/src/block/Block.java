package block;

import map.DirectionID;

public abstract class Block implements Cloneable {
    protected String name;
    protected String function;
    protected String abbr;
	protected int row;
	protected int col;
	protected Block centerBlock;
	protected Block[] neighbors = new Block[DirectionID.DIR_COUNT];
	
	public Block() {
		// TODO Auto-generated constructor stub
		for (int i=0; i<DirectionID.DIR_COUNT; i++) {
			neighbors[i] = null;
		}
	}
	
	
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
    
    public void setNeighbor(int direction, Block block) {
		if(direction > DirectionID.DIR_NONE && direction < DirectionID.DIR_COUNT) {
	        neighbors[direction] = block;
	    }
	}
	
	public Block getNeighbor(int direction) {
		return neighbors[direction];
	}
}