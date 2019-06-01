package menu;

import java.util.Vector;

import block.Block;
import block.BlockType;
import device.OutDevice;
import device.SpaceDecorator;
import device.StreamDevice;
import game.Game;
import map.CommonMapBuilder;
import map.MapBuilder;
import map.MapMgr;
import map.MapType;

public class MainMenu extends Menu {
	public MainMenu(int menuType) {
		super(menuType);
	}

	public boolean process() {
		// System.out.println("Menu menu hashCodeÎª£º" + menu.hashCode());
		OutDevice outDevice = new StreamDevice();
		OutDevice spaceOutDevice = new SpaceDecorator(outDevice);

		Menu menuTopDecorator = new MenuTopDecorator(this, this.getMenuType());

		menuTopDecorator.show(spaceOutDevice);
		int choice = getChoice();
		return doChoice(choice, outDevice);
	}

	protected void show(OutDevice outDevice) {
		outDevice.drawLn("\n\tÖ÷²Ëµ¥");
		outDevice.drawLn("1. New");
		outDevice.drawLn("2. Load");
		outDevice.drawLn("3. Option");
		outDevice.drawLn("4. Play");
		outDevice.drawLn("5. Change To EF");
		outDevice.drawLn("-1. Exit");
		outDevice.draw("Your choice is: ");
	}

	public boolean doChoice(int choice, OutDevice outDevice) {
		switch (choice) {
		case 1: {
			Game.getGame().setCurrentMenu(MenuID.PLAYERS_MENU);
			break;
		}
		case 2: {
			Game.getGame().setCurrentMenu(MenuID.LOAD_MENU);
			break;
		}
		case 3: {
			Game.getGame().setCurrentMenu(MenuID.OPTION_MENU);
			break;
		}
		case 4: {
			Game.getGame().setCurrentMap(MapMgr.getMapMgr().createMap(MapType.REGULARMAP));
			Game.getGame().setCurrentMenu(MenuID.PLAY_MENU);

			// Game.getGame().setCurrentMap(MapMgr.getMapMgr().createMap(MapType.FLAGMAP));

			// Game.getGame().getCurrentMap().show();
			break;
		}
		case 5: {
			Vector<Block> blocks = MapMgr.getMapMgr().createMap(MapType.SUNMAP).getBlockVector();
			MapBuilder commonMapBuilder = new CommonMapBuilder();

			for (int i = 0; i < 5; i++) { // if you want to modify the object actively, you just need to modify the
											// BlockType in the loop body
				commonMapBuilder.addBlock(BlockType.E_BLOCK, 0, i);
				commonMapBuilder.addBlock(BlockType.E_BLOCK, 4, i);

				commonMapBuilder.addBlock(BlockType.F_BLOCK, 2, i);
			}
			commonMapBuilder.addBlock(BlockType.TRIP_BLOCK, 1, 0);
			commonMapBuilder.addBlock(BlockType.TRIP_BLOCK, 1, 4);

			commonMapBuilder.addBlock(BlockType.SLIDE_BLOCK, 3, 0);
			commonMapBuilder.addBlock(BlockType.SLIDE_BLOCK, 3, 4);

			blocks = commonMapBuilder.getBlockList();
			MapMgr.getMapMgr().currentMap.setBlockVector(blocks);
			Game.getGame().getCurrentMap().show();
			break;
		}
		default:
			return false;
		}
		return true;
	}
}