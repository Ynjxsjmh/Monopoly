public class MainMenu extends Menu {
	public MainMenu(){
		super();
	}

    protected void show() {
        System.out.println("\n\tÖ÷²Ëµ¥");
        System.out.println("1. New");
        System.out.println("2. Load");
        System.out.println("3. Save");
        System.out.println("4. Option");
        System.out.println("5. Player");
        System.out.println("-1. Exit");
        System.out.println("Your choice is:");
    }

    public boolean doChoice(int choice) {
        switch(choice) {
        case 1: { Game.getGame().setCurrentMenu(MenuID.PLAYERS_MENU);   break; }
        case 2: { Game.getGame().setCurrentMenu(MenuID.LOAD_MENU);      break; }
		case 3: { Game.getGame().setCurrentMenu(MenuID.SAVE_MENU);      break; }
		case 4: { Game.getGame().setCurrentMenu(MenuID.OPTION_MENU);    break; }
		case 5: {

                MapBuilder commonMapBuilder = new CommonMapBuilder(5, 5);
				MapDirector mapDirector = new MapDirector();
				Map sunMap = mapDirector.createSunMap(commonMapBuilder);
				Block[][] blockList = sunMap.getBlockList();

                for (int i = 0; i < 5; i++) {  //if you want to modify the object actively, you just need to modify the BlockType in the loop body
					commonMapBuilder.addBlock(BlockType.E_BLOCK, 0, i);
					commonMapBuilder.addBlock(BlockType.E_BLOCK, 4, i);

					commonMapBuilder.addBlock(BlockType.F_BLOCK, 2, i);
				}

                sunMap.setBlockList(blockList);
				sunMap.show();

				break; }
        default:
            return false;
        }
		return true;
    }
}