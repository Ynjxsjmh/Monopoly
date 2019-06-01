import java.util.ArrayList;

public abstract class Map {
    protected Block[][] blockList;
    protected String name;
	
	/**
	* 显示Map
	*/
    public void show() {
        for (int i = 0; i < blockList.length; i++) {
			System.out.println();
            for (int j = 0; j < blockList[i].length; j++){
                System.out.print(blockList[i][j].toString());
            }
        }
    }
	
	public void setBlockList(Block[][] blockList){
		this.blockList = blockList;
	}
}