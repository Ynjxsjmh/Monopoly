package block;

import map.DirectionID;
import player.Player;

public abstract class Block implements Cloneable {
	protected BlockType blockType;
	protected String function;
	protected String abbr;
	protected int row;
	protected int col;
	protected Block centerBlock;
	protected Block[] neighbors = new Block[DirectionID.DIR_COUNT];
	
	// The flowing attribute is associated with Block.blockEffect()
	protected float money;
	protected int step;

	public Block() {
		// TODO Auto-generated constructor stub
		for (int i = 0; i < DirectionID.DIR_COUNT; i++) {
			neighbors[i] = null;
		}
	}

	public void setPosition(int r, int c) {
		row = r;
		col = c;
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
			// next is using deep clone
			block.centerBlock = (Block) centerBlock.clone();
			block.neighbors = (Block[]) neighbors.clone();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return block;
	}

	public void setNeighbor(int direction, Block block) {
		if (direction > DirectionID.DIR_NONE && direction < DirectionID.DIR_COUNT) {
			neighbors[direction] = block;
		}
	}
	
	public boolean blockEffect(Player player) {
		// if the block can block the player to go on walking,
		// it returns true
		return false;
	}

	public Block getNeighbor(int direction) {
		return neighbors[direction];
	}

	public float getMoney() {
		return money;
	}

	public void setMoney(float money) {
		this.money = money;
	}

	public int getStep() {
		return step;
	}

	public void setStep(int step) {
		this.step = step;
	}
	
	public BlockType getBlockType() {
		return this.blockType;
	}
}