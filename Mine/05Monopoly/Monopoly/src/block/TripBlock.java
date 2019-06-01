package block;

import player.Player;

public class TripBlock extends Block {
    public TripBlock() {
        blockType = BlockType.TRIP_BLOCK;
        function = "You are in TripBlock, your money suffers.";
        abbr = "B";
        
        money = -100;
    }
    
    public boolean blockEffect(Player player) {
		player.money += money;
		return false;
	}
}