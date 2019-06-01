import java.util.Vector;

public class SunMapDirector extends MapDirector {
	/**
	* This class is used to direct how to create SunMap
	*/

	/**
	* create SunMap
	* @param mapBuilder : it should be a object CommonMapBuilder, whose param is 5*5
	* @return : return a RectangularMap object
	*/
	public Map createMap(MapBuilder mapBuilder){
		Vector<Block> blocks;
		
		MapImp mapImp = new MapImp(5, 5);
		Map sunMap = new SunMap(mapImp);
		
		for (int i = 0; i < 5; i++) {  //if you want to modify the object actively, you just need to modify the BlockType in the loop body 
			mapBuilder.addBlock(BlockType.MONEY_BLOCK, 0, i);
			mapBuilder.addBlock(BlockType.MONEY_BLOCK, 4, i);

			mapBuilder.addBlock(BlockType.BAR_BLOCK, 2, i);
		}
		
		mapBuilder.addBlock(BlockType.TRIP_BLOCK, 1, 0);
		mapBuilder.addBlock(BlockType.TRIP_BLOCK, 1, 4);
		
		mapBuilder.addBlock(BlockType.SLIDE_BLOCK, 3, 0);
		mapBuilder.addBlock(BlockType.SLIDE_BLOCK, 3, 4);
		
		blocks = mapBuilder.getBlockList();
		sunMap.setBlockVector(blocks);
		
		return sunMap;
	}
}