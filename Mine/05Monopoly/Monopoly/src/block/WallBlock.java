package block;

public class WallBlock extends Block {
    public WallBlock() {
        blockType = BlockType.WALL_BLOCK;
        function = "This is a WallBlock, it couldn't be reached";
        abbr = " ";
    }
}