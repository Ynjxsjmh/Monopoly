package menu;

import device.OutDevice;
import game.Game;
import player.Player;

public class PlayMenu extends Menu {
	public PlayMenu(int menuType) {
		super(menuType);
	}

	protected void show(OutDevice outDevice) {
		System.out.println("\n-----------------current menu-------------------------------");
		// show the current map convenient for human choosing
		Game.getGame().getCurrentMap().show();

		System.out.println("\n-----------------current Info-------------------------------");
		Game.getGame().showInfo();

		outDevice.drawLn("\n\tPlayMenu:");
		outDevice.drawLn("1. Go¡­");
		outDevice.drawLn("2. useSkill");
		outDevice.drawLn("3. Load");
		outDevice.drawLn("4. Save");
		outDevice.drawLn("5. Back To MainMenu");
		outDevice.draw("Your choice is: ");
	}

	public boolean doChoice(int choice, OutDevice outDevice) {
		// human and computers do different thing here.
		// human do choice but computer go on directly
		// auto player complete its turn in Menu.process()

		switch (choice) {
		case 1: {
			// choose 1.go so go on walking

			Player player = Game.getGame().players.poll();
			System.out.println("--------------------------------------------------");
			System.out.println("PlayMenu.doChoice()");
			System.out.println("current player is " + player.getID());
			System.out.println("His type is " + (player.getIsHuman() ? "HUMAN" : "AUTO"));
			System.out.println("--------------------------------------------------");
			Game.getGame().players.offer(player);
			Game.getGame().currentPlayer = player;

			player.move();

			// int step = 0;
			//
			// if (player.getType().equals("HUMAN_TYPE")) {
			// step = 3;
			// } else {
			// step = 2;
			// }
			//
			// int count = 0;
			//
			// Block currentBlock = player.getCurrentBlock();
			//
			// Block nextBlock = currentBlock;
			//
			// Counterclockwise search for feasible paths
			// int curentDirection = player.direction;
			// Queue<Integer> directionQueue = new LinkedList<Integer>();
			// for (int i=curentDirection; i<(curentDirection+DirectionID.DIR_COUNT-1); i++)
			// {
			// if (i > 4) {
			// directionQueue.offer(i-4);
			// } else {
			// directionQueue.offer(i);
			// }
			// } // now current direction is the first element in this queue
			//
			// while(true) {
			// while (nextBlock.getNeighbor(curentDirection) != null) {
			// nextBlock = nextBlock.getNeighbor(curentDirection);
			// count ++;
			//
			// if (count == step) {
			// break;
			// }
			// }
			// if (count == step) {
			// break;
			// }
			//
			// directionQueue.poll();
			// directionQueue.offer(curentDirection);
			// curentDirection = directionQueue.peek();
			// }
			// search end
			// player.direction = curentDirection;
			// player.x = nextBlock.getRow();
			// player.y = nextBlock.getCol();

			// show current map
			System.out.println("\n-----------------after move-------------------------------");
			Game.getGame().getCurrentMap().show();

			Game.getGame().setCurrentMenu(MenuID.PLAY_MENU);
			break;
		}
		case 2: {
			Game.getGame().setCurrentMenu(MenuID.SKILL_MENU);
			break;
		}
		case 3: {
			Game.getGame().setCurrentMenu(MenuID.LOAD_MENU);
			break;
		}
		case 4: {
			Game.getGame().setCurrentMenu(MenuID.SAVE_MENU);
			break;
		}
		case 5: {
			Game.getGame().setCurrentMenu(MenuID.MAIN_MENU);
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
