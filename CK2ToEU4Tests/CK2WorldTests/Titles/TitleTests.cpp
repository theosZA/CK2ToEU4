#include "gtest/gtest.h"
#include "../CK2ToEU4/Source/CK2World/Titles/Title.h"
#include "../CK2ToEU4/Source/CK2World/Titles/Titles.h"
#include "../CK2ToEU4/Source/CK2World/Titles/Liege.h"
#include "../CK2ToEU4/Source/CK2World/Provinces/Province.h"
#include "../CK2ToEU4/Source/CK2World/Provinces/Provinces.h"
#include <sstream>

TEST(CK2World_TitleTests, nameCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_EQ(theTitle.getName(), "c_test");
}

TEST(CK2World_TitleTests, lawsDefaultToEmpty)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_TRUE(theTitle.getLaws().empty());
}

TEST(CK2World_TitleTests, lawCanBeAdded)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tlaw=\"revoke_title_voting_power_0\"\n";	
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_FALSE(theTitle.getLaws().empty());
	ASSERT_EQ(theTitle.getLaws().size(), 1);
	ASSERT_EQ(*theTitle.getLaws().begin(), "revoke_title_voting_power_0");
}

TEST(CK2World_TitleTests, multipleLawsCanBeAdded)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tlaw=\"revoke_title_voting_power_0\"\n";	
	input << "\tlaw=\"out_of_realm_inheritance_law_1\"\n";	
	input << "\tlaw=\"centralization_4\"\n";	
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_FALSE(theTitle.getLaws().empty());
	ASSERT_EQ(theTitle.getLaws().size(), 3);
	ASSERT_EQ(theTitle.getLaws().count("centralization_4"), 1);
}

TEST(CK2World_TitleTests, holderCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tholder=123\n";	
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_EQ(theTitle.getHolder().first, 123);
}

TEST(CK2World_TitleTests, holderDefaultsToZero)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_EQ(theTitle.getHolder().first, 0);
}

TEST(CK2World_TitleTests, inHREDefaultsToFalse)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_FALSE(theTitle.isInHRE());
}

TEST(CK2World_TitleTests, inHRECanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	CK2::Title theTitle(input, "c_test");
	theTitle.setInHRE();

	ASSERT_TRUE(theTitle.isInHRE());
}

TEST(CK2World_TitleTests, majorRevoltDefaultsToFalse)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_FALSE(theTitle.isMajorRevolt());
}

TEST(CK2World_TitleTests, majorRevoltCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tmajor_revolt=yes\n";
	input << "}";

	CK2::Title theTitle(input, "c_test");
	theTitle.setInHRE();

	ASSERT_TRUE(theTitle.isMajorRevolt());
}

TEST(CK2World_TitleTests, liegeDefaultsToNull)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_FALSE(theTitle.getLiege().second);
}

TEST(CK2World_TitleTests, simpleLiegeCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tliege=c_test2\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_EQ(theTitle.getLiege().second->getTitle().first, "c_test2");
}

TEST(CK2World_TitleTests, complexLiegeCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tliege=\n";
	input << "\t{\n";
	input << "\ttitle=c_test2\n";
	input << "\t}\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_EQ(theTitle.getLiege().second->getTitle().first, "c_test2");
}

TEST(CK2World_TitleTests, deJureLiegeTitleDefaultsToNull)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_FALSE(theTitle.getDeJureLiege().second);
}

TEST(CK2World_TitleTests, simpleDeJureLiegeCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tde_jure_liege=c_test2\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_EQ(theTitle.getDeJureLiege().second->getTitle().first, "c_test2");
}

TEST(CK2World_TitleTests, complexDeJureLiegeCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tde_jure_liege=\n";
	input << "\t{\n";
	input << "\ttitle=c_test2\n";
	input << "\t}\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_EQ(theTitle.getDeJureLiege().second->getTitle().first, "c_test2");
}

TEST(CK2World_TitleTests, baseTitleDefaultsToBlank)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_TRUE(theTitle.getBaseTitle().first.empty());
}

TEST(CK2World_TitleTests, simpleBaseTitleCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tbase_title=c_base\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_EQ(theTitle.getBaseTitle().second->getTitle().first, "c_base");
}

TEST(CK2World_TitleTests, complexBaseTitleCanBeSet)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "\tbase_title=\n";
	input << "\t{\n";
	input << "\ttitle=c_base\n";
	input << "\t}\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_EQ(theTitle.getBaseTitle().second->getTitle().first, "c_base");
}

TEST(CK2World_TitleTests, provincesDefaultToEmpty)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";

	const CK2::Title theTitle(input, "c_test");

	ASSERT_TRUE(theTitle.getProvinces().empty());
}

TEST(CK2World_TitleTests, provincesCanBeLoaded)
{
	std::stringstream input;
	input << "=\n";
	input << "{\n";
	input << "}";
	CK2::Title theTitle(input, "c_test");

	std::stringstream input2;
	input2 << "=\n";
	input2 << "{\n";
	input2 << "42={}\n";
	input2 << "43={}\n";
	input2 << "}";
	const CK2::Provinces theProvinces(input2);
	const auto& province = theProvinces.getProvinces().find(42);
	theTitle.registerProvince(std::pair(province->first, province->second));

	ASSERT_EQ(theTitle.getProvinces().find(42)->second->getID(), 42);
}
