public class MapDirector {
	/**
	* 此类是用来指导如何创建Map的
	*/
	
	/**
	* 创建日字形的地图
	* @param mapBuilder 原则上传入的是一个CommonMapBuilder对象，此对象为5×5的
	* @return 返回的是一个 SunMap
	*/
	public Map createSunMap(MapBuilder mapBuiler){
		Block[][] blockList;
		Map sunMap = new SunMap();
		
		for (int i = 0; i < 5; i++) {  //动态修改的话只需要修改循环体里传递的BlockType即可
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