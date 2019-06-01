package game;

import java.util.*;
import play.*;

public class MyCppContainer<E> {
	private Deque<E> playerList = new LinkedList<E>();
	
	public Iterator getIterator() {
		return new MyCppIterator();
	}
	
	class MyCppIterator {
		int index;
		public Object first() {
			return playerList.getFirst();
		}
		public Object next() {
			if (!this.isLast()) {
				return playerList.get(index);
			}
			return null;
		}
		public boolean isLast() {
			if(index < playerList.size()) {
				return false;
			}
			return true;
		}
		public Object current() {
			return playerList.get(index-1);
		}
		public int count() {
			return index-1;
		}
	}
}