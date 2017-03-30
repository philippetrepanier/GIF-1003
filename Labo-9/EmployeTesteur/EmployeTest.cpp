#include "Employe.h"
#include <gtest/gtest.h>
using namespace labo10;
TEST(Employe, ConstructeurParDefault)
{
	Employe e("Pierre-Marc", "Levasseur");
	ASSERT_EQ(1, 1);
}
