package skill;

import player.Player;

public abstract class Card extends Skill {
	protected CardType cardName;
	protected Player targetPlayer;

	public Card(Player executePlayer) {
		this.executePlayer = executePlayer;
	}

	public CardType getCardName() {
		return this.cardName;
	}

	public void setTargetPlayer(Player targetPlayer) {
		this.targetPlayer = targetPlayer;
	}

	public void apply(Player player) {

	}
}
