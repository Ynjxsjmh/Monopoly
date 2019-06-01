public class WindowsMainMenu extends MainMenu {
    protected void show() {
        System.out.println("\n\tWindowsÖ÷²Ëµ¥");
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
        case 1: { game.setCurrentMenu(MenuID.PLAYERS_MENU);   break; }
        case 2: { game.setCurrentMenu(MenuID.LOAD_MENU);      break; }
		case 3: { game.setCurrentMenu(MenuID.SAVE_MENU);      break; }
		case 4: { game.setCurrentMenu(MenuID.OPTION_MENU);      break; }
		case 5: { System.out.println("Playing...");      break; }
        default:
            return false;
        }
		return true;
    }
}