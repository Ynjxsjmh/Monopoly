public class RectangleMap extends Map {
	/**
	* 此类是口字形的地图，图为
	*
	* A A A A A
	* B       B
	* C       C
	* D       D
	* A A A A A
	*/
    public RectangleMap(BlockFactory blockFactory) {
		super(blockFactory);
        name = "RectangleMap";
    }
	
	protected initBlockList(){
		blockList = new BlockList[5][5];
		Block block = blockFactory.createBlock("WallBlock");
		for (int i = 0; i < blockList.length; i++){
			for (int j = 0; j < blockList[i].length; j++) {
				blockList[i][j] = block;
			}
		}
		
		for (int i = 0; i < 5; i++) {
			blockList[0][i] = blockFactory.createBlock("MoneyBlock");
			blockList[4][i] = blockFactory.createBlock("MoneyBlock");
		}
		
		blockList[1][0] = blockFactory.createBlock("TripBlock");
		blockList[1][4] = blockFactory.createBlock("TripBlock");
		
		blockList[2][0] = blockFactory.createBlock("BarBlock");
		blockList[2][4] = blockFactory.createBlock("BarBlock");
		
		blockList[3][0] = blockFactory.createBlock("SlideBlock");
		blockList[3][4] = blockFactory.createBlock("SlideBlock");
	}
}