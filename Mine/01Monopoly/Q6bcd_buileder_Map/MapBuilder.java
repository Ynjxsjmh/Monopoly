public abstract class MapBuilder {
	protected Block[][] blockList;
	
	public MapBuilder();
	
	public abstract void addBlock(BlockType blockType) {}
	
	public abstract Block[][] getBlockList() {return null;}
}