public class BlockFactory {
    public Block createBlock(String type) {
        if (type.equals("MoneyBlock")) {
            return new MoneyBlock();
        } else if (type.equals("BarBlock")) {
            return new BarBlock();
        } else if (type.equals("TripBlock")) {
            return new TripBlock();
        } else if (type.equals("SlideBlock")) {
            return new SlideBlock();
        } else if (type.equals("WallBlock")) {
			return new WallBlock();
		} else {
            return null;
        }
    }
}