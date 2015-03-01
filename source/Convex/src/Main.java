import java.awt.Color;
import javax.swing.JFrame;
import javax.swing.JPanel;


public class Main {
	public static void main(String[] args) {
		setUpFrame(new Quickhull());							//Runs the quickhull agorithm
	}
	

	//Sets up the frame and runs the program
	private static int setUpFrame(JPanel pan) {
		JFrame frame = new JFrame();							//Creates the frame
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	//Sets what happens when frame closes
		frame.setSize(700, 700);								//Sets frame's size
		frame.setTitle("Convex Hull Test");						//Sets the Title to the frame
		frame.add(pan);											//Adds the panel sent in into the frame
		frame.setVisible(true);									//Makes the frame visible
		
		return 1;
		
	}
}
