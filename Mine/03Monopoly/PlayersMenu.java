public class PlayersMenu extends Menu {
	public PlayersMenu() {
		super();
	}

    protected void show() {
        System.out.println("\n\tSet number of players (2-8):");
        System.out.println("2. 2");
        System.out.println("3. 3");
        System.out.println("4. 4");
        System.out.println("5. 5");
        System.out.println("6. 6");
        System.out.println("7. 7");
        System.out.println("8. 8");
        System.out.println("-1. Back");
    }

    public boolean doChoice(int choice) {
        switch(choice) {
        case 1: { System.out.println("Set Players count 1 player game"); break;  }
        case 2: { System.out.println("Set Players count 2 players game"); break;  }
        case 3: { System.out.println("Set Players count 3 players game"); break;  }
        case 4: { System.out.println("Set Players count 4 players game"); break;  }
        case 5: { System.out.println("Set Players count 5 players game"); break;  }
        case 6: { System.out.println("Set Players count 6 players game"); break;  }
        case 7: { System.out.println("Set Players count 7 players game"); break;  }
        case 8: { System.out.println("Set Players count 8 players game"); break;  }
        default: { Game.getGame().setCurrentMenu(MenuID.MAIN_MENU); }
        }
		return true;
    }
}