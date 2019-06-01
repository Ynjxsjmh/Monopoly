package block;

import map.DirectionID;

public class LinkBlock extends Block{
	protected Block centerBlock;
	protected Block[] neighbors = new Block[DirectionID.DIR_COUNT];
	
	public LinkBlock() {
		// TODO Auto-generated constructor stub
		
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
