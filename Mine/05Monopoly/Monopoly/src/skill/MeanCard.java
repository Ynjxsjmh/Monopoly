package skill;

import java.util.Queue;

import game.Game;
import player.Player;

public class MeanCard extends Card {
	// Equalize every player's money
	public MeanCard(Player executePlayer) {
		super(executePlayer);
		this.skillType = SkillType.CARD;
		this.cardName = CardType.MEAN_CARD;
		this.skillName = this.cardName.toString();
	}

	@Override
	public void execute(int targetPlayerNum) {
		Queue<Player> players = Game.getGame().players;
		float sumMoney = 0;
		float averageMoney = 0;
		
		for (Player player:players) {
			sumMoney += player.money;
		}
		
		averageMoney = sumMoney/Game.getGame().getPlayerNum();

		for (Player player:players) {
			player.money = averageMoney;
		}
	}
}
