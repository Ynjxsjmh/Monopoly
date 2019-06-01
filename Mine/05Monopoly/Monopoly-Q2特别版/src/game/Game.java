package game;
import java.util.LinkedList;
import java.util.Queue;

import block.BlockCache;
import map.Map;
import map.MapMgr;
import menu.MenuID;
import menu.MenuMgr;
import player.HumanPlayer;
import player.Player;

public class Game {
    private MenuMgr menuMgr;
	private MapMgr mapMgr;
    private static Game uniqueGame = new Game();
	
	public Queue<Player> players = new LinkedList<Player>();
	private int playerNum;

    private Game() {
        menuMgr = MenuMgr.getMenuMgr();
		mapMgr = MapMgr.getMapMgr();
		BlockCache.loadCache();
		
		players.offer(new HumanPlayer("0")); // default human player is one
    }

    public static Game getGame() {
    //    if (uniqueGame == null) {
	//		System.out.println("���ڷ���Game");
    //        uniqueGame = new Game();
    //    }
        return uniqueGame;
    }

    public void init() {
        setCurrentMenu(MenuID.MAIN_MENU);
    }

    public void run() {
        boolean running = true;
        while (running) {
            running = menuMgr.currentMenu.process();
            // choice = currentMenu.process();  //�����˵�����ѡ��ѡ�������Ӳ˵�
            // running = currentMenu.doChoice(choice);
            // setCurrentMenu(choice);

            // choice = currentMenu.process();  //���Ӳ˵�����ѡ��ÿ���Ӳ˵���ѡ����ֳ���ͬ����Ϊ��ѡ��Ϊ0��������һ���˵���
        }
    }

    public void term() {
    }

    public void setCurrentMenu(int menuID) {
        menuMgr.currentMenu = menuMgr.createMenu(menuID);
    }
    
    public int getCurrentMenuType() {
		return menuMgr.currentMenu.getMenuType();
	}

	public void setCurrentMap(Map map) {
		mapMgr.currentMap = map;
	}

	public Map getCurrentMap() {
		return mapMgr.currentMap;
	}
	
	public int getPlayerNum() {
		return playerNum;		
	}
	
	public void setPlayerNum(int num) {
		playerNum = num;
	}
	
}