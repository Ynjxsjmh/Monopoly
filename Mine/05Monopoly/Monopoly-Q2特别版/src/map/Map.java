package map;

import java.util.Vector;

import block.Block;

public abstract class Map {
    protected MapImp mapImp;
    protected String name;

	public Map(MapImp aImp) {
		mapImp = aImp;
	}

	/**
	* show Map
	*/
    public void show() {
        mapImp.show();
    }

	public void addBlock(Block block) {
		mapImp.addBlock(block);
	}

	public Block getBlock(int index){
		return mapImp.getBlock(index);
	}

	public int getRow() {
		return mapImp.getRow();
	}

	public int getCol() {
		return mapImp.getCol();
	}

	public void setBlockVector(Vector<Block> blockVector) {
		mapImp.setBlockVector(blockVector);
	}
	
	public Vector<Block> getBlockVector() {
		return mapImp.getblockVector();
	}	
}