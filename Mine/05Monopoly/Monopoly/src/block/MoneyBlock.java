package block;

import player.Player;

public class MoneyBlock extends Block {
    public MoneyBlock() {
        blockType = BlockType.MONEY_BLOCK;
        function = "You are in MoneyBlock, you are lucky enough to get some money";
        abbr = "A";
        
        money = 200;
    }
    
    public boolean blockEffect(Player player) {
		player.money += money;
		return false;
	}
}