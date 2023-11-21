#include <gtest/gtest.h>
#include "StateMachine.h"
#include "BarrierActuatorStub.h"

using namespace std;

TEST(StateMachine, firstTestWithStub){
	BarrierActuatorPtr actuator = make_shared<BarrierActuatorStub>();
	StateMachine stateMachine{actuator};
	ASSERT_EQ(StateID::OPEN, stateMachine.getStateID());
	stateMachine.trainApproaching();
	ASSERT_EQ(StateID::CLOSING, stateMachine.getStateID());
	stateMachine.barrierFullyClosed();
	ASSERT_EQ(StateID::CLOSED, stateMachine.getStateID());
	stateMachine.trainHasPassed();
	ASSERT_EQ(StateID::OPENING, stateMachine.getStateID());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
