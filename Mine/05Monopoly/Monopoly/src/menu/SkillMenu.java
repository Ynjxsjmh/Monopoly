package menu;

import device.OutDevice;
import game.Game;

public class SkillMenu extends Menu{
	public SkillMenu(int menuType) {
		super(menuType);
	}

	protected void show(OutDevice outDevice) {
		outDevice.drawLn("\n\tChoose Skill");
		outDevice.drawLn("1. Card");
		outDevice.drawLn("2. Magic");
		outDevice.drawLn("-1. Back");
		outDevice.draw("Your choose is: ");
	}

	public boolean doChoice(int choice, OutDevice outDevice) {
		switch (choice) {
		case 1: {
			Game.getGame().setCurrentMenu(MenuID.CARD_MENU);
			break;
		}
		case 2: {
			Game.getGame().setCurrentMenu(MenuID.MAGIC_MENU);
			break;
		}
		default: {
			Game.getGame().setCurrentMenu(MenuID.PLAY_MENU);
			break;
		}
		}
		return true;
	}
}
