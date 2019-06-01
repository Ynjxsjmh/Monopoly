package map;
import java.util.Vector;

import block.Block;
import block.BlockType;

public abstract class MapBuilder {
	protected Vector<Block> blocks;

	public MapBuilder() { }

	public abstract void addBlock(BlockType blockType, int x, int y);

	public Vector<Block> getBlockList(){
		return blocks;
	}
}