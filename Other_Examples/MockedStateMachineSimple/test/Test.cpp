#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include <stdexcept>

#include "StateMachine.h"
#include "BarrierActuatorStub.h"
#include "BarrierActuatorMock.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

using namespace std;
using StateID = StateMachine::StateID;

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
	EXPECT_THROW(stateMachine.barrierFullyClosed(), domain_error);
}

TEST(StateMachine, closeCommandCorrectlySent){
    shared_ptr<BarrierActuatorMock> actuator = make_shared<BarrierActuatorMock>();
    StateMachine stateMachine{actuator};

    EXPECT_CALL(*actuator, sendCloseCommand())
    	.Times(1);
    stateMachine.trainApproaching();
    ASSERT_EQ(StateID::CLOSING, stateMachine.getStateID());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
