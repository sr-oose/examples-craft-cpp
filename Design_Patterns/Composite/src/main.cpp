#include "nodes.h"

using namespace std;

int main(){
	TreeNodePtr add1 = make_shared<Add>(make_shared<Number>(5), make_shared<Number>(2));
	TreeNodePtr negate = make_shared<Negate>(make_shared<Number>(1));
	TreeNodePtr add2 = make_shared<Add>(make_shared<Number>(2), negate);
	TreeNodePtr multiply = make_shared<Multiply>(add1, add2);
	TreeNodePtr add3 = make_shared<Add>(multiply, make_shared<Number>(0.5));
	TreeNodePtr root = make_shared<Negate>(add3);
	cout << root->getExpressionString() << endl;
	cout << "Evaluation result: " << root->eval();
	return 0;
}

