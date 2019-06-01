package menu;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Vector;

import block.Block;
import device.OutDevice;
import game.Game;
import map.DirectionID;
import player.Player;

public class PlayMenu extends Menu {
	public PlayMenu(int menuType) {
		super(menuType);
	}

	protected void show(OutDevice outDevice) {
		System.out.println("\n-----------------current menu-------------------------------");
		// show the current map convenient for human choosing
		Game.getGame().getCurrentMap().show();
		
		outDevice.drawLn("\n\tPlayMenu:");
		outDevice.drawLn("1. Go¡­");
		outDevice.drawLn("2. Load");
		outDevice.drawLn("3. Save");
		outDevice.drawLn("4. Back To MainMenu");
		outDevice.draw("Your choice is: ");
	}

	public boolean doChoice(int choice, OutDevice outDevice) {
		// human and computers do different thing here.
		// human do choice but computer go on directly
		// auto player complete its turn in Menu.process()
		
		Player player = Game.getGame().players.poll();
		System.out.println("--------------------------------------------------");
		System.out.println("PlayMenu.doChoice()");
		System.out.println("current player is " + player.getName());
		System.out.println("His type is " + player.getType());
		System.out.println("--------------------------------------------------");
		Game.getGame().players.offer(player);

		switch (choice) {
		case 1: {
			// choose 1.go so go on walking
			
			int step = 0;
			
			if (player.getType().equals("HUMAN_TYPE")) {
				step = 3;
			} else {
				step = 2;
			}
			
			int count = 0;

			Block currentBlock = null;
			Vector<Block> blocks = Game.getGame().getCurrentMap().getBlockVector();
			for (Block tempBlock : blocks) {
				if ((tempBlock.getRow() == player.x) && (tempBlock.getCol() == player.y)) {
					currentBlock = tempBlock;
					break;
				}
			}
			// Counterclockwise search for feasible paths

			Block nextBlock = currentBlock;
			
			int curentDirection = player.direction;
			Queue<Integer> directionQueue = new LinkedList<Integer>();
			for (int i=curentDirection; i<(curentDirection+DirectionID.DIR_COUNT-1); i++) {
				if (i > 4) {
					directionQueue.offer(i-4);
				} else {
					directionQueue.offer(i);
				}
			}
			
			while(true) {
				while (nextBlock.getNeighbor(curentDirection) != null) {
					nextBlock = nextBlock.getNeighbor(curentDirection);
					count ++;
					
					if (count == step) {
						break;
					}
				}
				if (count == step) {
					break;
				}

				directionQueue.poll();
				directionQueue.offer(curentDirection);
				curentDirection = directionQueue.peek();
			}
			
			player.direction = curentDirection;
			player.x = nextBlock.getRow();
			player.y = nextBlock.getCol();
			
			System.out.println("\n-----------------after move-------------------------------");
			Game.getGame().getCurrentMap().show();

			Game.getGame().setCurrentMenu(MenuID.PLAY_MENU);
			break;
		} // show current map
		case 2: {
			Game.getGame().setCurrentMenu(MenuID.LOAD_MENU);
			break;
		}
		case 3: {
			Game.getGame().setCurrentMenu(MenuID.SAVE_MENU);
			break;
		}
		case 4: {
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
