
#include "StateMachine.h"

using namespace std;

StateMachine::StateMachine(std::shared_ptr<BarrierActuator> actuator){
	currentState = make_shared<StateOpen>(actuator);
}

void StateMachine::trainApproaching() {
	currentState = currentState->onTrainApproaching();
}

void StateMachine::trainHasPassed() {
	currentState = currentState->onTrainHasPassed();
}

void StateMachine::barrierFullyOpened() {
	currentState = currentState->onBarrierFullyOpened();
}

void StateMachine::barrierFullyClosed() {
	currentState = currentState->onBarrierFullyClosed();
}

StateID StateMachine::getStateID() {
	return currentState->getStateID();
}
