package menu;

import device.OutDevice;
import game.Game;

public class ResolutionMenu extends Menu {
	public ResolutionMenu(int menuType) {
		super(menuType);
	}

	protected void show(OutDevice outDevice) {
		outDevice.drawLn("\n\tSet resolution");
		outDevice.drawLn("1. 640X320");
		outDevice.drawLn("2. 800X600");
		outDevice.drawLn("3. 1024X768");
		outDevice.drawLn("-1. Back");
		outDevice.draw("Your choice is: ");
	}

	public boolean doChoice(int choice, OutDevice outDevice) {
		switch (choice) {
		case 1: {
			outDevice.drawLn("Resolution has been set to 640X320");
			Game.getGame().setCurrentMenu(MenuID.OPTION_MENU);
			break;
		}
		case 2: {
			outDevice.drawLn("Resolution has been set to 800X600");
			Game.getGame().setCurrentMenu(MenuID.OPTION_MENU);
			break;
		}
		case 3: {
			outDevice.drawLn("Resolution has been set to 1024X768");
			Game.getGame().setCurrentMenu(MenuID.OPTION_MENU);
			break;
		}
		default: {
			Game.getGame().setCurrentMenu(MenuID.OPTION_MENU);
		}
		}
		// There is no break statement after case. Because after choosing, the menu
		// should be set to option menu in case that players want to set the volume menu
		return true;
	}
}