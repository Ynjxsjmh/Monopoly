public class SunMap extends Map {
	/**
	* 此类是日字形的地图，图为
	*
	* A A A A A
	* B       B
	* C C C C C
	* D       D
	* A A A A A
	*/
    public SunMap(MapImp aImp) {
		super(aImp);
        name = "RectangleMap";
    }
}