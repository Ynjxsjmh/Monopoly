public class MacLoadMenu extends LoadMenu {
    protected void show() {
        System.out.println("\n\tSelect the Record to be loaded(1-5):");
        System.out.println("1. 1");
        System.out.println("2. 2");
        System.out.println("3. 3");
        System.out.println("4. 4");
        System.out.println("5. 5");
        System.out.println("-1. Back");
        System.out.println("Your choice is:");
    }

    public boolean doChoice(int choice) {
        switch(choice) {
        case 1: { System.out.println("Mac�浵1�������"); break; }
        case 2: { System.out.println("Mac�浵2�������"); break; }
        case 3: { System.out.println("Mac�浵3�������"); break; }
        case 4: { System.out.println("Mac�浵4�������"); break; }
        case 5: { System.out.println("Mac�浵5�������"); break; }
        default: { game.setCurrentMenu(MenuID.MAIN_MENU); }
        }
		return true;
    }
}