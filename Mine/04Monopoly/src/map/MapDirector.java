package map;
import java.util.Vector;

import block.Block;
import block.BlockType;

public class MapDirector {
	/**
	* This class is used to direct how to create Map
	*/

	/**
	* create RectangularMap
	* @param mapBuilder : it should be a object CommonMapBuilder, whose param is 5*5
	* @return : return a RectangularMap object
	*/
	public Map createMap(MapBuilder mapBuilder){
		Vector<Block> blocks;
		
		MapImp mapImp = new MapImp(5, 5);
		Map rectangularMap = new RectangularMap(mapImp);

		for (int i = 0; i < 5; i++) {
			mapBuilder.addBlock(BlockType.MONEY_BLOCK, 0, i);
			mapBuilder.addBlock(BlockType.MONEY_BLOCK, 4, i);
		}

        mapBuilder.addBlock(BlockType.TRIP_BLOCK, 1, 0);
		mapBuilder.addBlock(BlockType.TRIP_BLOCK, 1, 4);

		mapBuilder.addBlock(BlockType.BAR_BLOCK, 2, 0);
		mapBuilder.addBlock(BlockType.BAR_BLOCK, 2, 4);

		mapBuilder.addBlock(BlockType.SLIDE_BLOCK, 3, 0);
		mapBuilder.addBlock(BlockType.SLIDE_BLOCK, 3, 4);

		blocks = mapBuilder.getBlockList();
		
		rectangularMap.setBlockVector(blocks);

		return rectangularMap;
	}
}