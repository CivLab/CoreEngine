#include "stdafx.h"
#include "CppUnitTest.h"
#include <functional>

#include "../CoreGeometry/point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreGeometryTests
{
	TEST_CLASS(point_normL2)
	{
	public:

		TEST_METHOD(point_norm_is_zero_for_0_0)
		{
			Point A = Point(0, 0);
			Assert::AreEqual((&A)->normL2(), 0.);
		}

		TEST_METHOD(point_norm_is_2_for_0_2)
		{
			Point A = Point(0, 2);
			Assert::AreEqual((&A)->normL2(), 2.);
		}

		TEST_METHOD(point_norm_is_2_for_2_0)
		{
			Point A = Point(2, 0);
			Assert::AreEqual((&A)->normL2(), 2.);
		}

		TEST_METHOD(point_norm_is_sqrt2_for_1_1)
		{
			Point A = Point(1, 1);
			Assert::AreEqual((&A)->normL2(), std::sqrt(2));
		}

	};

	TEST_CLASS(point_normalize)
	{
	public:

		TEST_METHOD(point_normalization_exception_for_0_0)
		{
			Point A = Point(0, 0);
			std::function<Point()> f1 = [&A] { return (&A)->normalize(); };			

			Assert::ExpectException<std::logic_error>(f1);
		}

		TEST_METHOD(point_normalization_for_1_0)
		{
			Point A(1, 0);

			Point calculated = (&A)->normalize();
			Point expected(1, 0);

			Assert::IsTrue(expected == calculated);
		}

		TEST_METHOD(point_normalization_for_3_0)
		{
			Point A(3, 0);

			Point calculated = (&A)->normalize();
			Point expected(1, 0);

			Assert::IsTrue(expected == calculated);
		}

		TEST_METHOD(point_normalization_for_3_4)
		{
			Point A(3., 4.);

			Point calculated = (&A)->normalize();
			Point expected(3./5., 4./5.);

			Assert::IsTrue(expected == calculated);
		}
	};

	TEST_CLASS(point_Operators)
	{
	public:

		TEST_METHOD(point_addition)
		{
			Point A = Point(1, 2);
			Point B = Point(3, 6);
			
			Point expected = Point(4, 8);
			Point calculated = A + B;

			Assert::AreEqual(expected.X, calculated.X);
			Assert::AreEqual(expected.Y, calculated.Y);
		}

		TEST_METHOD(point_soustraction)
		{
			Point A = Point(1, 2);
			Point B = Point(3, 6);

			Point expected = Point(2, 4);
			Point calculated = B - A ;

			Assert::AreEqual(expected.X, calculated.X);
			Assert::AreEqual(expected.Y, calculated.Y);
		}

		TEST_METHOD(point_equals)
		{
			Point A = Point(1, 2);
			Point B = Point(1, 2);
			Point C = Point(2, 2);

			Assert::IsTrue(A==B);
			Assert::IsFalse(A==C);
		}

		TEST_METHOD(point_multiply_real)
		{
			Point A(1, 2);
			double k = 3.0;
			Point calculated = A*k;
			Point expected(3.0, 6.0);

			Assert::IsTrue(calculated == expected);
		}

		TEST_METHOD(point_multiply_point)
		{
			Point A(1, 2);
			Point B = Point(3, 4);
			double calculated = A*B;
			double expected(11.);

			Assert::IsTrue(calculated == expected);
		}

	};
}