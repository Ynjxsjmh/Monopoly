public abstract class MapBuilder {
	protected Block[][] blockList;
	
	public MapBuilder(){ }
	
	public abstract void addBlock(BlockType blockType, int x, int y);
	
	public Block[][] getBlockList(){
		return blockList;
	}
}