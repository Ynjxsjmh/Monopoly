package skill;

public class CardMgr {
	private static CardMgr uniqueCardMgr = new CardMgr();
	private Card[] cards = new Card[CardType.values().length];
	
	private CardMgr() {
		// All of the Card's member variables connected with Player is null
		// So attention should be attached that Player should be set before use card.
		cards[CardType.MEAN_CARD.ordinal()] = new MeanCard(null);
		cards[CardType.ROB_CARD.ordinal()] = new RobCard(null);
		cards[CardType.FLY_CARD.ordinal()] = new FlyCard(null);
		cards[CardType.LUCK_CARD.ordinal()] = new LuckCard(null);
		cards[CardType.EXFLY_CARD.ordinal()] = new ExFlyCard(null);
		cards[CardType.SUPER_CARD.ordinal()] = new SuperCard(null);
	}
	
	public static CardMgr getCardMgr() {
		return uniqueCardMgr;
	}
	
	public Card getCard(CardType cardType) {
		return cards[cardType.ordinal()];
	}
}
