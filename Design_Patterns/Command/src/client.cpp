#include "command.h"
#include "shapes.h"
#include "commandqueue.h"

using namespace std;

int main (){
	CommandQueue commandQueue{};
	commandQueue.enqueue(make_shared<DrawTextCommand>("Hallo 1"));
	commandQueue.enqueue(make_shared<DrawTextCommand>("Hallo 2"));
	commandQueue.enqueue(make_shared<DrawShapeCommand>(make_shared<Circle>()));
	commandQueue.enqueue(make_shared<DrawShapeCommand>(make_shared<Rectangle>()));

	while (!commandQueue.endReached())
		commandQueue.executeNextCommand();

	commandQueue.undoLastCommand();
	commandQueue.undoLastCommand();
	commandQueue.undoLastCommand();
}

