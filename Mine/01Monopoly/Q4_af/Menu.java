import java.util.*;

public abstract class Menu {
    protected Game game;
    public Menu() {
        game = Game.getGame();
    }
    public boolean process() {
        // System.out.println("Menu menu hashCode为：" + menu.hashCode());
        this.show();
        int choice = getChoice();
        return doChoice(choice);
    }

    protected abstract void show();
    protected int getChoice() {
        int choice = 0;
        Scanner scanner = new Scanner(System.in);
        choice = scanner.nextInt();
        return choice;
    }
    public abstract boolean doChoice(int choice);
}