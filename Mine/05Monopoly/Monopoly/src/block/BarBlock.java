package block;

import player.Player;

public class BarBlock extends Block {
    public BarBlock() {
        blockType = BlockType.BAR_BLOCK;
        function = "A BarBlock is on your way, you are barred to go on.";
        abbr = "C";
    }
    
    public boolean blockEffect(Player player) {
		return true;
	}
}