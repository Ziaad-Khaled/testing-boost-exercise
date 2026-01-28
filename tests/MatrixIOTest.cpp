#define BOOST_TEST_DYN_LINK

#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(OpenData)
{
  std::string filePath   = "../data/m3.csv";
  int         matrixSize = 3;

  MatrixXd expectedMatrix(3, 3);
  expectedMatrix << 0.680375, 0.59688, -0.329554, -0.211234, 0.823295,
      0.536459, 0.566198, -0.604897, -0.444451;

  MatrixXd actualMatrix = matrixIO::openData(filePath, matrixSize);

  BOOST_TEST((actualMatrix - expectedMatrix).norm() == 0.0);
}

BOOST_AUTO_TEST_SUITE_END()
