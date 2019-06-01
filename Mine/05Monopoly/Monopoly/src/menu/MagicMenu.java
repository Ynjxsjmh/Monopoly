package menu;

import java.util.Vector;

import device.OutDevice;
import game.Game;
import skill.Magic;
import skill.MagicType;
import skill.Skill;
import skill.SkillType;

public class MagicMenu extends Menu {
	public MagicMenu(int menuType) {
		super(menuType);
	}

	protected void show(OutDevice outDevice) {
		outDevice.drawLn("\n\tChoose Magic");
		MagicType[] magicTypes = MagicType.values();
		Vector<MagicType> ownMagicTypes = new Vector<MagicType>();
		int magicKind = magicTypes.length;
		int[] magicNum = new int[magicKind]; // Is magicNum initialized to 0?
		for (Skill skill : Game.getGame().currentPlayer.getSkillVector()) {
			if (skill.getSkillType().equals(SkillType.MAGIC)) {
				Magic magic = (Magic) skill;
				MagicType magicType = magic.getMagicName();
				magicNum[magicType.ordinal()]++;
				if (!ownMagicTypes.contains(magicType)) {
					// ensure there is only one same magic type in the vector
					ownMagicTypes.add(magicType);
				}
			}
		}

		for (int i = 0; i < ownMagicTypes.size(); i++) {
			outDevice.draw(i + ". " + ownMagicTypes.get(i));
			outDevice.drawLn("\t You have " + magicNum[ownMagicTypes.get(i).ordinal()] + " left.");
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
			Vector<MagicType> ownMagicTypes = new Vector<MagicType>();

			for (Skill skill : Game.getGame().currentPlayer.getSkillVector()) {
				if (skill.getSkillType().equals(SkillType.MAGIC)) {
					Magic magic = (Magic) skill;
					MagicType magicType = magic.getMagicName();
					if (!ownMagicTypes.contains(magicType)) {
						// ensure there is only one same magic type in the vector
						ownMagicTypes.add(magicType);
					}
				}
			}
			
			if (choice >= ownMagicTypes.size()) {
				Game.getGame().setCurrentMenu(MenuID.SKILL_MENU);
				break;
			}
			
			MagicType currentMagicType = ownMagicTypes.get(choice);
			Magic currentMagic = Game.getGame().getMagic(currentMagicType);
			// After getting the card, Player should be designated
			currentMagic.setExecutePlayer(Game.getGame().currentPlayer);
			Game.getGame().currentPlayer.useSkill(currentMagic);

			Game.getGame().setCurrentMenu(MenuID.PLAY_MENU);
		}
		}
		return true;
	}
}
