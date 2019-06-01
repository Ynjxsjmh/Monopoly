package map;
import java.util.*;

import block.Block;
import block.BlockType;

public class FlagMapDirector extends MapDirector {
	/**
	* This class is used to direct how to create SunMap
	*/

	/**
	* create SunMap
	* @param mapBuilder : it should be a object CommonMapBuilder, whose param is 5*8
	* @return : return a RectangularMap object
	*/
	public Map createMap(MapBuilder mapBuilder){
		Vector<Block> blocks;

		MapImp mapImp = new MapImp(5, 8);
		Map flagMap = new FlagMap(mapImp);

		int[][] layout = {
			{1, 1, 0, 0, 0, 2, 0, 6},
			{1, 2, 0, 1, 1, 3, 0, 0},
			{1, 3, 0, 2, 2, 4, 0, 7},
			{1, 4, 0, 3, 3, 5, 0, 0},
			{1, 5, 0, 4, 4, 0, 0, 8},
			{2, 6, 1, 0, 0, 0, 1, 9},
			{2, 7, 1, 2, 0, 0, 3, 10},
			{2, 8, 1, 4, 0, 0, 5, 12},
			{3, 9, 2, 0, 0, 0, 6, 13},
			{3, 10, 2, 2, 0, 11, 7, 14},
			{3, 11, 2, 3, 10, 12, 0, 0},
			{3, 12, 2, 4, 11, 0, 8, 15},
			{4, 13, 3, 0, 0, 0, 9, 16},
			{4, 14, 3, 2, 0, 0, 10, 18},
			{4, 15, 3, 4, 0, 0, 17, 13, 0},
			{1, 16, 4, 0, 0, 17, 13, 0},
			{1, 17, 4, 1, 16, 18, 0, 0},
			{1, 18, 4, 2, 17, 19, 14, 0},
			{1, 19, 4, 3, 18, 20, 0, 0},
			{1, 20, 4, 4, 19, 21, 15, 0},
			{2, 21, 4, 5, 20, 22, 0, 0},
			{2, 22, 4, 6, 21, 23, 0, 0},
			{2, 23, 4, 7, 22, 0, 0, 0}
		};


		Hashtable<Integer, BlockType> table = new Hashtable<Integer, BlockType>();
		table.put(1, BlockType.MONEY_BLOCK);
		table.put(2, BlockType.TRIP_BLOCK);
		table.put(3, BlockType.BAR_BLOCK);
		table.put(4, BlockType.SLIDE_BLOCK);

		for (int i = 0; i < layout.length; i++) {
			mapBuilder.addBlock(table.get(layout[i][0]), layout[i][2], layout[i][3]);
		}

		blocks = mapBuilder.getBlockList();
		flagMap.setBlockVector(blocks);

		return flagMap;
	}
}
