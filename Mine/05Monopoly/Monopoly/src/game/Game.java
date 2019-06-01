package game;

import java.util.LinkedList;
import java.util.Queue;

import block.BlockCache;
import block.BlockType;
import device.OutDevice;
import device.StreamDevice;
import map.DirectionID;
import map.Map;
import map.MapMgr;
import menu.MenuID;
import menu.MenuMgr;
import player.NormalPlayer;
import player.Player;
import skill.Card;
import skill.CardMgr;
import skill.CardType;
import skill.LuckCard;
import skill.Magic;
import skill.MagicMgr;
import skill.MagicType;
import skill.Skill;
import skill.SkillType;

public class Game {
	private MenuMgr menuMgr;
	private MapMgr mapMgr;
	private CardMgr cardMgr;
	private MagicMgr magicMgr;
	private DirectionID directionID;
	private static Game uniqueGame = new Game();
	private OutDevice outDevice;
	private boolean isEnd; // If the game ends

	public Queue<Player> players = new LinkedList<Player>();
	public Player currentPlayer;
	private int playerNum;

	private Game() {
		isEnd = false;
		outDevice = new StreamDevice();
		menuMgr = MenuMgr.getMenuMgr();
		mapMgr = MapMgr.getMapMgr();
		cardMgr = CardMgr.getCardMgr();
		magicMgr = MagicMgr.getMagicMgr();
		directionID = DirectionID.getDirectionID();
		BlockCache.loadCache();

		NormalPlayer normalPlayer = new NormalPlayer(0);
		normalPlayer.setHuman(true);
		for (int i = 0; i < 3; i++) {
			Card luckCard = new LuckCard(normalPlayer);
			normalPlayer.addSkill(luckCard);
		}

		players.offer(normalPlayer); // default human player is one
		currentPlayer = normalPlayer;
	}

	public static Game getGame() {
		// if (uniqueGame == null) {
		// System.out.println("正在返回Game");
		// uniqueGame = new Game();
		// }
		return uniqueGame;
	}

	public void init() {
		setCurrentMenu(MenuID.MAIN_MENU);
	}

	public void run() {
		boolean running = true;
		while (running && !isEnd) {
			running = menuMgr.currentMenu.process();
			// choice = currentMenu.process(); //对主菜单进行选择，选择后进入子菜单
			// running = currentMenu.doChoice(choice);
			// setCurrentMenu(choice);

			// choice = currentMenu.process(); //对子菜单进行选择，每个子菜单对选项表现出不同的行为。选择为0，返回上一级菜单。
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

	public java.util.Map<Integer, Integer> getDirectionMap() {
		return directionID.getDirectionMap();
	}

	public Card getCard(CardType cardType) {
		return cardMgr.getCard(cardType);
	}

	public Magic getMagic(MagicType magicType) {
		return magicMgr.getMagic(magicType);
	}

	public Player getSpecificPlayer(int playerID) {
		for (Player tempPlayer : players) {
			if (tempPlayer.getID() == playerID) {
				return tempPlayer;
			}
		}
		return null;
	}

	public OutDevice getDevice() {
		return this.outDevice;
	}

	public void showInfo() {
		Queue<Player> tempPlayers = Game.getGame().players;

		// draw player head
		System.out.printf("%-15s", "PlayerID");
		for (Player player : tempPlayers) {
			System.out.printf("%-15s", "Player[" + player.getID() + "]");
		}

		// draw money line
		outDevice.draw("\n");
		System.out.printf("%-15s", "money");
		for (Player player : tempPlayers) {
			System.out.printf("%-15.2f", player.money);
		}

		// draw card line
		CardType[] cardTypes = CardType.values();
		int cardKind = cardTypes.length;
		int[][] playersCardNum = new int[Game.getGame().playerNum][cardKind]; // Is cardNum initialized to 0?
		int count = 0;
		for (CardType currentCardType : cardTypes) {
			count ++;
			outDevice.draw("\n");
			System.out.printf("%-15s", currentCardType);
			for (Player player : tempPlayers) {
				if (player.getSkillVector() != null) {
					for (Skill skill : player.getSkillVector()) {
						if (skill.getSkillType().equals(SkillType.CARD)) {
							Card card = (Card) skill;
							CardType cardType = card.getCardName();
							// if cardType.equels(currentCardType)
							playersCardNum[player.getID()][cardType.ordinal()]++;
						}
					}
				}
//				outDevice.draw("\t" + playersCardNum[player.getID()][currentCardType.ordinal()]);
				System.out.printf("%-15d" ,playersCardNum[player.getID()][currentCardType.ordinal()]/count);
			}
		}

		// draw magic line
		MagicType[] magicTypes = MagicType.values();
		int magicKind = magicTypes.length;
		int[][] playersMagicNum = new int[Game.getGame().playerNum][magicKind]; // Is cardNum initialized to 0?
		count = 0;
		for (MagicType currentMagicType : magicTypes) {
			count ++;
			outDevice.draw("\n");
			System.out.printf("%-15s", currentMagicType);
			for (Player player : tempPlayers) {
				if (player.getSkillVector() != null) {
					for (Skill skill : player.getSkillVector()) {
						if (skill.getSkillType().equals(SkillType.MAGIC)) {
							Magic magic = (Magic) skill;
							MagicType magicType = magic.getMagicName();
							playersMagicNum[player.getID()][magicType.ordinal()]++;
						}
					}
				}
//				outDevice.draw("\t" + playersMagicNum[player.getID()][currentMagicType.ordinal()]);
				System.out.printf("%-15d" ,playersCardNum[player.getID()][currentMagicType.ordinal()]/count);
			}
		}
	}

	public void check() {
		// check if the player should be removed from queues
		// and if the game is end
		// It's executed in Player.move()
		for (Player player : players) {
			if (player.money <= 0) {
				players.remove(player);
				if (player.getIsHuman()) {
					// Game ends
					Game.getGame().setCurrentMenu(MenuID.MAIN_MENU);
					players.clear();
					NormalPlayer normalPlayer = new NormalPlayer(0);
					normalPlayer.setHuman(true);
					players.offer(normalPlayer);
					// isEnd = true;
				}
				for (Player tempPlayer : players) {
					BlockCache.getRealBlock(BlockType.TRIP_BLOCK).setMoney(-200);
					tempPlayer.money /= 2;
				}
			}
		}

		if ((players.size() == 1) && (players.peek().getIsHuman())) {
			outDevice.drawLn("You win");
			// Game ends
			Game.getGame().setCurrentMenu(MenuID.MAIN_MENU);
			players.clear();
			NormalPlayer normalPlayer = new NormalPlayer(0);
			normalPlayer.setHuman(true);
			players.offer(normalPlayer);
			// isEnd = true;
		}
	}
}