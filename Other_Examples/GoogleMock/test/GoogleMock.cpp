#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include <stdexcept>

class ConfigurationProvider {
public:
	virtual ~ConfigurationProvider() = default;
	virtual std::string getOptionValue(std::string& name) const = 0;
	virtual void setOption(const std::string& name, const std::string& value) = 0;
	virtual int getOptionNumber() const = 0;
};

/* Functions under test */

void resetEntry(ConfigurationProvider& config, const std::string& name){
	config.setOption(name, std::string());
}

void checkValidity(ConfigurationProvider& config){
	if (config.getOptionNumber() == 0
			|| config.getOptionNumber() > 100){
		throw std::runtime_error("configuration invalid");
	}
	// other checks
}

/************************/

class MockConfigProvider : public ConfigurationProvider {
public:
	MOCK_METHOD(std::string, getOptionValue, (std::string& name), (const));
	MOCK_METHOD(void, setOption, (const std::string& name, const std::string& value));
	MOCK_METHOD(int, getOptionNumber, (), (const));
};

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

TEST(reset, setOptionIsCalled) {
   MockConfigProvider provider{};
   std::string input = "foo";
   EXPECT_CALL(provider, setOption(_, _)).Times(AtLeast(1));
   resetEntry(provider, input);
}


TEST(reset, correctEntryIsSetToEmptyString) {
   MockConfigProvider provider{};
   std::string input = "foo";
   EXPECT_CALL(provider, setOption(input, std::string())).Times(AtLeast(1));
   resetEntry(provider, input);
}

TEST(checkValidity, errorOnEmptyConfiguration) {
   MockConfigProvider provider{};
   ON_CALL(provider, getOptionNumber())
       .WillByDefault(Return(0));

   EXPECT_CALL(provider, getOptionNumber())
   	   .WillOnce(Return(0))
       .WillRepeatedly(Return(0));

   try {
	   checkValidity(provider);
	   FAIL();
   } catch (std::exception& e) {
   }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
