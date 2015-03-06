import java.awt.Color;
import java.awt.Point;
import java.util.ArrayList;
import java.util.Random;

//This class uses the Panel class and transforms it to work well with Algorithms
//This will manage Point Nodes
public abstract class Algorithm extends Panel {
	protected ArrayList<Point> list;			//Stores a list of points that the program starts with
	protected ArrayList<Point> hull;			//Stores a list of points that are the convex hull
	
	protected abstract void FirstPoints();		//Used to start algorithm
	
	public Algorithm() {
		super();
		GeneratePoints();						//Generates a list of points to work with
	}
	
	//This will take list and populate it with random numbers
	//Points will only range from 50-650 to make them appear on screen easier
	private void GeneratePoints(){
		list = new ArrayList<Point>();		//Creates a new list, garbage collector should grab old list if existed
		hull = new ArrayList<Point>();		//Creates a new list, will remain empty for now
		
		Point [] point = new Point[TOTAL_POINTS];
		Random rand = new Random();				//Used for random function
		
		for(int i = 0; i < TOTAL_POINTS; ++i) {			//Generates random points and adds it to list
			int x = rand.nextInt(500) + 50;		//Creates a new x value ranging from 50-650
			int y = rand.nextInt(500) + 50;		//Creates a new y value ranging from 50-650
			list.add(new Point(x, y));			//Add the point to the list
		}
	}
	
	//This will find the point's distance from eachother
	protected int Distance(Point A, Point B, Point C) {
		int num = ((B.x - A.x) * (A.y - C.y)) - ((B.y - A.y) * (A.x - C.x)); //This gets the distance
		if(num < 0)	num = -(num);			//Sets up num as an absolute value
		return num;							//Returns the distance
	}
	//This will find where the point stands compared to the convex
	protected int Location(Point A, Point B, Point C) {
		int num = ((B.x - A.x) * (A.y-C.y)) - ((B.y - A.y) * (A.x-C.x)); //This gets the distance
		return (num>0) ? 1 : -1;			//Returns the location
	}
	
	//This begins the algorithm process
		protected void Begin() { 
			CallDraw();
			
			FirstPoints();
			
			finished = true;
			CallDraw();
			
		}
		
		protected void Draw() {		//Used with subclasses to update graphics
			while(dbg == null) {
				Render();						//Have the panel re render the graphics
				try {
					Thread.sleep(5);			//This controls the time between loop
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
			dbg.setColor(Color.green);				//Set's color of dbg
			for(int i = 0; i < list.size(); ++i) {	//Draw all items that are not in the hull
				Point p = list.get(i);
				dbg.fillOval(p.x-4, p.y-4, 8, 8);
			}
			dbg.setColor(Color.red);				//Set the color of dbg
			for(int i = 0; i < hull.size(); ++i) {	//Draw all points on outside of convex
				Point p = hull.get(i);			
				dbg.fillOval(p.x-6, p.y-6, 12, 12);
			}
			if(finished == true)					//When finished post it
				dbg.drawString("The Program is Done", 20, 10);
			PaintScreen();						//Draw the buffer to the screen
		}
	
	
}
