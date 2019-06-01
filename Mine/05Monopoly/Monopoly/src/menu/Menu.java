package menu;

import java.util.*;

import device.OutDevice;
import device.SpaceDecorator;
import game.Game;

public abstract class Menu {
	protected Game game;
	protected int menuType;

	public Menu(int menuType) {
		this.game = Game.getGame();
		this.menuType = menuType;
	}

	public boolean process() {
		// System.out.println("Menu menu hashCodeÎª£º" + menu.hashCode());
		OutDevice spaceOutDevice = new SpaceDecorator(Game.getGame().getDevice());
		this.show(spaceOutDevice);

		int choice = 1;

		if (!(!Game.getGame().players.element().getIsHuman()  // if the player is computer
				&& Game.getGame().getCurrentMenuType() == MenuID.PLAY_MENU)) {
			choice = getChoice(); // If it's human's turn, wait and get his choice
		} else {
			System.out.println();
		}

		return doChoice(choice, Game.getGame().getDevice());
	}

	protected abstract void show(OutDevice outDevice);

	protected int getChoice() {
		int choice = 0;
		Scanner scanner = new Scanner(System.in);
		choice = scanner.nextInt();
		// scanner.close();
		return choice;
	}

	public int getMenuType() {
		return menuType;
	}

	public abstract boolean doChoice(int choice, OutDevice outDevice);
}
