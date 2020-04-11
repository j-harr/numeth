#include <catch.hpp>
#include <numeth/vector.hpp>
#include <memory>

namespace numeth {

	SCENARIO("Constructing a vector", "[vector]") {
		GIVEN("I want to create a vector") {
			std::unique_ptr<vector<int> > myVec;

			WHEN("I create a vector with size 3") {
				myVec = std::make_unique<vector<int> >(3);

				THEN("My vector has size 3") {
					REQUIRE(myVec->getSize() == 3);
				}
			}
			WHEN("I create a vector with size 0") {
				myVec = std::make_unique<vector<int> >(0);

				THEN("My vector has size 0") {
					REQUIRE(myVec->getSize() == 0);
				}
			}
		}
	}

	SCENARIO("I want to clear a vector", "[vector]") {
		GIVEN("I have a vector with data") {

			std::unique_ptr<vector<int> > myVec = std::make_unique<vector<int> >(3);
			myVec->at(0) = 1;
			myVec->at(1) = 2;
			myVec->at(2) = 3;

			REQUIRE(myVec->at(0) == 1);
			REQUIRE(myVec->at(1) == 2);
			REQUIRE(myVec->at(2) == 3);

			WHEN("I clear the vector") {
				myVec->clear();

				THEN("The vector has size 0") {
					REQUIRE(myVec->at(0) == 0);
					REQUIRE(myVec->at(1) == 0);
					REQUIRE(myVec->at(2) == 0);
				}
			}
		}
	}

	SCENARIO("Filling vector with data", "[vector]") {
		GIVEN("I have a vector with initial size") {

			std::unique_ptr<vector<int> > myVec = std::make_unique<vector<int> >(4);

			WHEN("I add data to the vector using 'at()'") {
				myVec->at(0) = 1;
				myVec->at(1) = 2;
				myVec->at(2) = 3;
				myVec->at(3) = 4;

				THEN("My vector contains proper data using 'at()'") {
					REQUIRE(myVec->at(0) == 1);
					REQUIRE(myVec->at(1) == 2);
					REQUIRE(myVec->at(2) == 3);
					REQUIRE(myVec->at(3) == 4);
				}
			}

			WHEN("I add data to the vector using '[]'") {
				myVec->clear();
				(*myVec)[0] = 5;
				(*myVec)[1] = 6;
				(*myVec)[2] = 7;
				(*myVec)[3] = 8;

				THEN("My vector contains the proper data using '[]'") {
					REQUIRE((*myVec)[0] == 5);
					REQUIRE((*myVec)[1] == 6);
					REQUIRE((*myVec)[2] == 7);
					REQUIRE((*myVec)[3] == 8);
				}
			}
		}
	}

	SCENARIO("+ operator overload", "[vector]") {
		GIVEN("Two vectors of same size") {
			numeth::vector<int> vecA(3);
			numeth::vector<int> vecB(3);
			for (int i = 0; i < 3; i++) {
				vecA[i] = i;
				vecB[i] = i;
			}

			WHEN("I add the two vectors") {

			}
		}
	}

}
