public class MapDirector {
	/**
	* 此类是用来指导如何创建Map的
	* 当然，还有一些不足之处，比如不必每次都new Block出来，只用new一次就行。
	*/
	
	/**
	* 创建口字形的地图
	* @param mapBuilder 原则上传入的是一个CommonMapBuilder对象，此对象为5×5的
	* @return 返回的是一个 RectangularMap
	*/
    public Map createRectangularMap(MapBuilder mapBuiler){
		Block[][] blockList;
		Map rectangularMap = new RectangularMap();
		
		for (int i = 0; i < 5; i++) {
			mapBuiler.addBlock(BlockType.MONEY_BLOCK, 0, i);
			mapBuiler.addBlock(BlockType.MONEY_BLOCK, 4, i);
		}
		
		mapBuiler.addBlock(BlockType.TRIP_BLOCK, 1, 0);
		mapBuiler.addBlock(BlockType.TRIP_BLOCK, 1, 4);
		
		mapBuiler.addBlock(BlockType.BAR_BLOCK, 2, 0);
		mapBuiler.addBlock(BlockType.BAR_BLOCK, 2, 4);
		
		mapBuiler.addBlock(BlockType.SLIDE_BLOCK, 3, 0);
		mapBuiler.addBlock(BlockType.SLIDE_BLOCK, 3, 4);
		
		blockList = mapBuiler.getBlockList();
		rectangularMap.setBlockList(blockList);
		
		return rectangularMap;
	}
	
	/**
	* 创建日字形的地图
	*/
	public Map createSunMap(MapBuilder mapBuiler){
		Block[][] blockList;
		Map sunMap = new SunMap();
		
		for (int i = 0; i < 5; i++) {
			mapBuiler.addBlock(BlockType.MONEY_BLOCK, 0, i);
			mapBuiler.addBlock(BlockType.MONEY_BLOCK, 4, i);

			mapBuiler.addBlock(BlockType.BAR_BLOCK, 2, i);
		}
		
		mapBuiler.addBlock(BlockType.TRIP_BLOCK, 1, 0);
		mapBuiler.addBlock(BlockType.TRIP_BLOCK, 1, 4);
		
		mapBuiler.addBlock(BlockType.SLIDE_BLOCK, 3, 0);
		mapBuiler.addBlock(BlockType.SLIDE_BLOCK, 3, 4);
		
		blockList = mapBuiler.getBlockList();
		sunMap.setBlockList(blockList);
		
		return sunMap;
	}
}