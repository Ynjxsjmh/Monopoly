package map;
import java.util.Vector;

import block.BarBlock;
import block.Block;
import block.BlockCache;
import block.BlockType;
import block.EBlock;
import block.FBlock;
import block.MoneyBlock;
import block.SlideBlock;
import block.TripBlock;

public class CommonMapBuilder extends MapBuilder {
	/**
	* the reason why named common is that only 5 types of block can be created
	*/

	public CommonMapBuilder() { 
		blocks = new Vector<Block>();
	}
	
	/**
	add specific object block for blockList
    @param blockType create which kind of block
    @param x the horizontal position of block (take the upper left block as (0,0), and the direction of x axis is down)
	@param y the coordinate position of block
    */
	public void addBlock(BlockType blockType, int x, int y) {
		Block block;
		switch (blockType) {
			case MONEY_BLOCK:
				block = new MoneyBlock();
				break;
			case TRIP_BLOCK:
				block = new TripBlock();
				break;
			case BAR_BLOCK:
				block = new BarBlock();
				break;
			case SLIDE_BLOCK:
				block = new SlideBlock();
				break;
			case E_BLOCK:
				block = new EBlock();
				break;
			case F_BLOCK:
				block = new FBlock();
				break;
			// block = BlockCache.getBlock(blockType); break; //This time each block is different, so couldn't use this design pattern
			default:
			block = null;
		}
		block.setPosition(x, y);
		blocks.add(block);
	}
}