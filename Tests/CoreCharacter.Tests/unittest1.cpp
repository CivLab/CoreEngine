#include "stdafx.h"
#include "CppUnitTest.h"

#include "../../src/CoreCharacter/Character.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreCharacterTests
{		
	TEST_CLASS(isAlive_Test)
	{
	public:		
		TEST_METHOD(true_when_life_above_0)
		{
			Character myChar = Character("", 100);
			myChar.updateStatut();
			Assert::AreEqual(myChar.isAlive(), true);
		}

		TEST_METHOD(false_when_life_below_0)
		{
			Character myChar = Character("", -1);
			myChar.updateStatut();
			Assert::AreEqual(myChar.isAlive(), false);
		}

		TEST_METHOD(false_when_life_equals_0)
		{
			Character myChar = Character("", 0);
			myChar.updateStatut();
			Assert::AreEqual(myChar.isAlive(), false);
		}

	};

	TEST_CLASS(isHit_Test)
	{
	public:
		TEST_METHOD(returns_substract_and_alive_when_remain_above_0)
		{
			Character myChar = Character("", 100);
			myChar.isHit(10);
			Assert::AreEqual(myChar.getLife(), 90);
			Assert::AreEqual(myChar.isAlive(), true);
		}

		TEST_METHOD(returns_0_and_dead_when_remain_below_0)
		{
			Character myChar = Character("", 100);
			myChar.isHit(110);
			Assert::AreEqual(myChar.getLife(), 0);
			Assert::AreEqual(myChar.isAlive(), false);
		}

		TEST_METHOD(returns_0_and_dead_when_remain_equals_0)
		{
			Character myChar = Character("", 100);
			myChar.isHit(100);
			Assert::AreEqual(myChar.getLife(), 0);
			Assert::AreEqual(myChar.isAlive(), false);
		}

	};

	TEST_CLASS(isHealed_Test)
	{
	public:
		TEST_METHOD(returns_addition_when_below_max_life)
		{
			Character myChar = Character("", 100);
			myChar.isHit(30);
			myChar.isHealed(10);
			Assert::AreEqual(myChar.getLife(), 80);
		}

		TEST_METHOD(returns_max_life_when_above_max_life)
		{
			Character myChar = Character("", 100);
			myChar.isHit(10);
			myChar.isHealed(30);
			Assert::AreEqual(myChar.getLife(), myChar.getMaxLife());
		}

		TEST_METHOD(returns_max_life_when_equals_max_life)
		{
			Character myChar = Character("", 100);
			myChar.isHit(10);
			myChar.isHealed(10);
			Assert::AreEqual(myChar.getLife(), myChar.getMaxLife());
		}
	};
}