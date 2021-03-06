public class MapDirector {
	/**
	* This class is used to direct how to create Map
	* It needs some improvement, such as there is no need to new Block every time.
	*/

	/**
	* create RectangularMap
	* @param mapBuilder : it should be a object CommonMapBuilder, whose param is 5*5
	* @return : return a RectangularMap object
	*/
    public Map createRectangularMap(MapBuilder mapBuilder){
		Block[][] blockList;
		Map rectangularMap = new RectangularMap();

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

		blockList = mapBuilder.getBlockList();
		rectangularMap.setBlockList(blockList);

		return rectangularMap;
	}

	/**
	* create SunMap
	*/
	public Map createSunMap(MapBuilder mapBuilder){
		Block[][] blockList;
		Map sunMap = new SunMap();

		for (int i = 0; i < 5; i++) {
			mapBuilder.addBlock(BlockType.MONEY_BLOCK, 0, i);
			mapBuilder.addBlock(BlockType.MONEY_BLOCK, 4, i);

			mapBuilder.addBlock(BlockType.BAR_BLOCK, 2, i);
		}

        mapBuilder.addBlock(BlockType.TRIP_BLOCK, 1, 0);
		mapBuilder.addBlock(BlockType.TRIP_BLOCK, 1, 4);

		mapBuilder.addBlock(BlockType.SLIDE_BLOCK, 3, 0);
		mapBuilder.addBlock(BlockType.SLIDE_BLOCK, 3, 4);

		blockList = mapBuilder.getBlockList();
		sunMap.setBlockList(blockList);

		return sunMap;
	}
}