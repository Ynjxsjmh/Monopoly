package skill;

import java.util.Queue;
import java.util.Random;
import java.util.Scanner;

import game.Game;
import player.Player;

public class RobCard extends Card{
	// rob the targetPlayer of half of his money
	public RobCard(Player executePlayer) {
		super(executePlayer);
		this.skillType = SkillType.CARD;
		this.cardName = CardType.ROB_CARD;
		this.skillName = this.cardName.toString();
	}

	@Override
	public void execute(int targetPlayerNum) {
		Player targetPlayer = Game.getGame().getSpecificPlayer(targetPlayerNum);
		int playerID = 0;
		if (Game.getGame().currentPlayer.getIsHuman()) {
			System.out.println("\n You are using RobCard, please designate the target player");
			Scanner scanner = new Scanner(System.in);
			playerID = scanner.nextInt();
		} else {
			Queue<Player> choosePlayers = Game.getGame().players;
			choosePlayers.remove(Game.getGame().currentPlayer);
			Random random = new Random();
			int choose = random.nextInt(choosePlayers.size()+1);
			while((choose--)>0) {
				playerID = choosePlayers.poll().getID();
			}
		}
		targetPlayer = Game.getGame().getSpecificPlayer(playerID);

		executePlayer.money += targetPlayer.money / 2;
		targetPlayer.money /= 2;
	}
}
