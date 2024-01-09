// Copyright (C) 2024 Programmers, All Rights Reserved
// Authors: Lim Jeong Hyeok

#include "geometry/point2d.hpp"
#include <limits>
#include <cmath>

#include "gtest/gtest.h"
#include <stdexcept>

constexpr uint32_t kTestCount = 10000U;

namespace programmers::geometry {
TEST(GeometryPoint2D, Constructor) {
  Point2D point1;
  Point2D point2(0.0, 1.0);
  Point2D point3(point2);
  Point2D point4(std::move(Point2D()));
}

TEST(GeometryPoint2D, AssignmentOperator) {
  Point2D point1;
  auto point2 = point1;
  auto point3 = std::move(Point2D());
}

TEST(GeometryPoint2D, CalculateDistance) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_FLOAT_EQ(std ::sqrt((kSourceX - kTargetX) * (kSourceX - kTargetX) +
                               (kSourceY - kTargetY) * (kSourceY - kTargetY)),
                    source.CalculateDistance(target));
  }
}

TEST(GeometryPoint2D, StaticCalculateDistance) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_FLOAT_EQ(std ::sqrt((kSourceX - kTargetX) * (kSourceX - kTargetX) +
                               (kSourceY - kTargetY) * (kSourceY - kTargetY)),
                    Point2D::CalculateDistance(source, target));
  }
}

TEST(GeometryPoint2D, GetX) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());

    Point2D source(kSourceX, 0);

    EXPECT_FLOAT_EQ(kSourceX, source.GetX());
  }
}

TEST(GeometryPoint2D, GetY) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceY = static_cast<double>(std::rand());

    Point2D source(0, kSourceY);

    EXPECT_FLOAT_EQ(kSourceY, source.GetY());
  }
}

TEST(GeometryPoint2D, SetX) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());

    Point2D source;

    source.SetX(kSourceX);

    EXPECT_FLOAT_EQ(kSourceX, source.GetX());
  }
}

TEST(GeometryPoint2D, SetY) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceY = static_cast<double>(std::rand());

    Point2D source;

    source.SetY(kSourceY);

    EXPECT_FLOAT_EQ(kSourceY, source.GetY());
  }
}

TEST(GeometryPoint2D, OperatorPlus) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D plusPoint;
    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    plusPoint = source + target;

    EXPECT_FLOAT_EQ(plusPoint.GetX(), kSourceX + kTargetX);
    EXPECT_FLOAT_EQ(plusPoint.GetY(), kSourceY + kTargetY);
  }
}

TEST(GeometryPoint2D, OperatorMinus) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D minusPoint;
    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    minusPoint = source - target;

    EXPECT_FLOAT_EQ(minusPoint.GetX(), kSourceX - kTargetX);
    EXPECT_FLOAT_EQ(minusPoint.GetY(), kSourceY - kTargetY);
  }
}

TEST(GeometryPoint2D, OperatorPluseEqual) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);
    source += target;

    EXPECT_FLOAT_EQ(source.GetX(), kSourceX + kTargetX);
    EXPECT_FLOAT_EQ(source.GetY(), kSourceY + kTargetY);
  }
}

TEST(GeometryPoint2D, OperatorMinusEqual) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    source -= target;

    EXPECT_FLOAT_EQ(source.GetX(), kSourceX - kTargetX);
    EXPECT_FLOAT_EQ(source.GetY(), kSourceY - kTargetY);
  }
}

TEST(GeometryPoint2D, OperatorMultiply) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kMutiple = static_cast<double>(std::rand());

    Point2D multipliedPoint;
    Point2D source(kSourceX, kSourceY);
    multipliedPoint = source * kMutiple;

    EXPECT_FLOAT_EQ(multipliedPoint.GetX(), kSourceX * kMutiple);
    EXPECT_FLOAT_EQ(multipliedPoint.GetY(), kSourceY * kMutiple);
  }
}

TEST(GeometryPoint2D, OperatorDivide) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kDivide = static_cast<double>(std::rand());

    Point2D DividedPoint;
    Point2D source(kSourceX, kSourceY);
    DividedPoint = source / kDivide;

    EXPECT_FLOAT_EQ(DividedPoint.GetX(), kSourceX / kDivide);
    EXPECT_FLOAT_EQ(DividedPoint.GetY(), kSourceY / kDivide);
  }
}

TEST(GeometryPoint2D, OperatorEqual) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_FLOAT_EQ(((kSourceX == kTargetX) & (kSourceY == kTargetY)),
                    source == target);
  }
}

TEST(GeometryPoint2D, OperatorNotEqual) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_FLOAT_EQ(((kSourceX != kTargetX) || (kSourceY != kTargetY)),
                    source != target);
  }
}

} // namespace programmers::geometry
