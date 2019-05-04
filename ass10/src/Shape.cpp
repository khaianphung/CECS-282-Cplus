//Point a, Point b
#include "Shape.h"

#include<math.h>
Shape::Shape(Point &aa, Point &bb) {
	setPointA(aa);
	setPointB(bb);
}
/*change the shape size
@param1 the horizontal change
@param2 the verticle change
*/
void Shape::scale(int horizontal, int vertical) {
	b.setX(b.getX() * horizontal);
	b.setY(b.getY() * vertical);
}
/*move the shape
@param1 the horizontal change
@param2 the verticle change
*/
void Shape::translate(int horizontal, int vertical) {

	a.setX(a.getX() + horizontal);

	a.setY(a.getY() + vertical);


	b.setX(b.getX() + horizontal);

	b.setY(b.getY() + vertical);
}

//setters
void Shape::setPointA(Point &aa) {
	a = aa;
}

void Shape::setPointB(Point &bb) {
	b = bb ;
}


