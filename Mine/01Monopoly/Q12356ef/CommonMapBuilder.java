public class CommonMapBuilder extends MapBuilder {
	/**
	* the reason why named common is that only 5 types of block can be created
	*/
	
	/**
    constructor
    @param row : the row of the map
	@param column : the column of the map
    */	
	public CommonMapBuilder(int row, int column) {   //manually specify the row and column
		blockList = new Block[row][column];
		Block block = new WallBlock();
		for (int i = 0; i < blockList.length; i++){
			for (int j = 0; j < blockList[i].length; j++) {
				blockList[i][j] = block;
			}
		}
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
			case TRIP_BLOCK:
			case BAR_BLOCK:
			case SLIDE_BLOCK:
			case E_BLOCK:
			case F_BLOCK:
			block = BlockCache.getBlock(blockType); break;
			default:
			block = null;
		}
		blockList[x][y] = block;
	}
}