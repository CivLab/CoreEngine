#include "stdafx.h"
#include "CppUnitTest.h"

#include "../CoreGeometry/segment.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreGeometryTests
{		
	TEST_CLASS(lengthTest)
	{
	public:
		
		TEST_METHOD(length_calculation_OK)
		{
			Point A = Point(0, 0);
			Point B = Point(0, 1);
			Segment mySegment = Segment(A,B);

			Assert::AreEqual(mySegment.length(), 1.);
		}

		TEST_METHOD(length_calculation_when_length_zero)
		{
			Point A = Point(0, 0);
			Segment mySegment = Segment(A,A);

			Assert::AreEqual(mySegment.length(), 0.);
		}

	};

	TEST_CLASS(isOnSegmentTest)
	{
	public:

		TEST_METHOD(point_is_on_segment)
		{
			Point A = Point(0, 0);
			Point B = Point(0, 2);
			Point C = Point(0, 1);
			Segment mySegment = Segment(A, B);

			Assert::IsTrue(mySegment.isOnSegment(&C));
		}

		TEST_METHOD(point_is_outside_segment)
		{
			Point A = Point(0, 0);
			Point B = Point(0, 2);
			Point C = Point(1, 1);
			Segment mySegment = Segment(A, B);

			Assert::IsFalse(mySegment.isOnSegment(&C));
		}

	};
}