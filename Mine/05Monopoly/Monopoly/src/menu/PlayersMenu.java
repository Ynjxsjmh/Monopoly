package menu;

import device.OutDevice;
import game.Game;
import map.MapMgr;
import map.MapType;
import player.NormalPlayer;
import player.TWHPlayer;

public class PlayersMenu extends Menu {
	public PlayersMenu(int menuType) {
		super(menuType);
	}

	protected void show(OutDevice outDevice) {
		outDevice.drawLn("\n\tSet number of players (2-8):");
		outDevice.drawLn("2. 2");
		outDevice.drawLn("3. 3");
		outDevice.drawLn("4. 4");
		outDevice.drawLn("5. 5");
		outDevice.drawLn("6. 6");
		outDevice.drawLn("7. 7");
		outDevice.drawLn("8. 8");
		outDevice.drawLn("-1. Back");
		outDevice.draw("Your choice is: ");
	}

	public boolean doChoice(int choice, OutDevice outDevice) {
		if (choice >= 2 && choice <= 8)
			Game.getGame().setPlayerNum(choice);

		switch (choice) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8: {
			outDevice.drawLn("Set Players count " + choice + " players game");

			for (int i = 1; i < Game.getGame().getPlayerNum(); i++) {
				Game.getGame().players.offer(new TWHPlayer(i));
			}  // add auto player and human play has been added in Game's constructor

			Game.getGame().setCurrentMap(MapMgr.getMapMgr().createMap(MapType.FLAGMAP)); // set map
			Game.getGame().setCurrentMenu(MenuID.PLAY_MENU);

			break;
		}
		default: {
			Game.getGame().setCurrentMenu(MenuID.MAIN_MENU);
		}
		}
		return true;
	}
}