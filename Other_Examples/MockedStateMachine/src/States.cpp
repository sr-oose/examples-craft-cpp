#include <iostream>

#include "States.h"

using namespace std;

LevelCrossingStatePtr LevelCrossingState::onTrainApproaching() {
	throw domain_error("Event not supported in this state.");
}

LevelCrossingStatePtr LevelCrossingState::onBarrierFullyClosed() {
	throw domain_error("Event not supported in this state.");
}

LevelCrossingStatePtr LevelCrossingState::onBarrierFullyOpened() {
	throw domain_error("Event not supported in this state.");
}

LevelCrossingStatePtr LevelCrossingState::onTrainHasPassed() {
	throw domain_error("Event not supported in this state.");
}

LevelCrossingStatePtr StateClosing::onTrainApproaching() {
	return make_shared<StateClosing>(actuator);
}

LevelCrossingStatePtr StateClosing::onBarrierFullyClosed() {
	return make_shared<StateClosed>(actuator);
}

LevelCrossingStatePtr StateClosing::onTrainHasPassed() {
	actuator->sendOpenCommand();
	return make_shared<StateOpening>(actuator);
}

LevelCrossingStatePtr StateOpening::onTrainApproaching() {
	actuator->sendCloseCommand();
	return make_shared<StateClosing>(actuator);
}

LevelCrossingStatePtr StateOpening::onBarrierFullyOpened() {
	return make_shared<StateOpen>(actuator);
}

LevelCrossingStatePtr StateOpening::onTrainHasPassed() {
	return make_shared<StateOpening>(actuator);
}

LevelCrossingStatePtr StateOpen::onTrainApproaching() {
	actuator->sendCloseCommand();
	return make_shared<StateClosing>(actuator);
}

LevelCrossingStatePtr StateOpen::onTrainHasPassed() {
	return make_shared<StateOpening>(actuator);
}

LevelCrossingStatePtr StateClosed::onTrainApproaching() {
	return make_shared<StateClosed>(actuator);
}

LevelCrossingStatePtr StateClosed::onTrainHasPassed() {
	actuator->sendOpenCommand();
	return make_shared<StateOpening>(actuator);
}

StateID StateClosing::getStateID() {
	return StateID::CLOSING;
}

StateID StateOpening::getStateID() {
	return StateID::OPENING;
}

StateID StateOpen::getStateID() {
	return StateID::OPEN;
}

StateID StateClosed::getStateID() {
	return StateID::CLOSED;
}
