import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.util.ArrayList;


public class Quickhull extends Algorithm{
	
	
	public Quickhull() {
		super();			//Calls it's parent class
	}
	
	
	
	//This will start of by finding 2 x values that are farthest from eachother
	protected void FirstPoints() {
		int min = Integer.MAX_VALUE, minLoc = -1;		//Sets up the minimum value to be larger then most values and its location
		int max = Integer.MIN_VALUE, maxLoc = -1;		//Sets up the maximum value to be smaller then most values and its location
		ArrayList<Point> above = new ArrayList<Point>();	//Keeps track of all the points below the line
		ArrayList<Point> below= new ArrayList<Point>();
		Point A = null, B = null;						//Creates points A and B for the smallest and largest points
		
		for(int i = 0; i < list.size(); ++i) {			//Moves through list to find the smallest and largest value
			Point p = list.get(i);						//Keeps track of current point in temp p
			if(p.x < min) {								//If this x value is less then the current minimum
				min = p.x;								//Keep track of the smallest value and location
				minLoc = i;									
			}
			if(p.x > max) {								//If this x value is greater then the current maximum
				max = p.x;								//Keep track of the largest value and location
				maxLoc = i;									
			}
		}
		A = list.get(minLoc);							//Have A now point to the smallest point
		B = list.get(maxLoc);							//Have B now point to the largest point
		hull.add(A);									//Adds A to the hull list
		hull.add(B);									//Adds B to the hull list
		list.remove(minLoc);							//Now removes the A point from the list
		list.remove(maxLoc-1);							//Now removes the B point from the list
		
		//Places all the nodes in the correct set
		for(int i = 0; i < list.size(); ++i) {
			Point p = list.get(i);						//Keep track of current point
			if(Location(A, B, p) == -1)					//Tests teh location of the point
				above.add(p);
			else
				below.add(p);
		}
		CallDraw();
		
		NextPoint(A, B, above);
		NextPoint(B, A, below);
	}
	
	//This will get the next furthest point from the two points and list sent in
	//Set is the amount of points sent in, left is all the array points this will find on its left and also same with right
	private void NextPoint(Point A, Point B, ArrayList<Point> set) {
		if(set.size() < 1)	return;						//if the size is smaller then 1 leave
		if(set.size() == 1)	{							//If there is only one point left, it should be part of the hull also
			hull.add(set.get(0));						//Add the point to hull
			set.remove(0);								//and remove it from set
			CallDraw();
			return;
		}
		ArrayList<Point> below = new ArrayList<Point>();	//Keeps track of all the points below the line
		ArrayList<Point> above= new ArrayList<Point>();		//Keeps track of all the points above the line
		Point C;										//This will keep track of the farthest point from a and b
		
		int max = Integer.MIN_VALUE, maxLoc = -1;		//This will keep track of farthest point and location
		for(int i = 0; i < set.size(); ++i) {			//Finds the farthest point from A and B
			Point P = set.get(i);						//Keep track of temporary current point
			int dist = Distance(A, B, P);				//Get distance of the points
			if(dist > max) {							//If this distance is the farthest keep track of it's info
				max = dist;								//Keep track of value
				maxLoc = i;								//Keep track of location
			}
		}
		C = set.get(maxLoc);							//Get farthest Point
		hull.add(C);									//Add that point to hull
		set.remove(maxLoc);								//Remove it from set

		CallDraw();
		
		for(int i = 0; i < set.size(); ++i) { 			//Find all the points Location
			Point P = set.get(i);
			if(Location(A, C, P) == -1)					//Find Above AC
				above.add(P);
			if(Location(C, B, P) == -1)					//Find Below C and B
				below.add(P);
		}
		NextPoint(A, C, above);							
		NextPoint(C, B, below);
	}
}