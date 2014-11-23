//////////////////////////////////////////////////////////////////////
//                      Object Oriented Programming                 //
// Autor:İbrahim ÇETİNKAYA          Date: Create Date>> October 20  //
//                                                          2014    //
//                                                                  //
//                       FUNCTION IMPLEMENTATION                    //
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Vect3D.h"
using namespace std;
Vect3D::Vect3D(){
	setVect3DX(0.0);
	setVect3DY(0.0);
	setVect3DZ(0.0);
}

Vect3D::Vect3D(double pointXValue){
	setVect3DX(pointXValue);
	setVect3DY(0.0);
	setVect3DZ(0.0);
}
Vect3D::Vect3D(double pointXValue,double pointYValue){
	setVect3DX(pointXValue);
	setVect3DY(pointYValue);
	setVect3DZ(0.0);
}
Vect3D::Vect3D(double pointXValue,double pointYValue,double pointZValue){
	setVect3DX(pointXValue);
	setVect3DY(pointYValue);
	setVect3DZ(pointZValue);
}
void Vect3D::setVect3DX(double pointXValue)
{
	pointX = pointXValue;
}
void Vect3D::setVect3DY(double pointYValue){
	pointY = pointYValue;
}
void Vect3D::setVect3DZ(double pointZValue){
	pointZ = pointZValue;
}
double Vect3D::getVect3DX()const{
	return pointX;
}
double Vect3D::getVect3DY()const{
	return pointY;
}
double Vect3D::getVect3DZ()const{
	return pointZ;
}
void Vect3D::output()const{
	cout <<"Vect3D is ";
	cout << getVect3DX() <<"i "<<" + "<< getVect3DY() <<"j "<<" + "<< getVect3DZ() <<"k"<<endl;
}
void Vect3D::input(){
	double x1,y1,z1;
	cout << "Please enter the X coordinate of  Vect3D " << endl;
	cin >> x1;
	cout << "Please enter the Y coordinate of  Vect3D" << endl;
	cin >> y1;
	cout << "Please enter the Z coordinate of  Vect3D" << endl;
	cin >> z1 ;
	setVect3DX(x1);
	setVect3DY(y1);
	setVect3DZ(z1);
}
Vect3D Vect3D::resultDotProductVal(Vect3D secondVect3D){
	//call by value

	Vect3D dotProductT;
	dotProductT.setVect3DX( pointX * secondVect3D.pointX );
	dotProductT.setVect3DY( pointY * secondVect3D.pointY );
	dotProductT.setVect3DZ( pointZ * secondVect3D.pointZ );
	 return dotProductT;
}
Vect3D Vect3D::resultVect3DProductVal(Vect3D secondVect3D){
	//call by value 
	Vect3D Vect3DProductT;
	Vect3DProductT.setVect3DX( pointY * secondVect3D.pointZ - (pointZ * secondVect3D.pointY));//i
	Vect3DProductT.setVect3DY( (pointX * secondVect3D.pointZ - (pointZ * secondVect3D.pointX)) *(-1) );//-j
	Vect3DProductT.setVect3DZ( pointX * secondVect3D.pointY - (pointY * secondVect3D.pointX));//k

	return Vect3DProductT;
}
Vect3D Vect3D::resultDotProductRef(const Vect3D &secondVect3D){
	//call by Reference

	Vect3D dotProductT;
	dotProductT.setVect3DX( pointX * secondVect3D.pointX );
	dotProductT.setVect3DY( pointY * secondVect3D.pointY );
	dotProductT.setVect3DZ( pointZ * secondVect3D.pointZ );
	 return dotProductT;
}
Vect3D Vect3D::resultVect3DProductRef(const Vect3D &secondVect3D){
	//Call by Reference
	Vect3D Vect3DProductT;
	Vect3DProductT.setVect3DX( pointY * secondVect3D.pointZ - (pointZ * secondVect3D.pointY));//i
	Vect3DProductT.setVect3DY( (pointX * secondVect3D.pointZ - (pointZ * secondVect3D.pointX)) *(-1) );//-j
	Vect3DProductT.setVect3DZ( pointX * secondVect3D.pointY - (pointY * secondVect3D.pointX));//k
}
double Vect3D::findMagnitute(){
	double magnitute;
	magnitute = pointX * pointX + pointY * pointY + pointZ * pointZ ;
	return magnitute;
}
