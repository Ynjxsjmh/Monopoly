package game;

import java.util.*;
import play.*;

public class MyJavaContainer<E> {
	private Deque<E> playerList = new LinkedList<E>();

	public Iterator getIterator() {
		return new MyJavaIterator();
	}

	class MyJavaIterator {
		int index;

		public Object next() {
			if(this.hasNext()) {
				return playerList.get(index);
			}
			return null;
		}

		public boolean hasNext() {
			if(index < playerList.size()){
				return true;
			}
			return false;
		}

		public int count() {
			return index;
		}
	}
}