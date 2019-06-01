package block;
import java.util.Hashtable;

public class BlockCache {
    private static Hashtable<BlockType, Block> blockMap = new Hashtable<BlockType, Block>();

    public static Block getBlock(BlockType type) {
        Block cachedBlock = blockMap.get(type);
        return (Block) cachedBlock.clone();
    }

    public static void loadCache() {
        Block moneyBlock = new MoneyBlock();
        blockMap.put(BlockType.MONEY_BLOCK, moneyBlock);

        Block tripBlock = new TripBlock();
        blockMap.put(BlockType.TRIP_BLOCK, tripBlock);

        Block barBlock = new BarBlock();
        blockMap.put(BlockType.BAR_BLOCK, barBlock);

        Block slideBlock = new SlideBlock();
        blockMap.put(BlockType.SLIDE_BLOCK, slideBlock);

		Block wallBlock = new WallBlock();
		blockMap.put(BlockType.WALL_BLOCK, wallBlock);

		Block eBlock = new EBlock();
		blockMap.put(BlockType.E_BLOCK, eBlock);

		Block fBlock = new FBlock();
		blockMap.put(BlockType.F_BLOCK, fBlock);
    }
}