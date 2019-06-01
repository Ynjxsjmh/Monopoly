public class WindowsLoadMenu extends LoadMenu {
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
        case 1: { System.out.println("Windows¥Êµµ1º”‘ÿÕÍ±œ"); break; }
        case 2: { System.out.println("Windows¥Êµµ2º”‘ÿÕÍ±œ"); break; }
        case 3: { System.out.println("Windows¥Êµµ3º”‘ÿÕÍ±œ"); break; }
        case 4: { System.out.println("Windows¥Êµµ4º”‘ÿÕÍ±œ"); break; }
        case 5: { System.out.println("Windows¥Êµµ5º”‘ÿÕÍ±œ"); break; }
        default: { game.setCurrentMenu(MenuID.MAIN_MENU); }
        }
		return true;
    }
}