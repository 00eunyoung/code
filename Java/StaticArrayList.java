
public class StaticArrayList {
	public static void main(String[] args) {
		for(int i=1; i<5; i++) {
			new Rect(i, i+1);	
		}
		
		for(Rect r: Rect.rectarr) {
			System.out.println(r.width+", "+r.length+", "+r.getArea());
		}
	}

}
