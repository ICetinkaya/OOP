//////////////////////////////////////////////////////////////////////
//                     Object Oriented Programming                  //
// Autor:İbrahim ÇETİNKAYA          Date: Create Date>> October 20  //                                 
//                                                          2014    //
//////////////////////////////////////////////////////////////////////

//Create Vector Class
/*################################################################*/
/* Includes                                                       */
/*################################################################*/
#ifndef VECT3D_H
#define VECT3D_H

class Vect3D{
public:
	Vect3D(); // No parameter constructor
	Vect3D(double pointXValue); // One parameter constructor
	Vect3D(double pointXValue,double pointYValue);  // Two parameter constructor
	Vect3D(double pointXValue,double pointYValue,double pointZValue); // Three parameter constructor
	void output() const; //Print screen result of operations
	void input();  //Get coordinate variables of vector by User

	void setVect3DX(double pointXValue); //Change the pointX
	void setVect3DY(double pointYValue); //Change the pointY
	void setVect3DZ(double pointZValue); //Change the pointZ

	double getVect3DX()const; //Return the pointX
	double getVect3DY()const; //Return the pointY
	double getVect3DZ()const; //Return the pointY

	//Function that takes one parameter(secondVect3D).Return the obje of Vect3D type(result dot product of two vectors).
	Vect3D resultDotProductVal(Vect3D secondVect3D);
	//Function that takes one parameter(secondVect3D).Return the obje of Vect3D type(result vector product of two vectors).
	Vect3D resultVect3DProductVal(Vect3D secondVect3D);
	//Function that takes one parameter(const secondVect3D).Return the obje of Vect3D type(result vector product of two vectors).
	Vect3D resultVect3DProductRef(const Vect3D &secondVect3D);
	//Function that takes one parameter(const secondVect3D).Return the obje of Vect3D type(result dot product of two vectors).
	Vect3D resultDotProductRef(const Vect3D &secondVect3D);
	//Function that takes no parameter.Return  magnitute of vector.
	double findMagnitute();

private:
	double pointX;
	double pointY;
	double pointZ;
};
	
	
#endif
