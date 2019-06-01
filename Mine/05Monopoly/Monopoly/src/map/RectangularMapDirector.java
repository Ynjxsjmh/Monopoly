package map;

import java.util.Hashtable;
import java.util.Vector;

import block.Block;
import block.BlockType;

public class RectangularMapDirector extends MapDirector {
	
	/**
	 * create RectangularMap
	 * 
	 * @param mapBuilder
	 *            : it should be a object CommonMapBuilder, whose param is 5*5
	 * @return : return a RectangularMap object
	 */
	public Map createMap(MapBuilder mapBuilder) {
		Vector<Block> blocks;

		MapImp mapImp = new MapImp(5, 5);
		Map rectangularMap = new RectangularMap(mapImp);
		
		int[][] layout = {
				{1, 1, 0, 0, 0, 2, 0, 6},
				{1, 2, 0, 1, 1, 3, 0, 0},
				{1, 3, 0, 2, 2, 4, 0, 0},
				{1, 4, 0, 3, 3, 5, 0, 0},
				{1, 5, 0, 4, 4, 0, 0, 7},
				{2, 6, 1, 0, 0, 0, 1, 8},
				{2, 7, 1, 4, 0, 0, 5, 9},
				{3, 8, 2, 0, 0, 0, 6, 10},
				{3, 9, 2, 4, 0, 0, 7, 11},
				{4, 10, 3, 0, 0, 0, 8, 12},
				{4, 11, 3, 4, 0, 0, 9, 16},
				{1, 12, 4, 0, 0, 13, 10, 0},
				{1, 13, 4, 1, 12, 14, 0, 0},
				{1, 14, 4, 2, 13, 15, 0, 0},
				{1, 15, 4, 3, 14, 16, 0, 0},
				{1, 16, 4, 4, 15, 0, 11, 0},
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

		for (int i = 0; i < layout.length; i++) {
			Block block = blocks.get(i);
	        if(layout[i][4] > 0) {
	            block.setNeighbor(DirectionID.DIR_LEFT, blocks.get(layout[i][4]-1));
	        }
	        if(layout[i][5] > 0) {
	        	block.setNeighbor(DirectionID.DIR_RIGHT, blocks.get(layout[i][5]-1));
	        }
	        if(layout[i][6] > 0) {
	        	block.setNeighbor(DirectionID.DIR_UP, blocks.get(layout[i][6]-1));
	        }
	        if(layout[i][7] > 0) {
	        	block.setNeighbor(DirectionID.DIR_DOWN, blocks.get(layout[i][7]-1));
	        }
	        blocks.set(i, block);
		}
		
		rectangularMap.setBlockVector(blocks);

		return rectangularMap;
	}
}
