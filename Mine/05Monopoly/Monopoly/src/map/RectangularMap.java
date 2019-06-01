package map;

public class RectangularMap extends Map {
	/**
	* 此类是口字形的地图，图为
	*
	* A A A A A
	* B       B
	* C       C
	* D       D
	* A A A A A
	*/
    public RectangularMap(MapImp aImp) {
		super(aImp);
        name = "RectangleMap";
    }
}