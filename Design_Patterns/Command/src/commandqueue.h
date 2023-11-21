#ifndef COMMANDQUEUE_H_
#define COMMANDQUEUE_H_

#include <memory>
#include <vector>
#include "command.h"

class CommandQueue {
	using CommandPtr = std::shared_ptr<Command>;
public:
	void enqueue(CommandPtr command){
		commands.push_back(command);
	}

	void executeNextCommand(){
		commands.at(position++)->execute();
	}

	void undoLastCommand(){
		commands.at(--position)->undo();
		commands.pop_back();
	}

	bool endReached() const {
		return position >= commands.size();
	}

private:
	std::size_t position = 0;
	std::vector<CommandPtr> commands;
};



#endif
