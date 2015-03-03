//I used Killer Game Programming by Andrew Davison for reference to try and animate the panel
//Created by Drew Gohman

import javax.swing.JPanel;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;
import java.lang.Runnable;;

public abstract class Panel extends JPanel implements Runnable{
	protected static final int PWIDTH = 700;			//Width of Panel
	protected static final int PHEIGHT = 700;			//Height of Panel
	protected static final int TIME_BETWEEN = 100;		//Width of Panel
	protected static final int TOTAL_POINTS = 1000;		//Width of Panel
	
	protected volatile boolean finished = false;		//Knows when the program is done
	private Thread animator;						//This is used to control the animation thread
	protected Graphics dbg;							//Used to draw images
	private Image dbImage;							//Used alongside dbg
	
	protected abstract void Draw();					//Used with subclasses to update graphics
	protected abstract void Begin();					//Used with subclasses to update graphics
	
	public Panel() {
		setBackground(Color.white);					//Set color of panel
		setPreferredSize(new Dimension(PWIDTH, PHEIGHT));	//Set size of Panel
		Start();
	}
	
	public void Start() {
		if(animator == null) {
			animator = new Thread(this);
			animator.start();
		}
	}
	
	public void run()
	{
		Begin();
	}
	

	//This helps re render the graphics every call
	protected void Render() {
		if (dbImage == null) {				//If dbImage is null crate it
			dbImage = createImage(PWIDTH, PHEIGHT);	//set size of the image
			if(dbImage == null)
				return;
			dbg = dbImage.getGraphics();	//Set the graphics of the image to dbg
		}
		dbg.setColor(Color.WHITE);				//Has dbg to draw white
		dbg.fillRect(0, 0, PWIDTH, PHEIGHT);	//Clears the background
		//Draw();						//Used to have subclasses update teh graphics
		
	}
	
	//Actively renders the buffer image to teh screen
	protected void PaintScreen() {
		Graphics g;								//Create temp graphics object
		try {
			g = this.getGraphics();				//Get the panels current graphics
			if((g!=null) && (dbImage != null)) { //If the current graphics is not null
				g.drawImage(dbImage, 0, 0, null);	//Draw the current image to the buffer
				Toolkit.getDefaultToolkit().sync(); //Syncs graphics to the screen
				g.dispose(); 					//No use for g anymore
			}
		}
		catch (Exception e) {					//For any errors
			System.out.println("Graphics error " + e);
		}
	}
	
	
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		if(dbImage != null)
			g.drawImage(dbImage, 0, 0, null);	//Draw the dbImage on the screen
	}
	
	//This will call the draw method and rest the specified amount of time
	public void CallDraw() {
		Draw();
		try {
			Thread.sleep(TIME_BETWEEN);			//This controls the time between loop
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}
