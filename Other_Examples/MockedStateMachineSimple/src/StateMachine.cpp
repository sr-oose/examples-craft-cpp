#include <stdexcept>
#include "StateMachine.h"


using namespace std;

StateMachine::StateMachine(std::shared_ptr<BarrierActuator> actuator)
	: actuator(actuator)
{
	currentState = StateID::OPEN;
}

void StateMachine::trainApproaching() {
	switch(currentState){
	case StateID::CLOSED:
	case StateID::CLOSING:
		break;
	case StateID::OPEN:
	case StateID::OPENING:
		actuator->sendCloseCommand();
		currentState = StateID::CLOSING;
		break;
	default:
		throw domain_error("Invalid event");
	}
}

void StateMachine::trainHasPassed() {
	switch(currentState){
	case StateID::CLOSED:
	case StateID::CLOSING:
		actuator->sendOpenCommand();
		currentState = StateID::OPENING;
		break;
	case StateID::OPEN:
	case StateID::OPENING:
		break;
	default:
		throw domain_error("Invalid event");
	}
}

void StateMachine::barrierFullyOpened() {
	switch(currentState){
	case StateID::OPENING:
		currentState = StateID::OPEN;
		break;
	case StateID::OPEN:
	case StateID::CLOSED:
	case StateID::CLOSING:
	default:
		throw domain_error("Invalid event");
	}
}

void StateMachine::barrierFullyClosed() {
	switch(currentState){
	case StateID::CLOSING:
		currentState = StateID::CLOSED;
		break;
	case StateID::OPEN:
	case StateID::OPENING:
	case StateID::CLOSED:
	default:
		throw domain_error("Invalid event");
	}
}

StateMachine::StateID StateMachine::getStateID() {
	return currentState;
}
