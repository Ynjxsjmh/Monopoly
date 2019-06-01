package map;

import java.util.HashMap;
import java.util.Map;

public class DirectionID {
	public static final int DIR_NONE  = 0 ;
	public static final int DIR_LEFT  = 1 ;
	public static final int DIR_DOWN  = 2 ;
	public static final int DIR_RIGHT = 3 ;
	public static final int DIR_UP    = 4 ;
	public static final int DIR_COUNT = 5 ;
	
	// directionMap stores the direction pair which is opposite
	// in case player walk back
	private Map<Integer, Integer>directionMap = new HashMap<>();
	private static DirectionID uniqueDirectionID = new DirectionID();
	
	private DirectionID() {
		directionMap.put(DIR_DOWN, DIR_UP);
		directionMap.put(DIR_UP, DIR_DOWN);
		directionMap.put(DIR_LEFT, DIR_RIGHT);
		directionMap.put(DIR_RIGHT, DIR_LEFT);
	}
	
	public static DirectionID getDirectionID() {
		return uniqueDirectionID;
	}
	
	public Map<Integer, Integer> getDirectionMap() {
		return this.directionMap;
	}
}
