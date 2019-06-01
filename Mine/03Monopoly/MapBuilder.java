import java.util.Vector;

public abstract class MapBuilder {
	protected Vector<Block> blocks;

	public MapBuilder() { }

	public abstract void addBlock(BlockType blockType, int x, int y);

	public Vector<Block> getBlockList(){
		return blocks;
	}
}