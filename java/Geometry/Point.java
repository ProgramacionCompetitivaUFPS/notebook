La clase punto será la base sobre la cual se ejecuten otros algoritmos. 

class Point { 
	double x, y;
  	public Point() { 
  		this.x = this.y = 0.0; 
  	}
  	public Point(double _x, double _y){
  		this.x = _x;
  		this.y = _y;
  	} 
  	public double getX(){
  		return this.x;
  	}
  	public double getY(){
  		return this.y;
  	}
  	public boolean equals(Point other){
  		if(Math.abs(this.x - other.getX()) < 1e-9 && (Math.abs(this.y - other.getY()) < 1e-9)) {
  			return true;
  		}
  		return false;
  	}
}
