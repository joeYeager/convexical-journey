import java.awt.Point;


public class Bruteforce extends Algorithm {
	
	public Bruteforce() {
	super();			//Calls it's parent class
	}	



	//This will start of by finding 2 x values that are farthest from eachother
	protected void FirstPoints() {
		for(int i = 0; i < list.size(); ++i) {		//For all Points in list
			Point I = list.get(i);					//Grab Temp point
			Search: {
				for(int e = 0; e <  list.size(); ++e) {	//For all Points E in list
					if(i != e) {
						Point E = list.get(e);				//Temp Point E
						int changes = 0, state = Integer.MIN_VALUE;
						if(I.x != E.x && I.y != E.y) {
							for(int z = 0; z < list.size(); ++z) {	//All the points for Z
								if(z != i && z != e ) {
									Point Z = list.get(z);			//Temp point for Z
									if(Z.x != I.x && Z.y != I.y &&
										Z.x != E.x && Z.y != I.y) {
										int loc = Location(I, E, Z);
										if(state != loc) {
											state = loc;
											changes += 1;
										}
									}	
								}
								
							}	
						}
						if(changes == 1) {
							hull.add(I);
							CallDraw();
							break Search;
						}
					}
				}
			}
			
		}
		
	}


}
