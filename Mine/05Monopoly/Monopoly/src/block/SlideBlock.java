package block;

import player.Player;

public class SlideBlock extends Block {
    public SlideBlock() {
        blockType = BlockType.SLIDE_BLOCK;
        function = "You end in SlideBlock, you are lucky enough to go 2 blocks farther.";
        abbr = "D";
        
        step = 2;
    }
    
    public boolean blockEffect(Player player) {
		player.goOnMoving(step);
		return false;
	}
}