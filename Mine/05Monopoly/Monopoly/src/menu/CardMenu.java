package menu;

import java.util.Vector;

import device.OutDevice;
import game.Game;
import skill.Card;
import skill.CardType;
import skill.Skill;
import skill.SkillType;

public class CardMenu extends Menu {

	public CardMenu(int menuType) {
		super(menuType);
	}

	protected void show(OutDevice outDevice) {
		outDevice.drawLn("\n\tChoose Card");
		CardType[] cardTypes = CardType.values();
		Vector<CardType> ownCardTypes = new Vector<CardType>();
		int cardKind = cardTypes.length;
		int[] cardNum = new int[cardKind]; // Is cardNum initialized to 0?
		game = Game.getGame();
		for (Skill skill : Game.getGame().currentPlayer.getSkillVector()) {
			if (skill.getSkillType().equals(SkillType.CARD)) {
				Card card = (Card) skill;
				CardType cardType = card.getCardName();
				cardNum[cardType.ordinal()]++;
				if (!ownCardTypes.contains(cardType)) {
					// ensure there is only one same magic type in the vector
					ownCardTypes.add(cardType);
				}
			}
		}

		for (int i = 0; i < ownCardTypes.size(); i++) {
			outDevice.draw(i + ". " + ownCardTypes.get(i));
			outDevice.drawLn("\t You have " + cardNum[ownCardTypes.get(i).ordinal()] + " left.");
		}

		outDevice.drawLn("-1. Back");
		outDevice.draw("Your choice is: ");
	}

	public boolean doChoice(int choice, OutDevice outDevice) {
		switch (choice) {
		case -1: {
			Game.getGame().setCurrentMenu(MenuID.SKILL_MENU);
			break;
		}
		default: {
			// use different card according to the choice
			// ownCardTypes stores the card type player has
			Vector<CardType> ownCardTypes = new Vector<CardType>();

			for (Skill skill : Game.getGame().currentPlayer.getSkillVector()) {
				if (skill.getSkillType().equals(SkillType.CARD)) {
					Card card = (Card) skill;
					CardType cardType = card.getCardName();
					if (!ownCardTypes.contains(cardType)) {
						// ensure there is only one same magic type in the vector
						ownCardTypes.add(cardType);
					}
				}
			}
			
			if (choice >= ownCardTypes.size()) {
				Game.getGame().setCurrentMenu(MenuID.SKILL_MENU);
				break;
			}
			
			CardType currentCardType = ownCardTypes.get(choice);
			Card currentCard = Game.getGame().getCard(currentCardType);
			// After getting the card, Player should be designated
			currentCard.setExecutePlayer(Game.getGame().currentPlayer);

			Game.getGame().currentPlayer.useSkill(currentCard); // here has some bug
			Game.getGame().setCurrentMenu(MenuID.PLAY_MENU);
		}
		}
		return true;
	}
}
