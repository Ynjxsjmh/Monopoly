public class CommomMapBuilder extends MapBuilder {
	/**
	* 目前只能创造出5种block，因此叫common
	*/
	
	
	protected Block[][] blockList;
	
	/**
    构造函数
    @param row 地图的行数
	@param column 地图的列数
    */	
	public CommomMapBuilder(int row, int column) {  //人工指定地图长和宽
		blockList = new Block[row][column];
		Block block = new WallBlock();
		for (int i = 0; i < blockList.length; i++){
			for (int j = 0; j < blockList[i].length; j++) {
				blockList[i][j] = block;
			}
		}
	}
	
	/**
    给blockList添加元素block
    @param blockType 创建什么类型的块
    @param x 块的横坐标（以右上角的块为原点，x轴指向下）
	@param y 块的纵坐标
    */
	public void addBlock(BlockType blockType, int x, int y) {
		Block block;
		switch (blockType) {
			case MONEY_BLOCK:
			block = new MoneyBlock();
			case TRIP_BLOCK:
			block = new TripBlock();
			case BAR_BLOCK:
			block = new BarBlock();
			case SLIDE_BLOCK:
			block = new SlideBlock();
			default:
			block = null;
		}
		blockList[x][y] = block;
	}
	
	public Block[][] getBlockList(){
		return blockList;
	}
}